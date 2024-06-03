#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack<T>() {}
	~MutantStack<T>() {}
	MutantStack<T>(const MutantStack<T> &M) {}
	MutantStack<T>& operator=(const MutantStack<T> &M)
	{
		if (this == &M)
			return (*this);
		return (*this);
	}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void)
	{
		return (this->c.begin());
	}
	iterator end(void)
	{
		return (this->c.end());
	}
};			
