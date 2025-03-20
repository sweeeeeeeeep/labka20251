#pragma once
#include "Product.h"
#include <vector>

class ProductManeger
{
private:
	std::vector<std::unique_ptr<Product>> products;
public:
	void addProduct(std::unique_ptr<Product> product);
	void removeProduct(const std::string& name);
	void sellProduct(const std::string& name, int quantity);
	void saveToConfig(const std::string& filename) const;
	void showProducts() const;

};

