#include <iostream>
#include <sstream>
#include <string>
#include "movie.h"
#include "util.h"
#include "product.h"

using namespace std;

//Constructor 
Movie::Movie(const std::string category, const std::string name, double price, int qty, string genre, string rating):
  //calls the Product class
Product(category, name, price, qty) {
  //data members;
  genre_ = genre;
  rating_ = rating;
}

//Destructor
Movie::~Movie() {
}

std::set<std::string> Movie::keywords() const {
  //return a set of keywords
  set<string> movieKeywords;
  //puts in name 
  movieKeywords = parseStringToWords(name_);
  //create a new set for the genre
  set<string> genreKeywords;
  genreKeywords = parseStringToWords(genre_);
  //insert the author keywords into book keywords
  movieKeywords.insert(genreKeywords.begin(), genreKeywords.end());
  //returns the set
  return movieKeywords;
}

std::string Movie::displayString() const {
  string word = "";
  //adds the name
  word = word + name_;
  //makes a break in the line
  word = word + "\n"; 
  //adds the genre and rating in line two
  word = word + "Genre: " + genre_ + "Rating: " + rating_;
  //makes a break in the line
  word = word + "\n";
  //display price and quantity left
  word = word + to_string(price_) + " " + to_string(qty_) + " left.";
  //returns the string
  return word;
}

void Movie::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}