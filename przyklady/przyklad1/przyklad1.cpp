#include <gtest/gtest.h>

TEST(nazwa_serii_testow, nazwa_konkretnego_testu)
{
	/*
	kod testu - asercje, etc...
	*/
}

TEST(nazwa_serii_testow, nazwa_innego_konkretnego_testu)
{
	/*
	kod testu - asercje, etc...
	*/
}

TEST(add_test, add_test)
{
	ASSERT_EQ(2 + 2, 4);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
