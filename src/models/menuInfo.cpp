#include "models/menuInfo.hpp"

Product::Product(string itemName, float itemPrice, int itemAmount) : itemName(itemName), itemPrice(itemPrice), itemAmount(itemAmount){}
    string Product::getItemName() const{
        return itemName;
    };
    float Product::getItemPrice() const{
        return itemPrice;
    };
    int Product::getItemAmount() const{
        return itemAmount;
    };

    void Product::setItemName(string itemName){
        this->itemName = itemName;
    };
    void Product::setItemPrice(float itemPrice){
        this->itemPrice = itemPrice;
    };
    void Product::setItemAmount(int itemAmount){
        this->itemAmount = itemAmount;
    };