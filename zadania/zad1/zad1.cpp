// Celem zadania jest napisanie klasy super_kontener - można użyć kontenerów STL-owych.
// Klasa super_kontener na pewno musi posiadać std::map(odziedziczone lub jako składnik) oraz listę.
// Potrzebne funkcje oraz ich działanie można wydedukować na podstawie testów.
// Kod ma się kompilować oraz dawać wyniki podane na dole tego pliku.
// PLIKU zad1.cpp NIE WOLNO MODYFIKOWAĆ poza wyznaczonym miejscem.

#include "super_kontener.h"

class zad1_fixture : public ::testing::Test
{
protected:
	void SetUp()
	{
		// Tu wpisz odpowiedni kod.
	}

	super_kontener<int, int> s;
};

TEST_F(zad1_fixture, pierwszy)
{
	static int i;
	for(auto& it : s)
	{
		EXPECT_EQ(++i, it.first);
		EXPECT_EQ(i, it.second);
	}

	ASSERT_EQ(s.size(), 3);
}

TEST_F(zad1_fixture, drugi)
{
	ASSERT_EQ(s.try_emplace(3, 3).second, false);
}

TEST_F(zad1_fixture, trzeci)
{
	s.insert(std::pair<int, int>(4, 4));
}

TEST_F(zad1_fixture, czwarty)
{
	s.toTheQ(1).toTheQ(2).toTheQ(3);

	int val = s.popFromTheQ();
	ASSERT_EQ(s.Qsize(), 2);
	ASSERT_EQ(val, 1);
}

void dodatkowaFunkcja(const super_kontener<int, int>& s)
{
	FAIL() << ::testing::PrintToString(s);
}

TEST_F(zad1_fixture, piaty)
{
	std::cout << s << std::endl;

	dodatkowaFunkcja(s);
}

TEST(super_kontenerDeathTest, ostatni)
{
	super_kontener<double, int> s;
	
	ASSERT_DEATH(s.sudoku(), "Kazano mi ;_;.");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

/*
Wynik:

[==========] Running 6 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from super_kontenerDeathTest
[ RUN      ] super_kontenerDeathTest.ostatni
[       OK ] super_kontenerDeathTest.ostatni (12 ms)
[----------] 1 test from super_kontenerDeathTest (13 ms total)

[----------] 5 tests from zad1_fixture
[ RUN      ] zad1_fixture.pierwszy
[       OK ] zad1_fixture.pierwszy (0 ms)
[ RUN      ] zad1_fixture.drugi
[       OK ] zad1_fixture.drugi (0 ms)
[ RUN      ] zad1_fixture.trzeci
super_kontener.h -> tu jest numerek jaki chce:420: Failure
Failed
Ten kontener ma nie przyjmowac wiecej niz 3 pary.
[  FAILED  ] zad1_fixture.trzeci (2 ms)
[ RUN      ] zad1_fixture.czwarty
[       OK ] zad1_fixture.czwarty (0 ms)
[ RUN      ] zad1_fixture.piaty
Tu jest mapa
1, 1; 2, 2; 3, 3;

/mnt/c/Users/MSI/Desktop/seminarium/zadania_rozwiazane/zad1/zad1.cpp:49: Failure
Failed
Ha?! A skad to pisza? ... :O

[  FAILED  ] zad1_fixture.piaty (12 ms)
[----------] 5 tests from zad1_fixture (26 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 2 test cases ran. (48 ms total)
[  PASSED  ] 4 tests.
[  FAILED  ] 2 tests, listed below:
[  FAILED  ] zad1_fixture.trzeci
[  FAILED  ] zad1_fixture.piaty

 2 FAILED TESTS

*/