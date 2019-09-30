/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharacterFactory.h
 * Author: Admin
 *
 * Created on February 20, 2019, 2:36 PM
 */

#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H
#include <iostream>
#include <string>

using namespace std;

#include "Character.h"

string remove_space(string s){
    for(int i = 0; i < s.length(); i++){
        if(isalnum(s[i]))
            return s.substr(i, s.length());
    }
    return "";
}
class CharacterFactory {
public:
    virtual Character* createCharacter() const = 0;
    void setAttributes(Character* chr, string s){
        string name = s.substr(0, s.find("\t"));
        
        s = remove_space(s.substr(name.length(), s.length()));
        string size = s.substr(0,s.find("\t"));
        
        s = remove_space(s.substr(size.length(), s.length()));
        string weight = s.substr(0,s.find("\t"));
        
        s = remove_space(s.substr(weight.length(), s.length()));
        string speed = s.substr(0,s.find("\t"));
        
        s = remove_space(s.substr(speed.length(), s.length()));
        string hairlen = s.substr(0,s.find("\t")); 
       
        s = remove_space(s.substr(hairlen.length(), s.length()));
        string race = s.substr(0,s.find("\t"));
        
        s = remove_space(s.substr(race.length(), s.length()));
        string special = s;
        
        chr->setName(name);
        chr->setSize(size);
        chr->setWeight(weight);
        chr->setSpeed(speed);
        chr->setHair(hairlen);
        chr->setRace(race);
        chr->setSpecial(special);
    }
};

class BigCreate : public CharacterFactory {
public:
    virtual Character* createCharacter() const {
        return new Big();
    }
};
class MedCreate : public CharacterFactory {
public:
    virtual Character* createCharacter() const {
        return new Medium();
    }
};
class SmallCreate : public CharacterFactory {
public:
    virtual Character* createCharacter() const {
        return new Small();
    }
};
#endif /* CHARACTERFACTORY_H */