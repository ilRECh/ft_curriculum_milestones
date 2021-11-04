#pragma once

template <typename T>
class Array
{
private:
	std::size_t m_nSize;
	T *m_TArray;
public:
	Array():	m_nSize(),
				m_TArray()
	{};
	~Array()
	{
		delete m_TArray;
	};
	Array(std::size_t n):	m_nSize(n),
							m_TArray(new T[n]())
	{};
	Array(const Array<T> &A):	m_nSize(A.m_nSize),
								m_TArray(new T[A.m_nSize]())
	{
		for (std::size_t i = 0; i < m_nSize; ++i)
		{
			m_TArray[i] = A.m_TArray[i];
		}
	}
	Array& operator=(const Array<T> &A)
	{
		if (this == &A)
			return (*this);
		m_nSize = A.m_nSize;
		m_TArray = new T[m_nSize]();
		for (std::size_t i = 0; i < m_nSize; ++i)
		{
			m_TArray[i] = A.m_TArray[i];
		}
		return (*this);
	}
	T& operator[](std::size_t idx)
	{
		if (idx > m_nSize)
			throw std::out_of_range("index out of range");
		return (m_TArray[idx]);
	}
	std::size_t size() const
	{
		return (m_nSize);
	}
};
