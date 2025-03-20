#include "ProductManeger.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

void ProductManeger::addProduct(std::unique_ptr<Product> product)
{
	products.push_back(std::move(product));
}

void ProductManeger::removeProduct(const std::string& name)
{
	products.erase(std::remove_if(products.begin(), products.end(), [&name](const std::unique_ptr<Product>&product) {
		return product->getName() == name;
	}), products.end());
}

void ProductManeger::sellProduct(const std::string& name, int quantity)
{
	bool productFound = false;
	for (auto& product : products) {
		if (product -> getName() == name )
		{
			productFound = true;
			if (product->getQuantity() > 0) {
				product->setQuantity(product->getQuantity() - quantity);
				std::cout << "sold one umit of " << name << std::endl;
			}
			else
			{
				std::cout << "no more units of " << name << std::endl;
			}
		}
		else
		{
			std::cout << "Product not found" << name << std::endl;
		}
	}
	
	
}

void ProductManeger::saveToConfig(const std::string& filename) const
{
	nlohmann::json j;
	for (const auto& product : products) {
		product_data data = product->toJson();
		j.push_back(data);
	}
	std::ofstream file(filename);
	file << j.dump(4);
	file.close();
}

void ProductManeger::showProducts() const
{
	for (const auto& product : products)
	{
		std::cout << product->show() << std::endl;
	}
}
