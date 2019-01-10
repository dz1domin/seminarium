#include <gtest/gtest.h>
#include <iostream>

void moja_funkcja_ma_sie_crashowac(int* i)
{
	std::cerr << "Blad w lini " << __LINE__ << " moja_funkcja_ma_sie_crashowac()";
	exit(10);
}

TEST(inny_test_case, inny_test) 
{
	EXPECT_EQ(2, 2);
}

TEST(MyDeathTest, smierc) 
{
	ASSERT_DEATH({
    	int n = 5;
    	moja_funkcja_ma_sie_crashowac(&n);
		}, 
		"Blad w lini .* moja_funkcja_ma_sie_crashowac()");
}

TEST(inny_test_case, jeszcze_inny_test) 
{
	EXPECT_EQ(2, 2);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
