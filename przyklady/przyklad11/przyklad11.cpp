#include <gtest/gtest.h>

void super_funkcja(int* i)
{
	ASSERT_EQ(1, 2);
	i = new int();
}

TEST(test_propagacji, przyklad11)
{
	int* i = nullptr;
	
	super_funkcja(i);

	*i = 10;
	delete i;
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
