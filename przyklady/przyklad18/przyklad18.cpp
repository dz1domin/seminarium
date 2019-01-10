#include "przykladowa_klasa.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

using ::testing::Return;
using ::testing::InSequence;

class pan
{
public:
	pan(samochodzik& s) : m_s(s) {  }

	void wyruszWPodroz()
	{
		for(int i = 0; i < 5; i++)
			std::cout << m_s.getPredkosc() << std::endl;

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

	// trzeba pamiętać o RetiresOnSaturation
	// poniższy kod generuje błąd testu
	// for(int i = 0; i < 5; i++)
	// {
	// 	EXPECT_CALL(s, getPredkosc())
	// 					.WillOnce(Return(1 * i));
	// }

	for(int i = 1; i <= 5; i++)
	{
		EXPECT_CALL(s, getPredkosc())
						.WillOnce(Return(1 * i))
						.RetiresOnSaturation();
	}

	// a jak odwrócić kolejność?
	{
		InSequence atrapa;
		for(int i = 1; i <= 5; i++)
		{
			EXPECT_CALL(s, getPredkosc())
							.WillOnce(Return(1 * i))
							.RetiresOnSaturation();
		}
	}

	pan p(s);
	p.wyruszWPodroz();

	p.wyruszWPodroz();
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
