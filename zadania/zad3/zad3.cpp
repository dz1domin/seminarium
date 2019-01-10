// Celem zadania jest napisanie 2 benchmark-ów(funkcji) w celu porównania wydajności wstawiania na początek kontenera.
// W tym celu jeden benchmark ma być napisany dla std::vector i ma w nim być użyta metoda insert.
// Natomiast dla drugiego benchmarka należy napisać linked list-ę ze zdefiniowaną metodą push_front().
// W zadaniu tym można skorzystać jedynie z std::vector. Typ elementów przechowywanych w tych kontenerach to int, aczkolwiek
// w celach rozrywkowych można użyć innych(co znaczy że lista ma być szablonowa). Obydwa testy należy uruchomić dla 1e5 iteracji. 

#include "lista.h"

BENCHMARK_MAIN();

/*
Przykładowe wyniki:
2019-01-09 22:04:27
Running ./zad3
Run on (8 X 2601 MHz CPU s)
Load Average: 0.52, 0.58, 0.59
-------------------------------------------------------------------------
Benchmark                              Time             CPU   Iterations
-------------------------------------------------------------------------
BM_funkcja1/iterations:100000       5584 ns         5625 ns       100000
BM_funkcja2/iterations:100000        159 ns          156 ns       100000

*/