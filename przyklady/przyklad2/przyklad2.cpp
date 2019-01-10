#include <gtest/gtest.h>
#include <iostream>

class test_struktury : public ::testing::Test
{
public:
	test_struktury()
	{
		std::cout << "Konstruktor struktury" << std::endl;
		b = 20;
	}

protected:
	void SetUp() override
	{
		a = 10;
	}

	int a, b, c;
};

TEST_F(test_struktury, pierwszy_test)
{
	ASSERT_EQ(a, 10);
}

TEST_F(test_struktury, drgi_test)
{
	EXPECT_EQ(b, 10);
	ASSERT_EQ(c, 10);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
