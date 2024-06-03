#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	const Animal *Array[10];
	const Dog dog;
	const Cat cat;
	// const Animal animal;
	dog.getBrainAddress();
	cat.getBrainAddress();
	for (int i = 0; i < 5; ++i)
	{
		Array[i] = new Dog(dog);
		Array[i]->getBrainAddress();
	}
	for (int i = 5; i < 10; ++i)
	{
		Array[i] = new Cat(cat);
		Array[i]->getBrainAddress();
	}
	for (int i = 0; i < 10; ++i)
	{
		delete Array[i];
	}
	return (0);
}
