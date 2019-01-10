#include <gtest/gtest.h>
 
bool przyjmijLiczbe(int licz)
{
	if(licz < 3)
		return true;
	return false;
}

class moja_fixtura : public testing::TestWithParam<int>
{

};
 
INSTANTIATE_TEST_CASE_P(moja_instancja, moja_fixtura, ::testing::Values(1, 2, 3));
 
TEST_P(moja_fixtura, sprawdzenie)
{
	int i = GetParam();

	if(i < 3)
		ASSERT_TRUE(przyjmijLiczbe(i));
	else
		ASSERT_FALSE(przyjmijLiczbe(i));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
