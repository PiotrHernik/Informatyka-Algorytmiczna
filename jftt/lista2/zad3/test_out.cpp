#include <iostream>
#include <string>

using namespace std;

/* 
   Program demonstruje różne rodzaje komentarzy w C++.
   Zawiera komentarze jednolinijkowe, blokowe oraz dokumentacyjne.
*/

/** */
/**
 
*/

/**
 * Funkcja dodająca dwie liczby całkowite.
 * @param a Pierwsza liczba
 * @param b Druga liczba
 * @return Suma dwóch liczb
 */
int dodaj(int a, int b) {
    return a + b;
}
" "
std::string test = "taki sobie komentarz // i coś jeszcze //* fgfg */";

/*! 
 * Funkcja odejmująca dwie liczby całkowite.
 * @param a Minuend (odjemnik)
 * @param b Subtrahend (odejmowana)
 * @return Wynik odejmowania
 */
int odejmij(int a, int b) {
    return a - b;
}

int globalna_zmienna = 100;

bool jest_aktywna = true;

int main() {
    int wynik_dodawania = dodaj(5, 10); 

    int wynik_odejmowania = odejmij(20, 5); 

    cout << "Wynik dodawania: " << wynik_dodawania << endl; /* Wyświetla 15 */
    cout << "Wynik odejmowania: " << wynik_odejmowania << endl; 

    return 0;
}