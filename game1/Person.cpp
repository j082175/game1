#include "Person.h"
#include <iostream>

Person::Person(const unsigned& idNum, const std::string& name, const unsigned& age, const unsigned& height, const unsigned& weight)
    :mName(name), mAge(age), mHeight(height), mWeight(weight), Animal(idNum)
{

}



void Person::bark()
{
	Animal::bark();
	std::cout << "PersonBarking" << std::endl;
}

 const void Person::bark() const
{
    std::cout << "constPersonBarking" << std::endl;
}
