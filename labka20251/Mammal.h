#pragma once
#include "Animal.h"
#include <iostream> 
#include <string>
#include <map>

using product_data = std::map<std::string, std::string>;
class Mammal :
    public Animal
{
private:
	std::string petName;
public:
	//constructor
	Mammal();
	Mammal(const product_data& data);
	Mammal(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer, int age, const std::string& petName);

	//destructor
	virtual ~Mammal();

	//getters
	std::string getPetName() const;
	std::string getClass() const override;

	//setters
	void setPetName(const std::string& petName);

	//methods
	std::string type() const override;
	virtual std::string show() const override;
	std::unique_ptr<Product> clone() const override;
	product_data toJson()const override;
};

