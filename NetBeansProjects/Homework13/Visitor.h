/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visitor.h
 * Author: Admin
 *
 * Created on March 21, 2019, 3:22 PM
 */

#ifndef VISITOR_H
#define VISITOR_H
class TerminalNode;
class NonTerminalNode;
using namespace std;
class Visitor{
public:
    Visitor(){};
    virtual ~Visitor(){};
    virtual void VisitTerminalNode(TerminalNode*)=0;
    virtual void VisitNonTerminalNode(NonTerminalNode*)=0;    
};


#endif /* VISITOR_H */

