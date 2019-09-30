/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExpBuilder.h
 * Author: Admin
 *
 * Created on March 21, 2019, 3:10 PM
 */

#ifndef EXPBUILDER_H
#define EXPBUILDER_H
#include <stack>
#include <iostream>
#include <vector>
using namespace std;
class ExpBuilder: public Builder{
protected:
    stack<Node*> expStack;
public:
    virtual void addOperand(string operand){
        Node* newOperand = new Node(operand);
        expStack.push(newOperand);
    };
    
    virtual void addLiteral(string literal){
        Node* newOperand = new Node(literal);
        expStack.push(newOperand);
    };
    
    virtual void addLeftParenthesis(){};
    
    virtual void addRightParenthesis(){
        Node* rightChild = expStack.top();
        expStack.pop();
        Node* parent = expStack.top();
        expStack.pop();
        Node* leftChild = expStack.top();
        expStack.pop();
        parent->setLeftChild(leftChild);
        parent->setRightChild(rightChild);
        expStack.push(parent);
    };
    
    virtual Node* getExpression(){
        Node* root = expStack.top();
        expStack.pop();
        return root;
    };
};

#endif /* EXPBUILDER_H */

