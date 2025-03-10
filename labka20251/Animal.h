#pragma once  
#include "Product.h"  
#include <iostream>  
#include <string>  
#include <map>

using product_data = std::map<std::string, std::string>;
class Animal :  
   public Product  
{  
protected:  
   int age;  
public:  
   //constructor  
   Animal();
   Animal(const product_data& data);
   Animal(const std::string& name, int shelfLife, int quantity, double price, const std::string& manufacturer, int age);  

   //destructor  
   virtual ~Animal();  

   //getters  
   int getAge() const;  

   //setters  
   void setAge(int age);  

   //methods  
   virtual std::string type() const = 0;  
   virtual std::string show() const override;  

};
