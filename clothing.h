#ifndef clothing_h
#define clothing_h
#include <iostream>
#include "product.h"
#include <stdio.h>
#include <string>

class Clothing : public Product {
public: 

  //constructor 
  Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
  
  //prototypes 
  std::set<std::string> keywords() const;
  std::string displayString() const;
  void dump(std::ostream& os) const;

  //Destructor 
  ~Clothing();

protected:
  std::string size_;
  std::string brand_;
};
#endif