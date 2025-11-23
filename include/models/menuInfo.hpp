#pragma once
#include <string>

using namespace std;

class Product {
private :
    string itemName;
    float itemPrice;
    int itemAmount;


public :
    Product(string itemName, float itemPrice, int itemAmount);
    string getItemName() const;
    float getItemPrice() const;
    int getItemAmount() const;

    void setItemName(string itemName);
    void setItemPrice(float itemPrice);
    void setItemAmount(int itemAmount);

};