#include <gtest/gtest.h>

bool mojPredykat(int a, int b)
{
	return a % b;
}

TEST(predykaty_asercji, pierwszy_przyklad)
{
	int a = 10;
	int b = 2;

	EXPECT_PRED2(mojPredykat, a, b);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
