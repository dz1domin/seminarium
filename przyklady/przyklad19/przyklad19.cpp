#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;

int funkcja_zwracajaca_10()
{
	return 10;
}

class interfejs
{
public:
	virtual int funkcja_zwracajaca_10() = 0;
};

class mockowy_interfejs : public interfejs
{
public:
	MOCK_METHOD0(funkcja_zwracajaca_10, int());
};

class piatka
{
public:
	const int daj() { return 5; }
};

class piatka_mock
{
public:
	MOCK_CONST_METHOD0(daj, const int());
};

TEST(mocki, czesc_druga)
{
	piatka_mock p;
	mockowy_interfejs i;
	EXPECT_CALL(p, daj()).WillOnce(Return(5));
	EXPECT_CALL(i, funkcja_zwracajaca_10()).WillOnce(Return(10));

	EXPECT_EQ(p.daj(), 5);
	EXPECT_EQ(i.funkcja_zwracajaca_10(), 10);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
