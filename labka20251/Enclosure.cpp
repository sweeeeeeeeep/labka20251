#include "Enclosure.h"
#include <iostream>
#include <string>
Enclosure::Enclosure() : Product(), type("noType"), area(0)
{
}

Enclosure::Enclosure(const product_data& data) : Product(data),
type(data.find("type") != data.end() ? data.find("type")->second : "noType"),
area(data.find("area") != data.end() ? std::stoi(data.find("area")->second) : 0)
{
}

Enclosure::Enclosure(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer, const std::string& type, int area) : Product(name, shelfLife, quantity, price, manufacturer), type(type), area(area)
{
}

Enclosure::~Enclosure()
{
}

std::string Enclosure::getType() const
{
	return std::string(type);
}

int Enclosure::getArea() const
{
	return area;
}

void Enclosure::setType(const std::string& type)
{
	this->type = type;
}

void Enclosure::setArea(int area)
{
	this->area = area;
}

std::string Enclosure::show() const
{
	std::string result = Product::show() + " Type: " + type + " Area: " + std::to_string(area);
	return result;
}
