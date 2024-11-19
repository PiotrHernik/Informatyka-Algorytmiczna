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

//! Zmienna globalna używana do przechowywania wartości całkowitej
int globalna_zmienna = 100;

/// Zmienna globalna przechowująca wartość logiczną
bool jest_aktywna = true;

int main() {
    // Przykład użycia funkcji dodaj
    int wynik_dodawania = dodaj(5, 10); // Dodawanie 5 i 10

    // Przykład użycia funkcji odejmij
    int wynik_odejmowania = odejmij(20, 5); // Odejmowanie 5 od 20

    // Wyświetlenie wyników
    cout << "Wynik dodawania: " << wynik_dodawania << endl; /* Wyświetla 15 */
    cout << "Wynik odejmowania: " << wynik_odejmowania << endl; // Wyświetla 15

    return 0;
}