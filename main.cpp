#include <iostream>
#include <string>
#include <deque>

#include "map.hpp"
// #include <map>
// #define _map std::map
#define _map ft::map

// #include <stack>
// #define _stack std::stack

// #include <vector>
// #define _vector std::vector

// #include <stdlib.h>

// #define _make_pair std::make_pair

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public _stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename _stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	_vector<std::string> vector_str;
// 	_vector<int> vector_int;
// 	_stack<int> stack_int;
// 	_vector<Buffer> vector_buffer;
// 	_stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	_map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	_vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(_make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		_map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }

struct A {
private: 
	int _b;
public:
	int &b(int privileges) {
		(void)privileges;
		return _b;
	}
};

#include <map>

int main() {
	_map<int, int> a, e;
	ft::pair<int, int> b(1, 2);
	a.insert(b);
	e.insert(b);
	std::map<int, int> c, g;
	std::pair<int, int> d(1, 2);
	c.insert(d);
	g.insert(d);
	std::cout << (c == g ? "true" : "false") << std::endl;
	std::cout << (a == e ? "true" : "false") << std::endl;
	std::cout << c[1] << std::endl;
	std::cout << a[1] << std::endl;
	a[2] = 10;
	std::cout << a[2] << std::endl;
	A test;
	test.b(0) = 2;
	std::cout << test.b(0)  << std::endl;
	return 0;
}
