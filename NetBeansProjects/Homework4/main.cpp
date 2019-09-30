/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Admin
 *
 * Created on January 24, 2019, 7:03 PM
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Shape {
public:
    virtual unsigned computeArea() const =0; //pure virtual function
    int xLocation;
    int yLocation;
    string color;
    string printColor() {return color;}
    
};

class Square : public Shape {
public:
    Square(unsigned l): edgeLength(l) {}
    unsigned computeArea() const {return edgeLength*4;}
protected:
    unsigned edgeLength;
};

class Circle : public Shape {
public:
    Circle(unsigned r): radius(r) {}
    unsigned computeArea() const {return 3.14 * (radius*radius);}
protected:
    unsigned radius;
};




/*
 * 
 */
int main(int argc, char** argv) {
vector<Shape*> myShapes;
Circle* circ = new Circle(10);
circ->color = "red";
Circle* circ2 = new Circle(5);
circ2->color = "black";
Square* sq1 = new Square(5);
sq1->color = "white";
Square* sq2 = new Square(10);
sq2->color = "red";
Square* sq3 = new Square(20);
sq3->color = "white";
Square* sq4 = new Square(2);
sq4->color = "black";
myShapes.push_back(circ);
myShapes.push_back(circ2);
myShapes.push_back(sq1);
myShapes.push_back(sq2);
myShapes.push_back(sq3);
myShapes.push_back(sq4);
for(int i = 0; i<myShapes.size(); i++) {
    cout << myShapes[i]->computeArea() << endl;
    cout << myShapes[i]->printColor() << endl;
}
}
//Quick description: for loop goes through every shape and prints the area and color! Does compile and run correctly. 
//Het container is in the main function as described in video
//Circle class, Square class and Shape class all implemented correctly as instructed.
