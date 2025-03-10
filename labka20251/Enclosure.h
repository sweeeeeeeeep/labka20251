#pragma once
#include "Product.h"
#include<iostream>
#include<string>
#include <map>

using product_data = std::map<std::string, std::string>;
class Enclosure :
    public Product
{
private:
	std::string type;
	int area;
public:
	//constructor
	Enclosure();
	Enclosure(const product_data& data);
	Enclosure(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer, const std::string& type, int area);
	//destructor
	virtual ~Enclosure();
	//getters
	std::string getType() const;
	int getArea() const;
	//setters
	void setType(const std::string& type);
	void setArea(int area);
	//methods
	virtual std::string show() const override;


};

