#include <gtest/gtest.h>
#include <utility>
#include <iostream>

class moja_klasa
{
public:
	// friend void PrintTo(const moja_klasa& m_k, std::ostream* o)
	// {
	// 	*o << "\nA ta funkcja będzie faktycznie uzyta\n";
	// }

	friend std::ostream& operator<<(std::ostream& o, const moja_klasa& m_k)
	{
		std::cout << "\nJakas wazna informacja\n" << std::endl;
		return o;
	}

	int war = 11;
};

bool czy_10(const moja_klasa& m_k)
{
	return m_k.war == 10;
}

TEST(printer, printer_test)
{
	moja_klasa m_k;

	EXPECT_TRUE(czy_10(m_k)) << ::testing::PrintToString(m_k);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
