#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>

class Converter
{
private:
	char m_nCharValue;
	std::string m_sCharStatus;
	int m_nIntValue;
	std::string m_sIntStatus;
	float m_fFloatValue;
	std::string m_sFloatStatus;
	double m_dDoubleValue;
	std::string m_sDoubleStatus;
	Converter();
	Converter(const Converter &C);
	Converter& operator=(const Converter &C);
public:
	Converter(char *num);
	~Converter();
	void printCharValue() const;
	void printIntValue() const;
	void printFloatValue() const;
	void printDoubleValue() const;

	class ShittyNum : std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};


