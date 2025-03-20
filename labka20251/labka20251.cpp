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
#include "ProductManeger.h"

void showMenu() {
	std::cout << "1. Show products" << std::endl;
	std::cout << "2. Add product" << std::endl;
	std::cout << "3. Remove product" << std::endl;
	std::cout << "4. Sell product" << std::endl;
	std::cout << "5. Save to config" << std::endl;
	std::cout << "6. Exit" << std::endl;
}

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
	ProductManeger manager;
	/*for (const auto& data : productsData) {
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
	}*/
	for (const auto& data : productsData) {
		// Проверяем, есть ли ключ "class"
		if (data.find("class") == data.end()) {
			std::cout << "Error: 'class' not found in loaded data. Skipping." << std::endl;
			continue;
		}
		std::string type = data.at("class"); // "mammal", "amphibian", "enclosure", ...
		std::cout << "Loaded class: " << type << std::endl;
		if (type == "mammal") {
			manager.addProduct(std::make_unique<Mammal>(data));
		}
		else if (type == "amphibian") {
			manager.addProduct(std::make_unique<Amphibian>(data));
		}
		else if (type == "enclosure") {
			manager.addProduct(std::make_unique<Enclosure>(data));
		}
		else {
			std::cout << "Error: unknown class '" << type << "' in loaded data. Skipping." << std::endl;
		}
	}
	int choice;
	do {
		showMenu();
		std::cin >> choice;
		switch (choice) {
		case 1:
			manager.showProducts();
			break;
		case 2: {
			std::string type;
			std::cout << "Enter product type (mammal, amphibian, enclosure): ";
			std::cin >> type;
			product_data data;
			std::cout << "Enter product details:" << std::endl;
			std::cout << "Name: ";
			std::cin >> data["name"];
			std::cout << "Shelf Life: ";
			std::cin >> data["shelfLife"];
			std::cout << "Quantity: ";
			std::cin >> data["quantity"];
			std::cout << "Price: ";
			std::cin >> data["price"];
			std::cout << "Manufacturer: ";
			std::cin >> data["manufacturer"];
			if (type == "mammal") {
				data["class"] = "mammal";
				std::cout << "Age: ";
				std::cin >> data["age"];
				std::cout << "Pet Name: ";
				std::cin >> data["petName"];
				manager.addProduct(std::make_unique<Mammal>(data));
			}
			else if (type == "amphibian") {
				data["class"] = "amphibian";
				std::cout << "Age: ";
				std::cin >> data["age"];
				std::cout << "Habitat: ";
				std::cin >> data["habitat"];
				manager.addProduct(std::make_unique<Amphibian>(data));
			}
			else if (type == "enclosure") {
				data["class"] = "enclosure";
				std::cout << "Type: ";
				std::cin >> data["type"];
				std::cout << "Area: ";
				std::cin >> data["area"];
				manager.addProduct(std::make_unique<Enclosure>(data));
			}
			else {
				std::cout << "Error: unknown class " << type << std::endl;
			}
			break;
		}
		case 3: {
			std::string name;
			std::cout << "Enter product name to remove: ";
			std::cin >> name;
			manager.removeProduct(name);
			break;
		}
		case 4: {
			std::string name;
			std::cout << "Enter product name to sell: ";
			std::cin >> name;
			std::cout << "enter quantity to sell: ";
			int quantity;
			std::cin >> quantity;
			manager.sellProduct(name,quantity);
			break;
		}
		case 5:
			manager.saveToConfig("config.json");
			break;
		case 6:
			std::cout << "Exiting..." << std::endl;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	} while (choice != 6);

	return 0;

	
}
