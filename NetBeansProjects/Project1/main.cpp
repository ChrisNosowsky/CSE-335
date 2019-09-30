/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Admin
 *
 * Created on February 20, 2019, 2:36 PM
 */
using namespace std;
#include <cstdlib>
#include "Game.h"

/*
 * 
 */
int main(int argc, char** argv) 
{   
    
    Game game = Game("sisters.txt");
    
    game.getCharacters();
    
    game.getCharactersByRace();
    
    game.getCharactersBySpeed();

    game.getCharactersByHair();
    
    game.getCharacters();
    
    return 0;
}

