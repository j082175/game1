#pragma once
#include <vector>
#include "Uncopyable.h"
#include <memory>

class Animal : private Uncopyable
{
	const static unsigned int info = 50;
	enum
	{
		info2 = 100
	};
	unsigned int mIdentificationNumber;
	std::vector<std::size_t> vec;
	//std::shared_ptr<Person> shared;
public:
	Animal(const unsigned& num);



	virtual void bark() = 0;

	virtual ~Animal() = 0;

	void bark2();

	const std::size_t& operator[](const std::size_t& index)const;

	std::size_t& operator[](const std::size_t& index);

	void getInfo();
	void getIdNum();
	virtual const void bark() const;
private:
	void increaseCount();
};

