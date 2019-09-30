/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonTerminalNode.cpp
 * Author: Admin
 *
 * Created on March 18, 2019, 10:45 PM
 */

#include <cstdlib>
#include "NonTerminalNode.h"
using namespace std;

    void NonTerminalNode::addChild(Node* tn) {
        nodes.push_back(tn);
    }

    void NonTerminalNode::Accept(Visitor* v) {
        v->VisitNonTerminalNode(this);
    }

