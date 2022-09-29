
#include "mydatastore.h"
#include "util.h"
#include "datastore.h"
#include <string>
#include <set>
#include <vector>
#include <stdio.h> 
#include <map> 
#include "product.h"
#include "user.h"

using namespace std;

//Constructor
MyDataStore::MyDataStore() {
   
}

MyDataStore::~MyDataStore() {
  for(set<Product*>::iterator it = allProducts.begin(); it != allProducts.end(); ++it) {
    delete (*it); 
  }
  for(map<string, User*>::iterator it = userData.begin(); it != userData.end(); ++it) {
    delete it->second; 
  }
}

void MyDataStore::addProduct(Product *p) {
  //create a set for p keywords
  set<string> key = p->keywords();
  //adds the product into a vector 
  allProducts.insert(p);
  //iterates through 
  for (set<string>::iterator it = key.begin(); it != key.end(); ++it) {
    string term = (*it);
    transform(term.begin(), term.end(), term.begin(), ::tolower);
    if (keyMap.find(term) != keyMap.end()) {
      keyMap[term].insert(p);
    }
    else {
      //key does not exist
      //creates new set and pushes back the item
      keyMap[term] = set<Product*>();
      keyMap[term].insert(p);
    }
  }
}

void MyDataStore::addUser(User* u) {
  //creates a string for the user
  //adds the user into the userData
  string name = u->getName();
  userData[name] = u;
}

vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  //creates a set for our terms
  set<Product*> keySet = keyMap[terms[0]];
  for (vector<string>::iterator it = terms.begin(); it != terms.end(); ++it) {
    if (keyMap.find(*it) != keyMap.end()) {
      //if type is 0 we have an intersection 
      if (type == 0) {
        keySet = setIntersection(keyMap[*it], keySet); 
      }
      else {
      //if type is 1 we have an union
        keySet = setUnion(keyMap[*it], keySet);
      }
    }
  }
  //we need to change the set to a vector and return it
  vector<Product*> returnedSet;
  returnedSet.assign(keySet.begin(), keySet.end());
  return returnedSet;
}

void MyDataStore::dump(ostream& ofile) {
  //loops through the products and dumps them
  //creates header for products
  ofile << "<products>" << endl;
  for (set<Product*>::iterator it = allProducts.begin(); it != allProducts.end(); ++it) {
    //dump the products into the output files
    (*it) -> dump(ofile);
  }
  //create footer for products
  ofile << "</products>" << endl;

  //loops through the products and dumps them
  //creates header for products
  ofile << "<users>" << endl;
  for (map<string, User*>::iterator it = userData.begin(); it != userData.end(); ++it) {
    //dump the users into the output files
    it -> second -> dump(ofile);
  }
  //creates footer for user
  ofile << "</user>";
}

void MyDataStore::addToCart(string user, Product *p) {
  //if the user is not in the database, we can't add their product to the cart
  if (userData.find(user) == userData.end()) {
    cout << "Invalid Username" << endl;
    return;
  }
  //adds the products into the user's cart
  userCarts[user].push_back(p);
}

void MyDataStore::viewCart(string user) {
  //checks to see if the user is in the database
  if(userCarts.find(user) != userCarts.end()) {
    int counter = 1;
    for (vector<Product*>::iterator it = userCarts[user].begin(); it != userCarts[user].end(); ++it) {
      //iterates through the items in the cart and prints them out
      cout << "Item " << counter++ << endl;
      cout << (*it)-> displayString() << endl;
    }
  }
  else {
    //user does not exist
    cout << "Invalid Username" << endl;
  }
}

void MyDataStore::buyCart(string user) {
  //checks to see if the user is in the database 
  if (userCarts.find(user) != userCarts.end()) {
    for (vector<Product*>::iterator it = userCarts[user].begin(); it != userCarts[user].end();) {
      //iterates through the items in the cart for purchase
      if ((*it)->getQty() >= 1 && userData[user]->getBalance() >= (*it)->getPrice()) {
        //if there is an item avaliable for purchase and the user has enough money
        //Buy the item
        //Subtract 1 from quantity
        (*it)->subtractQty(1);
        userData[user]->deductAmount((*it)->getPrice());
        //removes the item from the cart
        userCarts[user].erase(it);
      }
      else {
        ++it;
      }
    }
  }
  else {
    cout << "Invalid Username" << endl;
  }
}