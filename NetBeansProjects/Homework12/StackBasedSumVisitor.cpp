/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackBasedSumVisitor.cpp
 * Author: Admin
 *
 * Created on March 18, 2019, 10:22 PM
 */

#include <cstdlib>
#include "StackBasedSumVisitor.h"
#include "TerminalNode.h"
#include "NonTerminalNode.h"
using namespace std;

    void StackBasedSumVisitor::VisitTerminalNode(TerminalNode* tn) {
        unsigned int sum = tn->getVal(); 
        //Visit every children, store state information in m_stack.
        for(int i=0; i< tn->getChildrenSize(); i++){
            tn->getChild(i)->Accept(this);
        }
        //Get state information from m_stack, do calculation.
        for( int i=0; i<tn->getChildrenSize(); i++ ){
            sum += m_stack.top();
            m_stack.pop();
        }
        m_stack.push(sum);
        
    }
    void StackBasedSumVisitor::VisitNonTerminalNode (NonTerminalNode* ntn) {
        unsigned int sum = ntn->getVal(); 
        //Visit every children, store state information in m_stack.
        for(int i=0; i< ntn->getChildrenSize(); i++){
            ntn->getChild(i)->Accept(this);
        }
        //Get state information from m_stack, do calculation.
        for( int i=0; i<ntn->getChildrenSize(); i++ ){
            sum += m_stack.top();
            m_stack.pop();
        }
        m_stack.push(sum);
        
    }
    int StackBasedSumVisitor::getResult() {
        unsigned int result = m_stack.top();
        m_stack.pop();

        return result;
    } 
