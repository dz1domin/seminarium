#include <gtest/gtest.h>

::testing::AssertionResult mojPredykat(const char* wyr1, const char* wyr2, int a, int b)
{
	if(a % b)
		return ::testing::AssertionSuccess();
	return ::testing::AssertionFailure() << "Tu jest moja wiadomosc!\n" << wyr1 << " wynosilo " << a << "\n" << wyr2 << 
	" wynosilo " << b << "\n";
}

TEST(predykaty_asercji, drugi_przyklad)
{
	int a = 10;
	int b = 2;
	int c = 12;

	EXPECT_PRED_FORMAT2(mojPredykat, a, b);
	EXPECT_PRED_FORMAT2(mojPredykat, c, b);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
