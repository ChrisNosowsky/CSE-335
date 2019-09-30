/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonStackBasedSumVisitor.h
 * Author: Admin
 *
 * Created on March 18, 2019, 7:13 PM
 */

#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H
using namespace std;
#include "TerminalNode.h"
class NonStackBasedSumVisitor: public Visitor{
protected:
    unsigned int sum;
public:
    NonStackBasedSumVisitor(){
        sum=0;
    };
    virtual ~NonStackBasedSumVisitor(){};
    virtual void VisitTerminalNode(TerminalNode* tn); 
    virtual void VisitNonTerminalNode(NonTerminalNode* ntn);     
    int getResult();
    
private:
    NonStackBasedSumVisitor(const NonStackBasedSumVisitor& orig){};    
};


#endif /* NONSTACKBASEDSUMVISITOR_H */

