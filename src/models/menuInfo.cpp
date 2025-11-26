#include "models/menuInfo.hpp"

Product::Product(string itemName, float itemPrice, int itemAmount, string itemCategory) : itemName(itemName), itemPrice(itemPrice), itemAmount(itemAmount), itemCategory(itemCategory){}
    string Product::getItemName() const{
        return itemName;
    };
    float Product::getItemPrice() const{
        return itemPrice;
    };
    int Product::getItemAmount() const{
        return itemAmount;
    };
    string Product::getItemCategory() const{
        return itemCategory;
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
    void Product::setItemCategory(string itemCategory){
        this->itemCategory = itemCategory;
    };