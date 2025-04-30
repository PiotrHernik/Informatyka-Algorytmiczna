with Ada.Text_IO; use Ada.Text_IO;
with Ada.Numerics.Float_Random; use Ada.Numerics.Float_Random;
with Random_Seeds; use Random_Seeds;
with Ada.Real_Time; use Ada.Real_Time;

procedure zad1 is

   Nr_Of_Travelers : constant Integer := 15;
   Nr_Of_Wild_Tenants : constant Integer := 10; -- Nowa stała określająca liczbę dzikich lokatorów

   Min_Steps : constant Integer := 10;
   Max_Steps : constant Integer := 100;

   Min_Delay : constant Duration := 0.01;
   Max_Delay : constant Duration := 0.05;

   Board_Width  : constant Integer := 15;
   Board_Height : constant Integer := 15;

   Start_Time : Time := Clock;

   Seeds : Seed_Array_Type(1..Nr_Of_Travelers + Nr_Of_Wild_Tenants) := Make_Seeds(Nr_Of_Travelers + Nr_Of_Wild_Tenants);

   type Position_Type is record	
      X: Integer range 0 .. Board_Width - 1; 
      Y: Integer range 0 .. Board_Height - 1; 
   end record;	   

   procedure Move_Down(Position: in out Position_Type) is
   begin
      Position.Y := (Position.Y + 1) mod Board_Height;
   end Move_Down;

   procedure Move_Up(Position: in out Position_Type) is
   begin
      Position.Y := (Position.Y + Board_Height - 1) mod Board_Height;
   end Move_Up;

   procedure Move_Right(Position: in out Position_Type) is
   begin
      Position.X := (Position.X + 1) mod Board_Width;
   end Move_Right;

   procedure Move_Left(Position: in out Position_Type) is
   begin
      Position.X := (Position.X + Board_Width - 1) mod Board_Width;
   end Move_Left;

   -- Typ dla dzikich lokatorów
   type Wild_Tenant_Type is record
      Id: Integer;
      Symbol: Character;
      Position: Position_Type;
      Life_Time: Duration;
   end record;

   -- Typ chroniony dla pola z obsługą dzikich lokatorów
   protected type Field_Protection is
      entry Enter(Id: Integer; Is_Wild: Boolean);
      procedure Leave(Id: Integer; Is_Wild: Boolean);
      entry Move_Wild_Tenant(From_X, From_Y: Integer; Success: out Boolean);
      function Is_Occupied return Boolean;
      function Get_Occupant_Id return Integer;
      function Is_Occupant_Wild return Boolean;
   private
      Occupied: Boolean := False;                       
      Occupant_Id: Integer := -1;
      Is_Wild_Tenant: Boolean := False;
   end Field_Protection;

   protected body Field_Protection is
      entry Enter(Id: Integer; Is_Wild: Boolean) when not Occupied is
      begin
         Occupied := True;               
         Occupant_Id := Id;
         Is_Wild_Tenant := Is_Wild;
      end Enter;

      procedure Leave(Id: Integer; Is_Wild: Boolean) is
      begin
         if Occupant_Id = Id and Is_Wild_Tenant = Is_Wild then
            Occupied := False;             
            Occupant_Id := -1;
            Is_Wild_Tenant := False;
         end if;
      end Leave;

      entry Move_Wild_Tenant(From_X, From_Y: Integer; Success: out Boolean) when Occupied and Is_Wild_Tenant is
         New_X, New_Y: Integer;
         Found: Boolean := False;
      begin
         Success := False;
         -- Sprawdź sąsiednie pola (góra, dół, lewo, prawo)
         for Dir in 0..3 loop
            New_X := Occupant_Position.X;
            New_Y := Occupant_Position.Y;
            
            case Dir is
               when 0 => Move_Up(New_Position);
               when 1 => Move_Down(New_Position);
               when 2 => Move_Left(New_Position);
               when 3 => Move_Right(New_Position);
               when others => null;
            end case;
            
            -- Sprawdź czy nowa pozycja jest różna od From_X, From_Y i wolna
            if (New_X /= From_X or New_Y /= From_Y) and then not Fields(New_X, New_Y).Is_Occupied then
               Fields(New_X, New_Y).Enter(Occupant_Id, True);
               Occupied := False;
               Occupant_Id := -1;
               Is_Wild_Tenant := False;
               Success := True;
               exit;
            end if;
         end loop;
      end Move_Wild_Tenant;

      function Is_Occupied return Boolean is
      begin
         return Occupied;
      end Is_Occupied;

      function Get_Occupant_Id return Integer is
      begin
         return Occupant_Id;
      end Get_Occupant_Id;

      function Is_Occupant_Wild return Boolean is
      begin
         return Is_Wild_Tenant;
      end Is_Occupant_Wild;
   end Field_Protection;

   type Field_Array is array (0 .. Board_Width - 1, 0 .. Board_Height - 1) of Field_Protection;
   Fields : Field_Array;

   type Trace_Type is record 	      
      Time_Stamp:  Duration;	      
      Id : Integer;
      Position: Position_Type;      
      Symbol: Character;	      
   end record;	      

   type Trace_Array_type is array(0 .. Max_Steps) of Trace_Type;

   type Traces_Sequence_Type is record
      Last: Integer := -1;
      Trace_Array: Trace_Array_type;
   end record; 

   procedure Print_Trace(Trace : Trace_Type) is
   begin
      Put_Line(
         Duration'Image(Trace.Time_Stamp) & " " &
         Integer'Image(Trace.Id) & " " &
         Integer'Image(Trace.Position.X) & " " &
         Integer'Image(Trace.Position.Y) & " " &
         (1 => Trace.Symbol)
      );
   end Print_Trace;

   procedure Print_Traces(Traces : Traces_Sequence_Type) is
   begin
      for I in 0 .. Traces.Last loop
         Print_Trace(Traces.Trace_Array(I));
      end loop;
   end Print_Traces;

   task Printer is
      entry Report(Traces : Traces_Sequence_Type);
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

   type Traveler_Type is record
      Id: Integer;
      Symbol: Character;
      Position: Position_Type;    
   end record;

   task type Wild_Tenant_Task_Type is
      entry Init(Id: Integer; Seed: Integer);
      entry Start;
   end Wild_Tenant_Task_Type;

   task body Wild_Tenant_Task_Type is
      G : Generator;
      Tenant : Wild_Tenant_Type;
      Time_Stamp : Duration;
      Traces: Traces_Sequence_Type;
      Life_Time: Duration;

      procedure Store_Trace is
      begin  
         Traces.Last := Traces.Last + 1;
         Traces.Trace_Array(Traces.Last) := ( 
            Time_Stamp => Time_Stamp,
            Id => Tenant.Id,
            Position => Tenant.Position,
            Symbol => Tenant.Symbol
         );
      end Store_Trace;

   begin
      accept Init(Id: Integer; Seed: Integer) do
         Reset(G, Seed);
         Tenant.Id := Id;
         Tenant.Symbol := Character'Val(Character'Pos('0') + (Id mod 10));
         Life_Time := Min_Delay + (Max_Delay * 5.0 - Min_Delay) * Duration(Random(G));
         
         loop
            Tenant.Position := (
               X => Integer(Float'Floor(Float(Board_Width) * Random(G))),
               Y => Integer(Float'Floor(Float(Board_Height) * Random(G)))
            );
            
            select
               Fields(Tenant.Position.X, Tenant.Position.Y).Enter(Tenant.Id, True);
               exit;
            else
               null;
            end select;
         end loop;
         
         Time_Stamp := To_Duration(Clock - Start_Time);
         Store_Trace;
      end Init;
      
      accept Start do
         null;
      end Start;
      
      delay Life_Time;
      
      Fields(Tenant.Position.X, Tenant.Position.Y).Leave(Tenant.Id, True);
      Time_Stamp := To_Duration(Clock - Start_Time);
      Store_Trace;
      
      Printer.Report(Traces);
   end Wild_Tenant_Task_Type;

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

      procedure Store_Trace is
      begin  
         Traces.Last := Traces.Last + 1;
         Traces.Trace_Array(Traces.Last) := ( 
            Time_Stamp => Time_Stamp,
            Id => Traveler.Id,
            Position => Traveler.Position,
            Symbol => Traveler.Symbol
         );
      end Store_Trace;
   
      procedure Make_Step is
         N : Integer;
         New_Position : Position_Type := Traveler.Position;
         Moved: Boolean := False;
      begin
         N := Integer(Float'Floor(4.0 * Random(G)));    
         case N is
            when 0 =>
               Move_Up(New_Position);
            when 1 =>
               Move_Down(New_Position);
            when 2 =>
               Move_Left(New_Position);
            when 3 =>
               Move_Right(New_Position);
            when others =>
               Put_Line(" ?????????????? " & Integer'Image(N));
         end case;

         -- Próba przejścia na nowe pole
         select
            Fields(New_Position.X, New_Position.Y).Enter(Traveler.Id, False);
            Fields(Traveler.Position.X, Traveler.Position.Y).Leave(Traveler.Id, False);
            Traveler.Position := New_Position;
            Moved := True;
         else
            -- Sprawdź czy pole jest zajęte przez dzikiego lokatora
            if Fields(New_Position.X, New_Position.Y).Is_Occupied and then 
               Fields(New_Position.X, New_Position.Y).Is_Occupant_Wild then
               
               declare
                  Success: Boolean;
               begin
                  Fields(New_Position.X, New_Position.Y).Move_Wild_Tenant(
                     Traveler.Position.X, Traveler.Position.Y, Success);
                  
                  if Success then
                     Fields(New_Position.X, New_Position.Y).Enter(Traveler.Id, False);
                     Fields(Traveler.Position.X, Traveler.Position.Y).Leave(Traveler.Id, False);
                     Traveler.Position := New_Position;
                     Moved := True;
                  end if;
               end;
            end if;
         end select;

         if not Moved then
            Traveler.Symbol := Character'Val(Character'Pos(Traveler.Symbol) + 32);
            Should_Terminate := True;
         end if;
      end Make_Step;

   begin
      accept Init(Id: Integer; Seed: Integer; Symbol: Character) do
         Reset(G, Seed); 
         Traveler.Id := Id;
         Traveler.Symbol := Symbol;
         
         loop
            Traveler.Position := (
               X => Integer(Float'Floor(Float(Board_Width) * Random(G))),
               Y => Integer(Float'Floor(Float(Board_Height) * Random(G)))          
            );
         
            select
               Fields(Traveler.Position.X, Traveler.Position.Y).Enter(Traveler.Id, False);
               exit; 
            else
               null;
            end select;
         end loop;

         Store_Trace; 

         Nr_of_Steps := Min_Steps + Integer(Float(Max_Steps - Min_Steps) * Random(G));
         Time_Stamp := To_Duration(Clock - Start_Time);
      end Init;
      
      accept Start do
         null;
      end Start;

      for Step in 1 .. Nr_of_Steps loop
         exit when Should_Terminate;
         delay Min_Delay + (Max_Delay - Min_Delay) * Duration(Random(G));
         Make_Step;

         Store_Trace;
         Time_Stamp := To_Duration(Clock - Start_Time);
      end loop;
      
      Fields(Traveler.Position.X, Traveler.Position.Y).Leave(Traveler.Id, False);
      Printer.Report(Traces);
   end Traveler_Task_Type;

   Travel_Tasks: array (0 .. Nr_Of_Travelers-1) of Traveler_Task_Type;
   Wild_Tenant_Tasks: array (0 .. Nr_Of_Wild_Tenants-1) of Wild_Tenant_Task_Type;
   Symbol : Character := 'A';
   Digit : Integer := 0;
begin 
   Put_Line(
         "-1 "&
         Integer'Image(Nr_Of_Travelers + Nr_Of_Wild_Tenants) &" "&
         Integer'Image(Board_Width) &" "&
         Integer'Image(Board_Height)      
      );

   -- Inicjalizacja podróżników
   for I in Travel_Tasks'Range loop
      Travel_Tasks(I).Init(I, Seeds(I+1), Symbol);
      Symbol := Character'Succ(Symbol);
   end loop;

   -- Inicjalizacja dzikich lokatorów
   for I in Wild_Tenant_Tasks'Range loop
      Wild_Tenant_Tasks(I).Init(Nr_Of_Travelers + I, Seeds(Nr_Of_Travelers + I + 1));
   end loop;

   -- Start wszystkich zadań
   for I in Travel_Tasks'Range loop
      Travel_Tasks(I).Start;
   end loop;
   
   for I in Wild_Tenant_Tasks'Range loop
      Wild_Tenant_Tasks(I).Start;
   end loop;
end zad1;