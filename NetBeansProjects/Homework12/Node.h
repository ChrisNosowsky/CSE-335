/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Admin
 *
 * Created on March 18, 2019, 8:54 PM
 */

#ifndef NODE_H
#define NODE_H
#include <string>
#include "Visitor.h"
class Node {
protected:
    int val;
    Node(int v): val(v){
    }
public:
    virtual ~Node(){};
    
    virtual int getVal() const {
        return val;
    }
    virtual void Accept(Visitor*) = 0;
};


#endif /* NODE_H */

