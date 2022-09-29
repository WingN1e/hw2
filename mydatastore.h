#ifndef mydatastore_h
#define mydatastore_h
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"
#include <map>
#include <array>
#include <queue>

using namespace std;

class MyDataStore : public DataStore {
public: 
  //Constructor
  MyDataStore();
  //Destructor
  ~MyDataStore();
  //Member functions
  void addProduct(Product *p);
  void addUser(User* u);
  vector <Product*> search(std::vector<std::string>& terms, int type);
  void dump(std::ostream& ofile);

  //Add to cart
  void addToCart(std::string user, Product* p);
  //View the cart
  void viewCart(std::string user);
  //Buy the cart
  void buyCart(std::string user);

private:
  //Maps username to vector of products
  map<string, vector<Product*>> userCarts;
  //Maps username to their user data
  map<string, User*> userData;
  //Vector for all the products
  set<Product*> allProducts;
  //map keywords to the products
  map<string, set<Product*>> keyMap;
};
#endif