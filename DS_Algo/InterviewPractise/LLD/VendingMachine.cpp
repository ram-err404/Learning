/*
  Requirements:
  -------------
  1.) Some sets of items.
  2.) Category of items. 
        {Drinks, Chips, Biscuits, etc}
  3.) Accept tokens.
  4.) Get item
*/

#include<bits/stdc++.h>
using namespace std;

class VendingMachine{
  list<Item>   products;

public:
  Item        getItem(string itemCode, double money);
  Item        viewItem(string itemCode);
  list<Item>  viewItems(Category category);
};

class Item {
  int       itemId;
  string    itemName;
  string    itemDescription;
  double    price;
  Category  category;
};

enum Category {
  DRINKS, CHIPS, BISCUITS
};

class Operator {

public:
  void  addItem(VendingMachine &vendingMachine, Item &item);
  bool  correctIssue(VendingMachine &vendingMachine);
};