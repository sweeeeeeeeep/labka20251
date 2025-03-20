#include "Product.h"
#include <iostream>

Product::Product() : name("noName"), shelfLife(0), quantity(0), price(0), manufacturer("noManufacturer")
{ 
}

Product::Product(const product_data& data) {
    auto getValue = [&](const std::string& key, const std::string& defaultValue) {
        return data.find(key) != data.end() ? data.at(key) : defaultValue;
        };

    auto getIntValue = [&](const std::string& key, int defaultValue) {
        return data.find(key) != data.end() ? std::stoi(data.at(key)) : defaultValue;
        };

    auto getDoubleValue = [&](const std::string& key, double defaultValue) {
        return data.find(key) != data.end() ? std::stod(data.at(key)) : defaultValue;
        };

    name = getValue("name", "noName");
    shelfLife = getIntValue("shelfLife", 0);
    quantity = getIntValue("quantity", 0);
    price = getDoubleValue("price", 0.0);
    manufacturer = getValue("manufacturer", "noManufacturer");
}

Product::Product(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer) : name(name), shelfLife(shelfLife), quantity(quantity), price(price), manufacturer(manufacturer)
{
}

Product::~Product()
{
}

std::string Product::getName() const
{
	return std::string(name);
}

int Product::getShelfLife() const
{
	return shelfLife;
}

int Product::getQuantity() const
{
	return quantity;
}

double Product::getPrice() const
{
	return price;
}

std::string Product::getManufacturer() const
{
	return std::string(manufacturer);
}
//setters
void Product::setName(const std::string& name)
{
	this->name = name;
}

void Product::setShelfLife(int shelfLife)
{
	this->shelfLife = shelfLife;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::setManufacturer(const std::string& manufacturer)
{
	this->manufacturer = manufacturer;
}

std::string Product::show() const
{
	std::string result;
	result = "Name: " + name + " ShelfLife: " + std::to_string(shelfLife) + " Quantity: " + std::to_string(quantity) + " Price: " + std::to_string(price) + " Manufacturer: " + manufacturer;
	return result;
}

product_data Product::toJson() const
{
	product_data data;
	data["name"] = name;
	data["shelfLife"] = std::to_string(shelfLife);
	data["quantity"] = std::to_string(quantity);
	data["price"] = std::to_string(price);
	data["manufacturer"] = manufacturer;

	return data;
}









