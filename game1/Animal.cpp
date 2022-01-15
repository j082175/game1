#include "Animal.h"
#include <iostream>

static unsigned int count;

 Animal::Animal(const unsigned& num)
	:mIdentificationNumber(num)
{
	 vec.resize(num);
	 increaseCount();
 }

void Animal::bark()
{
	std::cout << "AnimalBarking" << std::endl;
}

Animal::~Animal(){}

void Animal::bark2()
{
	std::cout << "Animal" << std::endl;
}

void Animal::increaseCount()
{
	count++;
	std::cout << "count :" << count << std::endl;
}

void Animal::getInfo()
{
	std::cout << info << " " << info2 << std::endl;
}

void Animal::getIdNum()
{
	std::cout << "IdentificationNumber : " << mIdentificationNumber << std::endl;
}

const void Animal::bark() const
{
	std::cout << "constAnimalBarking" << std::endl;
}

const std::size_t& Animal::operator[](const std::size_t& index)const
{
	std::cout << "ConstAnimalOperator[]" << std::endl;
	return vec[index];
}

std::size_t& Animal::operator[](const std::size_t& index)
{
	std::cout << "AnimalOperator[]" << std::endl;
	return const_cast<std::size_t&>(static_cast<const Animal&>(*this)[index]);
}
