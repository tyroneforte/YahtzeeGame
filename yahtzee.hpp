//
//  yahtzee.hpp
//  Yahtzee
//
//  Created by Tyrone Forte on 4/25/20.
//  Copyright © 2020 Tyrone. All rights reserved.
//

#ifndef yahtzee_hpp
#define yahtzee_hpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include <limits>
#include <ios>

class Player{
public:
    Player(){playerScore = 0; topScore = 0; aces = -1; twos = -1; threes = -1; fours = -1; fives = -1; sixes = -1; bonus = -1; threeKind = -1; fourKind = -1; fullHouse = -1; smStraight = -1; lrgStraight = -1; yahtzee = -1; chance = -1; bonus = -1; slotsFilled = 0; }
    int rollDice();
    void rollFiveDice();
    void showCurrentDice();
    void holdDice();
    void takeTurn();
    void reRoll();
    void selectScoreCard();
    void displayPlayerCard();
    void endGame();
    int displayPlayerScore();
private:
    int diceArray[5];
    int playerScore;
    int topScore;
    int aces;
    int twos;
    int threes;
    int fours;
    int fives;
    int sixes;
    int bonus;
    int threeKind;
    int fourKind;
    int fullHouse;
    int smStraight;
    int lrgStraight;
    int yahtzee;
    int chance;
    int slotsFilled;
};




#endif /* yahtzee_hpp */
