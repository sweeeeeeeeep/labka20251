#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal() : Product(), age(0)
{
}

Animal::Animal(const product_data& data) : Product(data), age(data.find("age") != data.end() ? std::stoi(data.find("age") -> second) : 0)
{

}

Animal::Animal(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer, int age) : Product(name, shelfLife, quantity, price, manufacturer), age(age)
{
}

Animal::~Animal()
{
}



int Animal::getAge() const
{
	return age;
}


void Animal::setAge(int age)
{
	this->age = age;
}

std::string Animal::show() const
{
	std::string result = Product::show() +  " Age: " + std::to_string(age)+ " Type: "+ type();
	return result;

}

product_data Animal::toJson() const
{
	
	product_data data = Product::toJson();
	data["age"] = std::to_string(age);
	return data;
}



