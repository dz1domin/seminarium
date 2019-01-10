#pragma once

class InterfejsFolderu
{
public:
	virtual int liczbaPlikow() = 0;
	virtual std::vector<std::string> nazwyPlikow() = 0;
	virtual std::size_t rozmiarPliku(std::string) = 0;
};

class ObiektLiczacy
{
public:
	ObiektLiczacy(InterfejsFolderu& i) : m_i(i) {}

	std::map<std::string, double> rysujWykres();
private:
	InterfejsFolderu& m_i;
};
