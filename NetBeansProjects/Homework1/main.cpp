/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chris Nosowsky
 *
 * Created on January 10, 2019, 7:57 PM
 */

#include <cstdlib>
using namespace std;
#include <iostream>
#include "Car.h"
#define GASTYPE 87

void printGasTypePointer(const unsigned int* gasTypePtr) {
    cout << *gasTypePtr << endl;
}
bool yearEarlier(const Car& car1, const Car& car2) {
    return car1.getYear() < car2.getYear();
}
int main(int argc, char** argv) {
    const unsigned int gasType = 87;
    printGasTypePointer(&gasType); //passing by reference gasType const.
    
    const Car FordEscape("Ford","Escape", 2002, 22); //const objects
    const Car JeepGrandCherokee("Jeep", "Grand Cherokee", 2000, 18);
    cout << FordEscape.getCarMake();
    cout << JeepGrandCherokee.getGasMileage(); //const member functions being invoked onto const objects!
    cout << yearEarlier(FordEscape, JeepGrandCherokee);
    return 0;
}

