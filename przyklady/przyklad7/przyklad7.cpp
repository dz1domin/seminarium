#include "gmock/gmock.h"

TEST(matchery, prosty_matcher)
{
	EXPECT_THAT("Do widzenia", ::testing::EndsWith("nia"));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
