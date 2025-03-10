#pragma once
#include "Animal.h"
#include <iostream>
#include <string>
#include <map>

using product_data = std::map<std::string, std::string>;
class Amphibian :
    public Animal
{
private:
	std::string habitat;
public:
	//constructor
	Amphibian();
	Amphibian(const product_data& data);
	Amphibian(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer, int age, const std::string& habitat);
	//destructor
	virtual ~Amphibian();
	//getters
	std::string getHabitat() const;
	//setters
	void setHabitat(const std::string& habitat);
	//methods
	std::string type() const override;
	virtual std::string show() const override;
};

