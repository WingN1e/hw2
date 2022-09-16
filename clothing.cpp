#include <iostream>
#include <sstream>
#include <string>
#include "clothing.h"
#include "util.h"
#include "product.h"

using namespace std;

//Constructor 
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, string size, string brand):
  //calls the Product class
Product(category, name, price, qty) {
  //data members;
  size_= size;
  brand_ = brand;
}

//Destructor
Clothing::~Clothing() {
}

std::set<std::string> Clothing::keywords() const {
  //return a set of keywords
  set<string> clothingKeywords;
  //puts in name 
  clothingKeywords = parseStringToWords(name_);
  //create a new set for the brand
  set<string> brandKeywords;
  brandKeywords = parseStringToWords(brand_);
  //insert the author keywords into book keywords
  clothingKeywords.insert(brandKeywords.begin(), brandKeywords.end());
  //returns the set
  return clothingKeywords;
}

std::string Clothing::displayString() const {
  string word = "";
  //adds the name
  word = word + name_;
  //makes a break in the line
  word = word + "\n"; 
  //adds the size and brand in line two
  word = word + "Size: " + size_ + "Brand: " + brand_;
  //makes a break in the line
  word = word + "\n";
  //display price and quantity left
  word = word + to_string(price_) + " " + to_string(qty_) + "left.";
  //returns the string
  return word;
}

void Clothing::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}