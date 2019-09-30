/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chris Nosowsky
 *
 * Created on January 15, 2019, 5:57 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

class Car {
public:
    int publicgasLED;
protected:
    int protectedgasCHIP;
private:
    int privategasWIRE;
public:
   Car(int led, int chip, int wire):publicgasLED(led),protectedgasCHIP(chip),privategasWIRE(wire) {
   }
};
class ledDisplay: public Car{ //derived requirement 1 and 2
protected:
    int protectedLEDPixel;
public:
    int publicLEDValue;
    ledDisplay(int number, int chipchirp, int signal):Car(number, chipchirp, signal) {
    }
    void print() {
        cout<<publicgasLED<<endl; //req 1
        cout<<protectedgasCHIP<<endl; //req 2
        //cout<<privategasWIRE<<endl;//error:'int Car::privategasWIRE' is private
        //requirement 3 above
    }
};

class headLiner : public ledDisplay{ //further derive requirement 1 and 2
protected:
    int protectedHeadlinerPixel;
public:
    int publicHeadlinerValue;
    headLiner(int num, int chime, int sig):ledDisplay(num,chime,sig){
    }
    void print() {
        cout<<publicgasLED<<endl; //req 1
        cout<<protectedgasCHIP<<endl; //req 2
        //cout<<privategasWIRE<<endl;//error:'int Car::privategasWIRE' is private
    }
};

class CHIPFunction: protected Car { //for req 4
protected:
    int protectedCHIPBits;
public:
    CHIPFunction(int chipFreq, int chipReading, int chipWave):Car(chipFreq,chipReading,chipWave) {
        
    }
    void print() {
        cout<<publicgasLED<<endl; //req4
        cout<<protectedgasCHIP<<endl; //req 4
        //cout<<privategasWIRE<<endl;//error:'int Car::privategasWIRE' is private
        //req 5 above
    }
};

class CHIPCode: protected CHIPFunction { //for req 4
protected:
    int protectedCHIPLang;
public:
    CHIPCode(int chipHertz, int chipLines, int chipTemp):CHIPFunction(chipHertz,chipLines,chipTemp) {
        
    }
    void print() {
        cout<<publicgasLED<<endl; //req4
        cout<<protectedgasCHIP<<endl; //req 4
        //cout<<privategasWIRE<<endl;//error:'int Car::privategasWIRE' is private
        //req 5 above
    }
};

class WireHarness: private Car { //for req 6
private:
    int privateWiring;
public:
    WireHarness(int wire1, int wire2, int wire3):Car(wire1,wire2,wire3) {
        
    }
    void print() {
        cout<<publicgasLED<<endl; //req 6
        cout<<protectedgasCHIP<<endl; //req 6
        //cout<<privategasWIRE<<endl;//error:'int Car::privategasWIRE' is private
        //req 7 above
    }
};

class WireDiagram: private WireHarness { //for req 6
private:
    int privateWires;
public:
    WireDiagram(int redWire, int blackWire, int yellowWire):WireHarness(redWire,blackWire,yellowWire) {
        
    }
    void print() {
        //cout<<publicgasLED<<endl; //error: 'int Car::publicgasLED' is inaccessible within this context
        //cout<<protectedgasCHIP<<endl; //error: 'int Car::protectedgasCHIP' is protected within this context
        //req 6
        //cout<<privategasWIRE<<endl;//error:'int Car::privategasWIRE' is private
        //req 7 above
    }
};
/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}

