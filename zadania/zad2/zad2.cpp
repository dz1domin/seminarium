// Celem zadania jest napisanie mock-owej klasy dla klasy InterfejsFolderu i przeprowadzenie prostego testu wspoldzialania
// z klasą ObiektLiczacy. Dla tego zadania zakładamy, że w "folderze" mamy 3 pliki o nazwach:
// - jeden.dat (100B)
// - dwa.dat	(150B)
// - trzy.dat	(50B)
// Obietk klasy ObiektLiczacy wywołuje metodę liczbaPlikow i nazwyPlikow dokładnie raz, natomiast rozmiarPliku dla każdego
// oddzielnie dostając napisane u góry rozmiary. Dokładnie w takiej kolejności.
// Dodatkowo nalezy napisac implementację metody rysujWykres klasy ObiektLiczacy, która zwraca mapę o kluczu jako nazwa pliku
// oraz wartości rzeczywistej będącej udziałem danego pliku w wielkości folderu oraz wypisuje te mapę na standardowe wyjście. 

#include "klasy.h"

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}

/*
Wynik:

[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from zad2
[ RUN      ] zad2.pierwszy
dwa.dat 0.5
jeden.dat 0.333333
trzy.dat 0.166667
[       OK ] zad2.pierwszy (2 ms)
[----------] 1 test from zad2 (9 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (17 ms total)
[  PASSED  ] 1 test.

*/