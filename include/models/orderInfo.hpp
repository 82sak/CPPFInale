#pragma once
#include <iostream>

using namespace std;

class Order {
private :
    string itemOrderName;
    float itemOrderPrice;
    int itemOrderAmount;
    string itemOrderCategory;

public :
    Order(string itemOrderName, float itemOrderPrice, int itemOrderAmount, string itemOrderCategory);
    string getItemOrderName() const;
    float getItemOrderPrice() const;
    int getItemOrderAmount() const;
    string getItemOrderCategory() const;

    void setItemOrderName(string itemName);
    void setItemOrderPrice(float itemPrice);
    void setItemOrderAmount(int itemAmount);
    void setItemOrderCategory(string itemCategory);
};