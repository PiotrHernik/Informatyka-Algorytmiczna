with Ada.Text_IO; use Ada.Text_IO;
with Ada.Numerics.Float_Random; use Ada.Numerics.Float_Random;
with Random_Seeds; use Random_Seeds;
with Ada.Real_Time; use Ada.Real_Time;

procedure  zad4 is


-- Travelers moving on the board

  Nr_Of_Travelers : constant Integer := 15;

  Min_Steps : constant Integer := 1 ;
  Max_Steps : constant Integer := 10 ;

  Min_Delay : constant Duration := 0.01;
  Max_Delay : constant Duration := 0.05;

-- 2D Board with torus topology

  Board_Width  : constant Integer := 15;
  Board_Height : constant Integer := 15;

-- Timing

  Start_Time : Time := Clock;  -- global startnig time

-- Random seeds for the tasks' random number generators
 
  Seeds : Seed_Array_Type(1..Nr_Of_Travelers) := Make_Seeds(Nr_Of_Travelers);

-- Types, procedures and functions

  -- Postitions on the board
  type Position_Type is record	
    X: Integer range 0 .. Board_Width - 1; 
    Y: Integer range 0 .. Board_Height - 1; 
  end record;	   

  -- elementary steps
  procedure Move_Down( Position: in out Position_Type ) is
  begin
    Position.Y := ( Position.Y + 1 ) mod Board_Height;
  end Move_Down;

  procedure Move_Up( Position: in out Position_Type ) is
  begin
    Position.Y := ( Position.Y + Board_Height - 1 ) mod Board_Height;
  end Move_Up;

  procedure Move_Right( Position: in out Position_Type ) is
  begin
    Position.X := ( Position.X + 1 ) mod Board_Width;
  end Move_Right;

  procedure Move_Left( Position: in out Position_Type ) is
  begin
    Position.X := ( Position.X + Board_Width - 1 ) mod Board_Width;
  end Move_Left;

   protected Task_Counter is
      procedure Task_Done; -- Zwiększa licznik zakończonych zadań
      entry Wait_For_Completion; -- Blokuje, aż wszystkie zadania się zakończą
   private
      Done_Count : Integer := 0; -- Licznik zakończonych zadań
   end Task_Counter;

   protected body Task_Counter is
      procedure Task_Done is
      begin
         Done_Count := Done_Count + 1;
      end Task_Done;

      entry Wait_For_Completion when Done_Count = Nr_Of_Travelers is
      begin
         null; -- Zwolnienie blokady, gdy wszystkie zadania są zakończone
      end Wait_For_Completion;
   end Task_Counter;

   protected type Field_Protection is
      entry Enter(Id: Integer);
      procedure Leave;
   private
      Occupied: Boolean := False;                       
      Occupant_Id: Integer := -1;     
   end Field_Protection;

   protected body Field_Protection is
      entry Enter(Id: Integer) when not Occupied is
      begin
         Occupied := True;               
         Occupant_Id := Id;               
      end Enter;

      procedure Leave is
      begin
         Occupied := False;             
         Occupant_Id := -1;         
      end Leave;
   end Field_Protection;

   type Field_Array is array (0 .. Board_Width - 1, 0 .. Board_Height - 1) of Field_Protection;
   Fields : Field_Array;


  -- traces of travelers
  type Trace_Type is record 	      
    Time_Stamp:  Duration;	      
    Id : Integer;
    Position: Position_Type;      
    Symbol: Character;	      
  end record;	      

  type Trace_Array_type is  array(0 .. Max_Steps) of Trace_Type;

  type Traces_Sequence_Type is record
    Last: Integer := -1;
    Trace_Array: Trace_Array_type ;
  end record; 


  procedure Print_Trace( Trace : Trace_Type ) is
    Symbol : String := ( ' ', Trace.Symbol );
  begin
    Put_Line(
        Duration'Image( Trace.Time_Stamp ) & " " &
        Integer'Image( Trace.Id ) & " " &
        Integer'Image( Trace.Position.X ) & " " &
        Integer'Image( Trace.Position.Y ) & " " &
        ( ' ', Trace.Symbol ) -- print as string to avoid: '
      );
  end Print_Trace;

  procedure Print_Traces( Traces : Traces_Sequence_Type ) is
  begin
    for I in 0 .. Traces.Last loop
      Print_Trace( Traces.Trace_Array( I ) );
    end loop;
  end Print_Traces;

  -- task Printer collects and prints reports of traces
  task Printer is
    entry Report( Traces : Traces_Sequence_Type );
  end Printer;
  
  task body Printer is 
  begin
      loop
         select
            accept Report(Traces : Traces_Sequence_Type) do
               Print_Traces(Traces);
            end Report;
         or
            terminate;
         end select;
      end loop;
  end Printer;


  -- travelers
  type Traveler_Type is record
    Id: Integer;
    Symbol: Character;
    Position: Position_Type;    
  end record;


   task type Traveler_Task_Type is	
      entry Init(Id: Integer; Seed: Integer; Symbol: Character);
      entry Start;
   end Traveler_Task_Type;	

   task body Traveler_Task_Type is
      G : Generator;
      Traveler : Traveler_Type;
      Time_Stamp : Duration;
      Nr_of_Steps: Integer;
      Traces: Traces_Sequence_Type; 
      Should_Terminate : Boolean := False;
      Direction : Integer;

      procedure Store_Trace is
      begin  
         Traces.Last := Traces.Last + 1;
         Traces.Trace_Array( Traces.Last ) := ( 
            Time_Stamp => Time_Stamp,
            Id => Traveler.Id,
            Position => Traveler.Position,
            Symbol => Traveler.Symbol
         );
      end Store_Trace;
      
      procedure Make_Step is
         New_Position : Position_Type := Traveler.Position;

      begin
         case Direction is
            when 0 =>
               Move_Up( New_Position );
            when 1 =>
               Move_Down( New_Position );
            when 2 =>
               Move_Left( New_Position );
            when 3 =>
               Move_Right( New_Position );
            when others =>
               Put_Line( " ?????????????? " & Integer'Image( Direction ) );
         end case;

         select
            Fields(New_Position.X, New_Position.Y).Enter(Traveler.Id);
            Fields(Traveler.Position.X, Traveler.Position.Y).Leave;
            Traveler.Position := New_Position;
         or
            delay 5.0 * Max_Delay;
            Traveler.Symbol := Character'Val(Character'Pos(Traveler.Symbol) + 32);
            Should_Terminate := True;
         end select;

      end Make_Step;

      begin
      accept Init(Id: Integer; Seed: Integer; Symbol: Character) do
         Reset(G, Seed);
         Traveler.Id := Id;
         Traveler.Symbol := Symbol;
         
         Traveler.Position := (
            X => Id,
            Y => Id     
         );
         
         Fields(Traveler.Position.X, Traveler.Position.Y).Enter(Traveler.Id);

         if Id mod(2) = 0 then
            Direction := Integer( Float'Floor(2.0 * Random(G)) );
         else 
            Direction := 2 + Integer( Float'Floor(2.0 * Random(G)) );
         end if;

         Store_Trace;
         Nr_of_Steps := Min_Steps + Integer( Float(Max_Steps - Min_Steps) * Random(G));

         Time_Stamp := To_Duration ( Clock - Start_Time ); -- reads global clock
      end Init;
      
      accept Start do
         null;
      end Start;

      for Step in 1 .. Nr_of_Steps loop

         exit when Should_Terminate;
         delay Min_Delay+(Max_Delay-Min_Delay)*Duration(Random(G));

         Make_Step;

         Store_Trace;
         Time_Stamp := To_Duration ( Clock - Start_Time ); -- reads global clock

      end loop;
      Fields(Traveler.Position.X, Traveler.Position.Y).Leave;
      Printer.Report( Traces );

      Task_Counter.Task_Done;
   end Traveler_Task_Type;


-- local for main task

   Travel_Tasks: array (0 .. Nr_Of_Travelers-1) of Traveler_Task_Type; -- for tests
   Symbol : Character := 'A';
   begin 
  
   -- Prit the line with the parameters needed for display script:
   Put_Line(
      "-1 "&
      Integer'Image( Nr_Of_Travelers ) &" "&
      Integer'Image( Board_Width ) &" "&
      Integer'Image( Board_Height )      
   );


   -- init tarvelers tasks
   for I in Travel_Tasks'Range loop
      Travel_Tasks(I).Init( I, Seeds(I+1), Symbol );
      Symbol := Character'Succ( Symbol );
   end loop;

   -- start tarvelers tasks
   for I in Travel_Tasks'Range loop
      Travel_Tasks(I).Start;
   end loop;

   Task_Counter.Wait_For_Completion;

end zad4;

