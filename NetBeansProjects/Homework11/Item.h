/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: Admin
 *
 * Created on March 13, 2019, 8:41 PM
 */

#ifndef ITEM_H
#define ITEM_H
using namespace std;
#include <string>
class Item{
protected:
    string I_name;
    unsigned int I_price;
    Item(){}
    Item(string name, unsigned int price): I_name(name),I_price(price){}
public:
    virtual string getName() const{return I_name;}
    virtual unsigned int getPrice() const{return I_price;}
    virtual void print() const = 0;
    virtual ~Item(){};
};

#endif /* ITEM_H */

