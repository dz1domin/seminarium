#include <gtest/gtest.h>

int super_funkcja_do_testowania(int k)
{
	if(k < 5)
		return k;
	return -1;
}

TEST(test_scoped_trace, przyklad10)
{
	{
		SCOPED_TRACE("pierwsza seria");
		EXPECT_EQ(1, super_funkcja_do_testowania(1));
		EXPECT_EQ(2, super_funkcja_do_testowania(2));
	}

	{
		SCOPED_TRACE("druga seria");
		EXPECT_EQ(1, super_funkcja_do_testowania(1));
		EXPECT_EQ(6, super_funkcja_do_testowania(6));
	}
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
