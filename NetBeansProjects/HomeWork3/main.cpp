/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Admin
 *
 * Created on January 19, 2019, 10:13 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Dequeue {
public:
    int maxsize = 10;
    int totalsize = 0;
    string getL() const {return topmost;}
    string getR() const {return backmost;}
protected:
    string topmost = "";
    string backmost = "";
    int topindex = 0; //always 0 index
    int backindex = 0;
public:
    void insertL(string s, vector<string> &v) {
            v.insert(v.begin(), s);
            backindex +=1;
            topmost = v[topindex];
            totalsize++;
}
    void insertR(string s, vector<string> &v) {
            v.push_back(s);
            backindex+=1;
            backmost = v[backindex-1]; //essentially v.end() -1
            totalsize++;
    }
    string removeL(vector<string> &v) {
        string removed = v[topindex];
        v.erase(v.begin());
        backindex--;
        topmost = v[topindex];
        backmost = v[backindex];
        totalsize--;
        return removed;
    }
    string removeR(vector<string> &v) {
        string removed = v[backindex-1];
        v.erase(v.end());
        backindex--;
        backmost = v[backindex];
        totalsize--;
        return removed;
        
    }
};

class Stack: private Dequeue { //req2
public:
    void push(string x,vector<string> &v) {insertL(x,v);}; //calling this only allows for insertion on left
    string pop(vector<string>&v) { return removeL(v);}; //calling this only allows removing from left
    string top() {return topmost;};
};

class Queue { //req 3
private:
    Dequeue dq;
public:
    void push(string x,vector<string> &v) {dq.insertL(x,v);};
    string pop(vector<string>&v) { return dq.removeR(v);};
    bool full() {return dq.maxsize == dq.totalsize;};
};


/*
 * 
 */
int main(int argc, char** argv) {
    vector<string> v;
    Dequeue d;
    d.insertL("string1",v);
    d.insertL("string2",v);
    d.insertL("string3",v);
    d.insertL("string4",v);
    d.insertL("string5",v);
    d.insertR("string6",v);
    d.insertR("string7",v);
    d.insertR("string8",v);
    //cout << v[7];
    for(int i = d.totalsize; i > 0; i--) { //req 4.1
        cout << d.removeL(v) << endl;
    }
    vector<string> v2;
    Stack s;
    s.push("string100",v2);
    s.push("string200",v2);
    s.push("string300",v2);
    s.push("string400",v2);
    vector<string> v3 = v2;
    for(auto it = v3.begin(); it != v3.end(); it++) { //req4.2
        cout << s.pop(v2) << endl;
    }
    vector<string> v4;
    Queue q;
    q.push("string10",v4);
    q.push("string20",v4);
    q.push("string30",v4);
    q.push("string40",v4);
    vector<string> v5 =v4;
    for(auto it = v5.begin(); it != v5.end(); it++) { //req4.3
        cout << q.pop(v4) << endl;
    }
}

//NOTE READ THIS: I hit run, they all compile and print in desired order. I added endl's to make it easier to read.