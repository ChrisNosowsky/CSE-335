/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonTerminalNode.h
 * Author: Admin
 *
 * Created on March 18, 2019, 7:12 PM
 */

#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H
#include <string>
#include <vector>
#include "Visitor.h"
#include "Node.h"
using namespace std;
class NonTerminalNode: public Node {
public:
    int val;
    vector<Node*> nodes;
    NonTerminalNode(int v): Node(v) {
        val = v;
    }
public:
    virtual ~NonTerminalNode(){};
    virtual void addChild(Node* tn);
    virtual Node* getChild(int i) const {return nodes[i];}
    virtual unsigned int getChildrenSize() const {return nodes.size();}
    virtual int getVal() const {return val;}
    virtual void Accept(Visitor* v);
};


#endif /* NONTERMINALNODE_H */

