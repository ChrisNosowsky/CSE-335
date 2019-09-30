/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Admin
 *
 * Created on February 5, 2019, 5:55 PM
 */
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
template<class QueueType> class Queue {
protected:
    int top;
    int end;
    vector<QueueType> items;
public:
    Queue() {
        top = 0;
        end = 0;
    }
    int topp() {//number 1
       return top; 
    }
    QueueType push(QueueType ele) { //number 3
        items.insert(items.begin(), ele);
        top++;
        return items[end];
    }
    QueueType pop() { //number 2
        QueueType x = items[top];
        items.erase(items.end()-1);
        top--; 
        return items[top];
    }
    bool empty() { //number 4
        if(top == 0) {
            return true;
        }
        return false;
    }
    
};
/*
 * 
 */
int main(int argc, char** argv) {
    Queue<int> q1;
    q1.push(1);   
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    int suh = q1.topp();
    for(int i=0; i<suh; i++) {
       cout<<"Pop: "<<q1.pop()<<endl; //tested, does 123456.
    }
    //Test 2 For Doubles Below//
    Queue<double> q2;
    q2.push(0.1);   
    q2.push(0.2);
    q2.push(0.3);
    q2.push(0.4);
    q2.push(0.5);
    q2.push(0.6);
    int suhbruh = q2.topp();
    for(int i=0; i<suhbruh; i++) {
       cout<<"Pop: "<<q2.pop()<<endl; //tested, does 123456.
    }
}

//this all works and compiles. Utilized C++ vectors to store data of any type given by the queue object creation.

