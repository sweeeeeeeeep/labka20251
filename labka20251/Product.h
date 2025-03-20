#pragma once
#include <iostream>
#include <string>
#include <map>

using product_data = std::map<std::string, std::string>;
class Product
{
protected:
	std::string name;
	int shelfLife;
	int quantity;//количество 
	double price;
	std::string manufacturer;
public:
	//constructor
	Product();

	Product(const product_data& data);

	Product(const std:: string& name, int shelfLife, int quantity, double price, const std::string& manufacturer);

	//destructor
	virtual ~Product();

	//getters
	std::string getName() const;
	int getShelfLife() const;
	int getQuantity() const;
	double getPrice() const;
	std::string getManufacturer() const;
	virtual std::string getClass() const = 0;

	//setters
	void setName(const std::string& name);
	void setShelfLife(int shelfLife);
	void setQuantity(int quantity);
	void setPrice(double price);
	void setManufacturer(const std::string& manufacturer);

	//methods
	virtual std::string show() const;
	virtual std::unique_ptr<Product> clone() const = 0;
	virtual product_data toJson()const;




};

