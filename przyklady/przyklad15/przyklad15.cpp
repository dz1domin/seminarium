#include "przykladowa_klasa.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;

class pan
{
public:
	pan(samochodzik& s) : m_s(s) {  }

	void dzialaj()
	{
		m_s.getPozycje();
	}
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
	EXPECT_CALL(s, getPozycje())
							.Times(3)
							.WillRepeatedly(Return(std::pair<double, double>(10, 10)));

	pan p(s);
	
	for(int i = 0; i < 3; i++)
		p.dzialaj();
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
