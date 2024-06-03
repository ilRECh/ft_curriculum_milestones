#include "Span.hpp"

Span::Span():	m_MArr(),
				m_nMax()
{
}

Span::~Span()
{
}

Span::Span(const Span &S):	m_MArr(S.m_MArr),
							m_nMax(S.m_nMax)
{
}

Span& Span::operator=(const Span &S)
{
	if (this == &S)
		return (*this);
	m_MArr = S.m_MArr;
	m_nMax = S.m_nMax;
	return (*this);
}

Span::Span(unsigned int N):	m_MArr(),
							m_nMax(N)
{
}

void Span::addNumber(int num)
{
	if (m_nMax == 0)
		throw std::out_of_range("Span is full");
	m_MArr[num];
	m_nMax--;
}

std::size_t Span::shortestSpan()
{
	int prev = 0;
	int cur = 0;
	int shortest = std::numeric_limits<int>::max();
	if (m_MArr.size() < 2)
		throw std::out_of_range("no span to find");
	std::map<int, int>::iterator it = m_MArr.begin();
	while (true)
	{
		prev = it->first;
		it++;
		if (it == m_MArr.end())
			break ;
		cur = it->first;
		if (cur - prev < shortest)
		{
			shortest = cur - prev;
		}
	}
	return (shortest);
}

std::size_t Span::longestSpan()
{
	if (m_MArr.size() < 2)
		throw std::out_of_range("no span to find");
	return (m_MArr.rbegin()->first - m_MArr.begin()->first);
}
