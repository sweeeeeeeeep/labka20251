#include "Mammal.h"  
#include <iostream>  
#include <string>  

Mammal::Mammal() : Animal(), petName("noName")  
{  
}  

Mammal::Mammal(const product_data& data) : Animal(data), petName(data.find("petName") != data.end() ? data.find("petName")->second : "noName")  
{  
}  

Mammal::Mammal(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer, int age, const std::string& petName) : Animal(name, shelfLife, quantity, price, manufacturer, age), petName(petName)  
{  
}  

Mammal::~Mammal()  
{  
}  

std::string Mammal::getPetName() const  
{  
return std::string(petName);  
}  
std::string Mammal::getClass() const  
{  
return "mammal";  
}  

void Mammal::setPetName(const std::string& petName)  
{  
this->petName = petName;  
}  

std::string Mammal::type() const  
{  
return "mlekopitayshie";  
}  

std::string Mammal::show() const  
{  
std::string result = Animal::show() + " Pet name: " + petName;  
return result;  
}  

std::unique_ptr<Product> Mammal::clone() const  
{  
return std::make_unique<Mammal>(*this);  
}  

product_data Mammal::toJson() const  
{  
product_data data = Animal::toJson();  
data["petName"] = petName;  
data["class"] = getClass();  
return data;  
}
