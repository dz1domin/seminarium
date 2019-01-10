#include <gtest/gtest.h>

void spr(int a)
{
	FAIL() << "Mozna strumieniowac jakies wiadomosci!\n";
}

TEST(przyklad3, wiecej_asercji)
{
	int a = 10;

	if(a)
		SUCCEED();

	if(a < 20)
		ADD_FAILURE();

	if(a != 20)
		ADD_FAILURE_AT("przyklad3.cpp", 14);

	spr(a);

	if(a == 10)
		SUCCEED();
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
