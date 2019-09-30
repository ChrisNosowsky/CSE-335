/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laptop.h
 * Author: Admin
 *
 * Created on March 13, 2019, 1:30 PM
 */
#include "Item.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#ifndef LAPTOP_H
#define LAPTOP_H

class Laptop: public Item {
public:
    Laptop() {}
    Laptop(string name, int cost, string cpu): Item(name,cost) {}
    virtual void print() const {
        cout<<"(Laptop name="<<I_name<<", Laptop price="<<I_price<<"); ";
    }
    virtual ~Laptop(){};
};

#endif /* LAPTOP_H */

