/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Admin
 *
 * Created on January 27, 2019, 11:28 PM
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Shape {
protected:
    int xLocation;
    int yLocation;   
    string name;
public:   
    Shape() { //default constructor
        name = "Default Shape";
        cout<<"In Shape Default Constructor"<<endl;
    };
    Shape(const int& xLoc, const int& yLoc, const string& c) { //parameter constructor
        xLocation = xLoc;
        yLocation = yLoc;
        name = c;
        cout <<"In Shape Constructor: "<<name<<endl;
    };
    virtual ~Shape(){
        cout<<"In Shape Destructor: "<<name << endl;
    }
    Shape(const Shape& shape){
        if(this!=&shape){
            xLocation = shape.xLocation;
            yLocation = shape.yLocation;
            name = shape.name;
            cout << "In Shape Copy Constructor: "<<name<<endl;
        }
        else cout<<"In Shape Copy Constructor: Self-copying"<<endl;
    }
    Shape& operator=(const Shape& shape) {
        if(this!= &shape) {
            xLocation = shape.xLocation;
            yLocation = shape.yLocation;
            name = shape.name;
        }
        return *this;
    }
    virtual unsigned computeArea() const =0; //pure virtual function
    string printName() {return name;}
    
};

class Square : public Shape {
public:
    Square() { //def const
      name = "Default Square";
      cout<<"In Square Default Constructor" <<endl;  
    };
    Square(const int& xLoc, const int& yLoc, const string& c, const unsigned& edgeL):Shape(xLoc,yLoc,c) {
        edgeLength = edgeL;
        cout<<"In Square Constructor: "<<name<<endl;
    };
    virtual ~Square(){
        cout<<"In Square Destructor: " <<name<< endl;
    }
    Square(const Square& square){
        if(this!=&square){
            xLocation = square.xLocation;
            yLocation = square.yLocation;
            name = square.name;
            edgeLength = square.edgeLength;
            cout << "In Square Copy Constructor: "<<name<<endl;
        }
        else cout<<"In Square Copy Constructor: Self-copying"<<endl;
    }
    Square& operator=(const Square& square) {
        if(this!= &square) {
            xLocation = square.xLocation;
            yLocation = square.yLocation;
            name = square.name;
            edgeLength = square.edgeLength;
        }
        return *this;
    }    
    unsigned computeArea() const {return edgeLength*4;}
protected:
    unsigned edgeLength;
};

class Circle : public Shape {
public:
    Circle() { //def const
      name = "Default Circle";
      cout<<"In Circle Default Constructor"<<endl;  
    };
    Circle(const int& xLoc, const int& yLoc, const string& c, const unsigned& r):Shape(xLoc,yLoc,c) {
        radius = r;
        cout<<"In Circle Constructor: "<<name<<endl;
    };
    virtual ~Circle(){
        cout<<"In Circle Destructor: "<<name << endl;
    }
    Circle(const Circle& circle){
        if(this!=&circle){
            xLocation = circle.xLocation;
            yLocation = circle.yLocation;
            name = circle.name;
            radius = circle.radius;
            cout << "In Circle Copy Constructor: "<<name<<endl;
        }
        else cout<<"In Circle Copy Constructor: Self-copying"<<endl;
    }
    Circle& operator=(const Circle& circle) {
        if(this!= &circle) {
            xLocation = circle.xLocation;
            yLocation = circle.yLocation;
            name = circle.name;
            radius = circle.radius;
        }
        return *this;
    }   
    unsigned computeArea() const {return 3.14 * (radius*radius);}
protected:
    unsigned radius;
};



/*
 * 
 */
int main(int argc, char** argv) {
    {Square sq1;} //req 8
    Square *sq2 = new Square(2,2,"Square 2",5);
    Circle cir1;
    Circle *circ2 = new Circle(3,6,"Circle 2",6);
    delete sq2; //req 7
    delete circ2;
    
}