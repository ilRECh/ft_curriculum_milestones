#pragma once
#include <iostream>
#include <limits>
#include <map>

class Span
{
private:
	std::map<int, int> m_MArr;
	std::size_t m_nMax;
	Span();
public:
	~Span();
	Span(const Span& S);
	Span& operator=(const Span& S);
	Span(unsigned int N);
	void addNumber(int num);
	std::size_t shortestSpan();
	std::size_t longestSpan();
};
