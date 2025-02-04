Program ten jest kompilatorem prostego języka imperatywnego do kodu maszyny wirtualnej. W celu dokonania kompilacji programu należy użyć procedury "make".
Wywołanie programu jest zgodne ze specyfikacją. 
Program został podzielony na kilka folderów.
W folderze main znajduje się lexer, parser oraz główna funkcja programu.
W folderze ast znajduje się struktura drzewa ast, a także wszelkie związane z nim funkcjonalności. To w tym folderze znajdują się metody odpowiedzialne za wykonywanie poszczególnych komend "executeCommand".\
W folderze astUtilities znajdują sie funckje odpowiadające za tworzenie drzewa ast. Wywoływane są one w parserze.
W folderze SymbolTable znajduje się klasa odgrywająca rolę tablicy symboli.
W folderze ErrorClass znajduje się klasa odpowiedzialan za zgłaszane błędu.
W folderze functions, znajdują się funckje, które pomagają w przygotowaniu zmiennych do dalszych działań w aseblerze, albo sprawdzają czy zmienna jest poprawna. Znajdują się tam również algorytmy mnożenia i dzielenia.