#pragma once
#include "Animal.h"
#include <string>

class Person :
    public Animal
{
    std::string mName;
    unsigned int mAge;
    unsigned int mHeight;
    unsigned int mWeight;
public:
    Person(const unsigned& idNum, const std::string& name = " ", const unsigned& age = 0,
        const unsigned& height = 0, const unsigned& weight = 0);


    virtual void bark();
    const void bark() const;
    

};

