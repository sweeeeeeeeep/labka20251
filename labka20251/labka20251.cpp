#include "Mammal.h"

// labka20251.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Product.h"
#include "Animal.h"
#include "Enclosure.h"
#include "Amphibian.h"
#include <vector>
#include "JsonLoadData.h"
#include "LoadData.h"

int main()
{
	/*std::vector<Product*> products;

	std::cout << "vvedite col-vo productov" << std::endl;
	int n;
	std::cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		std::string name, manufacturer, typeOfProduct;
		int shelfLife, quantity;
		double price;
		std::cout << "vvedite name product" << std::endl;
		std::cin >> name;
		std::cout << "vvedite shelfLife product" << std::endl;
		std::cin >> shelfLife;
		std::cout << "vvedite quantity product" << std::endl;
		std::cin >> quantity;
		std::cout << "vvedite price product" << std::endl;
		std::cin >> price;
		std::cout << "vvedite manufacturer product" << std::endl;
		std::cin >> manufacturer;
		std::cout << "vvedite type of product" << std::endl;
		std::cin >> typeOfProduct;
		if (typeOfProduct == "animal")
		{
			int age;
			std::string type;
			std::cout << "vvedite age animal" << std::endl;
			std::cin >> age;
			std::cout << "vvedite type animal" << std::endl;
			std::cin >> type;
			if (type == "mammal")
			{
				std::string petName;
				std::cout << "vvedite petName" << std::endl;
				std::cin >> petName;
				products.push_back(new Mammal(name, shelfLife, quantity, price, manufacturer, age, petName));

			}
			else if (type == "amphibian")
			{
				std::string habitat;
				std::cout << "vvedite habitat" << std::endl;
				std::cin >> habitat;
				products.push_back(new Amphibian(name, shelfLife, quantity, price, manufacturer, age, habitat));
			}
			else
			{
				std::cout << "nepravilniy tip" << std::endl;
			}
		}
		else if (typeOfProduct == "enclosure")
		{
			std::string type;
			int area;
			std::cout << "vvedite type enclosure" << std::endl;
			std::cin >> type;
			std::cout << "vvedite area enclosure" << std::endl;
			std::cin >> area;
			products.push_back(new Enclosure(name, shelfLife, quantity, price, manufacturer, type, area));


		}
		else
		{
			std::cout << "net takogo product" << std::endl;
		}

	}
	for (auto product : products)
	{
		std::cout << product->show() << std::endl;
	}

	for (auto product : products)
	{
		delete product;
	}*/
	JsonLoadData jsonLoader("config.json");
	std::vector<product_data> productsData = jsonLoader.getData();

	std::vector<std::unique_ptr<Product>> products;
	for (const auto& data : productsData) {
		if (data.find("class") == data.end()) {
			std::cout << "Error: class not found" << std::endl;
			continue;
		}

		std::string type = data.at("class");
		if (type == "mammal") {
			products.push_back(std::make_unique<Mammal>(data));
		}
		else if (type == "amphibian") {
			products.push_back(std::make_unique<Amphibian>(data));
		}
		else if (type == "enclosure") {
			products.push_back(std::make_unique<Enclosure>(data));
		}
		else {
			std::cout << "Error: unknown class " << type << std::endl;
		}
	}

	for (const auto& product : products) {
		std::cout << product->show() << std::endl;
	}

	return 0;

	
}
