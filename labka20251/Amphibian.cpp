#include "Amphibian.h"
#include <iostream>	
#include <string>	

Amphibian::Amphibian() : Animal(), habitat("noHabitat")
{
}

Amphibian::Amphibian(const product_data& data) : Animal(data), habitat(data.find("habitat") != data.end() ? data.find("habitat") ->second : "noHabitat")
{
}

Amphibian::Amphibian(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer, int age, const std::string& habitat) : Animal(name, shelfLife, quantity, price, manufacturer, age), habitat(habitat)
{
}

Amphibian::~Amphibian()
{
}

std::string Amphibian::getHabitat() const
{
	return std::string(habitat);
}

void Amphibian::setHabitat(const std::string& habitat)
{
	this->habitat = habitat;
}

std::string Amphibian::type() const
{
	return "amphibian";
}

std::string Amphibian::show() const
{
	std::string result = Animal::show() + " Habitat: " + habitat;
	return result;
}

