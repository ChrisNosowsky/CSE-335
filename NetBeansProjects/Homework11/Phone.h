/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Phone.h
 * Author: Admin
 *
 * Created on March 13, 2019, 1:29 PM
 */
#include "Item.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#ifndef PHONE_H
#define PHONE_H

class Phone: public Item {
public:
    Phone(string name, unsigned int cost, int year):Item(name,cost){}
    virtual void print() const {
        cout<<"(Phone name="<<I_name<<", Phone price="<<I_price<<"); ";
    }
    virtual ~Phone(){}
};

#endif /* PHONE_H */

