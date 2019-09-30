/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Admin
 *
 * Created on February 20, 2019, 2:36 PM
 */

#ifndef GAME_H
#define GAME_H
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "CharacterFactory.h"
using namespace std;


bool getName(Character* chr, Character* chr2){
    return (chr->getName() < chr2->getName());
}
bool getHair(Character* chr, Character* chr2){
    return (stod(chr->getHair()) < stod(chr2->getHair()));
}
bool getSpeed(Character* chr, Character* chr2){
    return (stod(chr->getSpeed()) < stod(chr2->getSpeed()));
}
bool getRace(Character* chr, Character* chr2){
    return (chr->getRace() < chr2->getRace());
}

class Game {
protected:
    string doc_text;
    vector<Character*> chr;
public:
    Game(string txt) {
        doc_text = txt;
        createSisters();
    }
    void createSisters() {
        ifstream fs("sisters.txt");
        string line;
        BigCreate bigClass = BigCreate();
        MedCreate medClass = MedCreate();
        SmallCreate smallClass = SmallCreate();
        Character* newChar;
        while(getline(fs,line)) {
            if(line.find("big") != std::string::npos) {
                newChar = bigClass.createCharacter();
                bigClass.setAttributes(newChar, line);
                chr.push_back(newChar);
            }
            else if(line.find("med") != std::string::npos) {
                newChar = medClass.createCharacter();
                bigClass.setAttributes(newChar, line);
                chr.push_back(newChar);
            }
            else {
                newChar = smallClass.createCharacter();
                bigClass.setAttributes(newChar, line);
                chr.push_back(newChar);
            }
        }
    }
    void printSisters() const {
        for(int i = 0; i < chr.size(); i++) {
            chr[i]->print();
        }
        cout << "************ **************** ************" << endl;
    }
    void getCharacters() { //print characters by name
       cout << "************ Printing Sisters ************" << endl;
       sort(chr.begin(),chr.end(),getName); 
       printSisters();
    }
    void getCharactersByRace() { //print characters by race
      cout << "************ Printing Sisters: Order by Race ************" << endl;
      sort(chr.begin(),chr.end(),getRace);  
      printSisters();
    }
    void getCharactersByHair() { //print characters by hair
      cout << "************ Printing Sisters: Order by Hair ************" << endl;
      sort(chr.begin(),chr.end(),getHair);  
      printSisters();
    }
    void getCharactersBySpeed() { //print characters by speed
      cout << "************ Printing Sisters: Order by Speed ************" << endl;
      sort(chr.begin(),chr.end(),getSpeed);
      printSisters();
    }
};


#endif /* GAME_H */

