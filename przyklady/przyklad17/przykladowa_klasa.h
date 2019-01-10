#pragma once

#include <utility>

class samochodzik
{
public:
	virtual bool doPrzodu() = 0;
	virtual bool doTylu() = 0;
	virtual bool skrec(double kat) = 0;
	virtual bool wlaczSilnik() = 0;
	virtual bool wylaczSilnik() = 0;
	virtual bool przyspiesz(double war) = 0;
	virtual double getPredkosc() = 0;
	virtual double getKat() = 0;
	virtual std::pair<double, double> getPozycje() = 0;
	virtual ~samochodzik(){}
};	