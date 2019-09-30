/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bundle.h
 * Author: Admin
 *
 * Created on March 13, 2019, 1:29 PM
 */
using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include "Item.h"
#ifndef BUNDLE_H
#define BUNDLE_H

class Bundle: public Item{
protected:
    vector<Item*> entries;
    double d;
public:
    Bundle(string name, double discount):Item(name,2480){
        d = discount;
    }
    
    virtual ~Bundle(){
        for(int i=0; i<entries.size(); i++) delete entries[i];
    }

    virtual void addItem(Item* entry){
        entries.push_back(entry);
    }
    virtual unsigned int getBundlePrice() const{
        int sum = 0;
        for(int i=0; i<entries.size(); i++){
            sum += entries[i]->getPrice();
        }
        return sum;
    }
    virtual void print() const{
        int total = 0;
        cout<<"Bundle "<<I_name<<" contains: (";
        for(int i=0; i<entries.size(); i++){
            entries[i]->print();
        }
        cout<<" ; Bundle Price="<< getBundlePrice() * d <<");";
    }
};

#endif /* BUNDLE_H */

