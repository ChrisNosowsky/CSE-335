/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TerminalNode.h
 * Author: Admin
 *
 * Created on March 18, 2019, 7:14 PM
 */

#ifndef TERMINALNODE_H
#define TERMINALNODE_H
#include <string>
#include <vector>
#include "Visitor.h"
#include "Node.h"
using namespace std;
class TerminalNode: public Node {
public:
    vector<Node*> nodes;
    int val;
    TerminalNode(int v): Node(v) {
        val = v;
    }
public:
    virtual ~TerminalNode(){};   
    virtual void addChild(Node* nd);
    virtual Node* getChild(int i) const {return nodes[i];}
    virtual unsigned int getChildrenSize() const {return nodes.size();}
    virtual int getVal() const {return val;}
    virtual void Accept(Visitor* v);
    
};


#endif /* TERMINALNODE_H */

