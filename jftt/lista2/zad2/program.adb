-- Program dodający dwie liczby w języku Ada
-- Autor: Twój pseudonim

with Ada.Text_IO;       -- Biblioteka obsługi wejścia i wyjścia
with Ada.Integer_Text_IO; -- Biblioteka do obsługi liczb całkowitych

procedure Dodawanie is
   -- Deklaracja zmiennych
   Liczba1, Liczba2, Suma : Integer;

begin
   -- Wyświetlenie komunikatu do użytkownika
   Ada.Text_IO.Put_Line("Program do dodawania dwóch liczb");

   -- Pobranie pierwszej liczby od użytkownika
   Ada.Text_IO.Put("Podaj pierwszą liczbę: ");
   Ada.Integer_Text_IO.Get(Liczba1);

   -- Pobranie drugiej liczby od użytkownika
   Ada.Text_IO.Put("Podaj drugą liczbę: ");
   Ada.Integer_Text_IO.Get(Liczba2);

   -- Obliczenie sumy liczb
   Suma := Liczba1 + Liczba2;

   -- Wyświetlenie wyniku
   Ada.Text_IO.Put("Suma liczb ");
   Ada.Integer_Text_IO.Put(Liczba1);
   Ada.Text_IO.Put(" i ");
   Ada.Integer_Text_IO.Put(Liczba2);
   Ada.Text_IO.Put(" wynosi: ");
   Ada.Integer_Text_IO.Put(Suma);
   Ada.Text_IO.New_Line; -- Przejście do nowej linii

end Dodawanie;