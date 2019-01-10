#include <gtest/gtest.h>

::testing::AssertionResult mojPredykat(int a, int b)
{
	if(a % b)
		return ::testing::AssertionSuccess();
	return ::testing::AssertionFailure() << "Tu jest moja wiadomosc!";
}

TEST(predykaty_asercji, drugi_przyklad)
{
	int a = 10;
	int b = 2;

	EXPECT_TRUE(mojPredykat(a, b));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
