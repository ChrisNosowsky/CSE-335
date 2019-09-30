/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: Admin
 *
 * Created on February 20, 2019, 2:36 PM
 */

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;
class Character {
protected:
    string c_name;
    string c_size;
    string c_weight;
    string c_speed;
    string c_hair;
    string c_race;
public:
    void print() const {
        cout << left;
        cout << setw(20) << "Name: " + c_name;
        cout << setw(15) << "Size: " + c_size;
        cout << setw(20) << "Weight: " + c_weight;
        cout << setw(20) << "Speed: " + c_speed;
        cout << setw(20) << "HairLen: " + c_hair;
        cout << setw(20) << "Race: " + c_race;
        cout << setw(20) << getSpecial() << endl;
    }
    virtual string getSpecial() const = 0;
    string getName() const {
      return c_name;  
    } 
    string getRace() const {
       return c_race; 
    }
    string getHair() const {
       return c_hair;
    }
    string getSpeed() const {
        return c_speed;
    }
    void setName(string name){
        c_name = name;
    }
    void setSize(string size){
        c_size = size;
    }
    void setWeight(string weight){
        c_weight = weight;
    }
    void setSpeed(string speed){
        c_speed = speed;
    }
    void setHair(string hair){
        c_hair = hair;
    }
    void setRace(string race){
        c_race = race;
    }
    virtual void setSpecial(string s) = 0;
    
};

class Small : public Character {
protected:
    bool c_equip;
public:
    virtual string getSpecial() const {
        if (c_equip == true) {
            return "IsEquipped: 1";
        }
        return "IsEquipped: 0";
    }
    virtual void setSpecial(string s){
        if(s == "TRUE")
            c_equip = true;
        else
            c_equip = false;
    }
};

class Medium : public Character {
protected:
    string c_weapon;
public:
    virtual string getSpecial() const {
        return "Weapon: " + c_weapon;
    }
    virtual void setSpecial(string s){
        c_weapon = s;
    }
};

class Big : public Character {
protected:
    string c_skill;
public: 
    virtual string getSpecial() const {
        return "Skill: " + c_skill;
    }
    virtual void setSpecial(string s){
        c_skill = s;
    }
};

#endif /* CHARACTER_H */

