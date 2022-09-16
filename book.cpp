#include <iostream>
#include <sstream>
#include <string>
#include "book.h"
#include "util.h"
#include "product.h"

using namespace std;

//Constructor 
Book::Book(const std::string category, const std::string name, double price, int qty, string isbn, string author):
//calls the Product class
Product(category, name, price, qty) {
  //data members;
  isbn_ = isbn;
  author_ = author;
}

//Destructor
Book::~Book() {
}

std::set<std::string> Book::keywords() const {
  //return a set of keywords
  set<string> bookKeywords;
  //puts in author name and ibsn
  bookKeywords = parseStringToWords(name_);
  bookKeywords.insert(isbn_);
  //create a new set for the author
  set<string> authorKeywords;
  authorKeywords = parseStringToWords(author_);
  //insert the author keywords into book keywords
  bookKeywords.insert(authorKeywords.begin(), authorKeywords.end());
  return bookKeywords;
}

std::string Book::displayString() const {
  string word = "";
  word = word + name_;
  word = word + "\n";
  word = word + "Author: " + author_ + " IBSN: " + isbn_;
  word = word + "\n";
  word = word + to_string(price_) + " " + to_string(qty_) + " left."; 
  return word;
}

void Book::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}
