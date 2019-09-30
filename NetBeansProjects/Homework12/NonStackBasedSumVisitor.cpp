/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonStackBasedSumVisitor.cpp
 * Author: Admin
 *
 * Created on March 18, 2019, 10:16 PM
 */

#include <cstdlib>
#include "NonStackBasedSumVisitor.h"
#include "TerminalNode.h"
#include "NonTerminalNode.h"
using namespace std;

    void NonStackBasedSumVisitor::VisitTerminalNode(TerminalNode* tn){
        sum+=tn->getVal();
        for(int i=0; i< tn->getChildrenSize(); i++){
            tn->getChild(i)->Accept(this);
        }
    }
    
    void NonStackBasedSumVisitor::VisitNonTerminalNode(NonTerminalNode* ntn){
        sum += ntn->getVal(); 	
        for(int i=0; i< ntn->getChildrenSize(); i++){
            ntn->getChild(i)->Accept(this);
        }
    };
        
    int NonStackBasedSumVisitor::getResult() {
        unsigned int result =sum;
        sum=0;
        return result;
    }

