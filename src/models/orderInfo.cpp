#include "models/orderInfo.hpp"

Order::Order(string itemOrderName, float itemOrderPrice, int itemOrderAmount, string itemOrderCategory) : itemOrderName(itemOrderName), itemOrderPrice(itemOrderPrice), itemOrderAmount(itemOrderAmount), itemOrderCategory(itemOrderCategory){}
    string Order::getItemOrderName() const{
        return itemOrderName;
    };
    float Order::getItemOrderPrice() const{
        return itemOrderPrice;
    };
    int Order::getItemOrderAmount() const{
        return itemOrderAmount;
    };
    string Order::getItemOrderCategory() const{
        return itemOrderCategory;
    };

    void Order::setItemOrderName(string itemOrderName){
        this->itemOrderName = itemOrderName;
    };
    void Order::setItemOrderPrice(float itemOrderPrice){
        this->itemOrderPrice = itemOrderPrice;
    };
    void Order::setItemOrderAmount(int itemOrderAmount){
        this->itemOrderAmount = itemOrderAmount;
    };
    void Order::setItemOrderCategory(string itemOrderCategory){
        this->itemOrderCategory = itemOrderCategory;
    };