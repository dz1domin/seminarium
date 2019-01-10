#include "przykladowa_klasa.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;

class pan
{
public:
	pan(samochodzik& s) : m_s(s) {  }
private:
	samochodzik& m_s;
};

class mockowy_samochodzik : public samochodzik
{
public:
	MOCK_METHOD0(doPrzodu, bool());
	MOCK_METHOD0(doTylu, bool());
	MOCK_METHOD1(skrec, bool(double));
	MOCK_METHOD0(wlaczSilnik, bool());
	MOCK_METHOD0(wylaczSilnik, bool());
	MOCK_METHOD1(przyspiesz, bool(double));
	MOCK_METHOD0(getPredkosc, double());
	MOCK_METHOD0(getKat, double());
	MOCK_METHOD0(getPozycje, std::pair<double, double>());
};

TEST(pan_test, pierwszy)
{
	mockowy_samochodzik s;
	EXPECT_CALL(s, wlaczSilnik())
							.Times(AtLeast(1));

	pan p(s);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
