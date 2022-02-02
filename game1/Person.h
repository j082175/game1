#pragma once
#include "Animal.h"
#include <string>
#include <initializer_list>
#include <vector>
//
#include <iostream>


class Person :
    public Animal
{

    std::string mName;
    unsigned int mAge;
    unsigned int mHeight;
    unsigned int mWeight;
    
public:
     explicit Person(const unsigned& idNum, const std::string& name = " ", const unsigned& age = 0,
        const unsigned& height = 0, const unsigned& weight = 0);



    virtual void bark();
    const void bark() const;

    Person(const Person& p)
        :mName(p.mName), mAge(p.mAge), mHeight(p.mHeight), mWeight(p.mWeight),Animal(p)
    {
        std::cout << "hoho" << std::endl;
    }

    const Person& operator=(const Person& p)
    {
        std::cout << "fuck you" << std::endl;
        if (this == &p)
        {
            std::cout << "Same!!!" << std::endl;
            return *this;
        }

        Animal::operator=(p);
        this->mName = p.mName;
        this->mAge = p.mAge;
        this->mHeight = p.mHeight;
        this->mWeight = p.mWeight;
        return *this;
    }
};

