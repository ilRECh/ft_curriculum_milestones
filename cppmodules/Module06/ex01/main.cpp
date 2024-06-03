#include <iostream>

struct Data
{
	const char s;
	const char h;
	const char i;
	const char t;
	Data():	s('s'),
			h('h'),
			i('i'),
			t('t')
	{}
};

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main()
{
	Data data;
	std::cout <<	deserialize(serialize(&data))->s << '\n' <<
					deserialize(serialize(&data))->h << '\n' <<
					deserialize(serialize(&data))->i << '\n' <<
					deserialize(serialize(&data))->t << std::endl;
	std::cout <<	&data << '\n' <<
					deserialize(serialize(&data)) << std::endl;
	return (0);
}
