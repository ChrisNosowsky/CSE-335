/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonTerminalNode.h
 * Author: Admin
 *
 * Created on March 21, 2019, 3:24 PM
 */

#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H
#include <string>
#include <vector>
#include "Visitor.h"
#include "Node.h"
class NonTerminalNode: public Node {
public:
    Node* val;
    vector<Node*> nodes;
    NonTerminalNode(Node* v): Node(v) {
        val = v;
    }
public:
    virtual ~NonTerminalNode(){};
    virtual void addChild(Node* tn);
    virtual Node* getChild(int i) const {return nodes[i];}
    virtual unsigned int getChildrenSize() const {return nodes.size();}
    virtual Node* getVal() const {return val;}
    virtual void Accept(Visitor* v);
};


#endif /* NONTERMINALNODE_H */

