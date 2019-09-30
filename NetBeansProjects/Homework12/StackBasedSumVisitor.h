/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackBasedSumVisitor.h
 * Author: Admin
 *
 * Created on March 18, 2019, 7:15 PM
 */

#ifndef STACKBASEDSUMVISITOR_H
#define STACKBASEDSUMVISITOR_H
#include "Visitor.h"
#include "TerminalNode.h"
#include "NonTerminalNode.h"
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class StackBasedSumVisitor: public Visitor {
public:
    stack<int> m_stack;
public:
    StackBasedSumVisitor() {};
    virtual ~StackBasedSumVisitor() {};   
    virtual void VisitTerminalNode(TerminalNode* tn);
    virtual void VisitNonTerminalNode (NonTerminalNode* ntn);
    int getResult();
private:
    StackBasedSumVisitor(const StackBasedSumVisitor& orig){};    
};


#endif /* STACKBASEDSUMVISITOR_H */

