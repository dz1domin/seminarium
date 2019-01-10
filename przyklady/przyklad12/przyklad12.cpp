#include <gtest/gtest.h>

void super_funkcja()
{
	ASSERT_EQ(1, 2);
}

TEST(test_propagacji, przyklad11)
{
	super_funkcja();

	if(HasFatalFailure())
		return;

	int* i = new int();
	delete i;
	delete i;
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
