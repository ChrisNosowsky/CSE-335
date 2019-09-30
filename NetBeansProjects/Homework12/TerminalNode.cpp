/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TerminalNode.cpp
 * Author: Admin
 *
 * Created on March 18, 2019, 10:39 PM
 */

#include <cstdlib>
#include "TerminalNode.h"
using namespace std;

    void TerminalNode::addChild(Node* nd) {
       nodes.push_back(nd); 
       
    }
    
    void TerminalNode::Accept(Visitor* v) {
        v->VisitTerminalNode(this);
    }
