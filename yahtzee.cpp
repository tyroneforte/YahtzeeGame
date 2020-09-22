//
//  yahtzee.cpp
//  Yahtzee
//
//  Created by Tyrone Forte on 4/25/20.
//  Copyright © 2020 Tyrone. All rights reserved.
//

#include "yahtzee.hpp"





int Player::rollDice(){
    int result = (rand()%6) +1;
    return result;
}

void Player::rollFiveDice(){
    for (int i = 0; i < 5; i++){
        
        diceArray[i] = rollDice();
    }
}

void Player::reRoll(){
    for (int i = 0; i < 5; i++){
        if (diceArray[i] == 0){
           diceArray[i] = rollDice();
        }
    }
}
    
void Player::showCurrentDice(){
    
    std::cout << "Your current dice: " << std::endl;
    for(int i = 0; i < 5; i++){
        char ch{'a'};
        std::cout << static_cast<char>(ch+i) <<". " << diceArray[i] << std::endl;
    }
}

void Player::holdDice(){
    std::string heldDice;
    std::cout<< "Type the corresponding letter(s) for the dice you want to hold" << std::endl;
    std::cin>>heldDice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    if ((heldDice.find("a", 0, 1))== -1){
        diceArray[0] = 0;
    }
    if ((heldDice.find("b", 0, 1))== -1){
        diceArray[1] = 0;
    }
    if ((heldDice.find("c", 0, 1))== -1){
        diceArray[2] = 0;
    }
    if ((heldDice.find("d", 0, 1))== -1){
        diceArray[3] = 0;
    }
    if ((heldDice.find("e", 0, 1))== -1){
        diceArray[4] = 0;
    }
    reRoll();
    
}

int Player::displayPlayerScore(){
    return playerScore;
}

void Player::endGame(){
    std::cout << "Thanks for playing!" << std::endl;
    displayPlayerCard();
}

void Player::takeTurn(){
    while (slotsFilled < 13){
        

    int rollsRemaining = 2;
    int playerChoice = 0;
    
    rollFiveDice();
    std::cout << "" <<std::endl;
    showCurrentDice();
    std::cout << "" <<std::endl;
        
    
    
    while (rollsRemaining > 0){
    rollsRemaining--;
    displayPlayerCard();
    std::cout << "Number of rolls left = " << rollsRemaining + 1 <<std::endl;
    std::cout << "What do you want to do?" <<std::endl;
    std::cout<< "1. Hold Dice and reroll" << std::endl;
    std::cout<< "2. Reroll all dice" << std::endl;
    std::cout<< "3. End turn and select scorecard" << std::endl;
    //std::cout<< "4. Show score" << std::endl;
    //std::cout<< "5. Show scorecard" << std::endl;
    std::cin >>playerChoice;
        
        switch(playerChoice){
            case 1:
                holdDice();
                showCurrentDice();
                break;
            case 2:
                rollFiveDice();
                showCurrentDice();
                break;
            case 3:
                rollsRemaining = 0;
                break;
                /*
            case 4:
                std::cout <<"Your score is: " << displayPlayerScore() << std::endl;
                rollsRemaining++;
                break;
            case 5:
                displayPlayerCard();
                rollsRemaining++;
                break;*/
            default:
                std::cout << "Please pick a valid option" << std::endl;
                rollsRemaining++;
        }
    }
    
    if (rollsRemaining == 0){
        std::cout << "Number of rolls left = " << 0 <<std::endl;
        displayPlayerCard();
        std::cout << "Choose category to score (type in letter): " <<std::endl;
        
        char category;
        
        bool valid = false;
        
        while(valid == false){
            std::cin >>category;
            switch(category){
                case 'a':
                    if(aces == -1){
                        aces = 0;
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 1){
                                aces++;
                            }
                        }
                        playerScore = playerScore + aces;
                        topScore = topScore + aces;
                        slotsFilled++;
                        valid = true;
                        if(topScore >= 63 && bonus == -1){
                            bonus = 35;
                            topScore = topScore + bonus;
                        }
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'b':
                    if(twos == -1){
                        twos = 0;
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 2){
                                twos = twos + 2;
                            }
                        }
                        playerScore = playerScore + twos;
                        topScore = topScore + twos;
                        slotsFilled++;
                        valid = true;
                        if(topScore >= 63 && bonus == -1){
                            bonus = 35;
                            topScore = topScore + bonus;
                        }
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'c':
                    if(threes == -1){
                        threes = 0;
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 3){
                                threes = threes + 3;
                            }
                        }
                        playerScore = playerScore + threes;
                        topScore = topScore + threes;
                        slotsFilled++;
                        valid = true;
                        if(topScore >= 63 && bonus == -1){
                            bonus = 35;
                            topScore = topScore + bonus;
                        }
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'd':
                    if(fours == -1){
                        fours = 0;
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 4){
                                fours = fours + 4;
                            }
                        }
                        playerScore = playerScore + fours;
                        topScore = topScore + fours;
                        slotsFilled++;
                        valid = true;
                        if(topScore >= 63 && bonus == -1){
                            bonus = 35;
                            topScore = topScore + bonus;
                        }
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'e':
                    if(fives == -1){
                        fives = 0;
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 5){
                                fives = fives + 5;
                            }
                        }
                        playerScore = playerScore + fives;
                        topScore = topScore + fives;
                        slotsFilled++;
                        valid = true;
                        if(topScore >= 63 && bonus == -1){
                            bonus = 35;
                            topScore = topScore + bonus;
                        }
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'f':
                    if(sixes == -1){
                        sixes = 0;
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 6){
                                sixes = sixes + 6;
                            }
                        }
                        playerScore = playerScore + sixes;
                        topScore = topScore + sixes;
                        slotsFilled++;
                        valid = true;
                        if(topScore >= 63 && bonus == -1){
                            bonus = 35;
                            topScore = topScore + bonus;
                        }
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'g':
                    if(threeKind == -1){
                            threeKind = 0;
                            int oneCount = 0;
                            int twoCount = 0;
                            int threeCount = 0;
                            int fourCount = 0;
                            int fiveCount = 0;
                            int sixCount = 0;
                        
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 1){oneCount++;}
                            if(diceArray[i] == 2){twoCount++;}
                            if(diceArray[i] == 3){threeCount++;}
                            if(diceArray[i] == 4){fourCount++;}
                            if(diceArray[i] == 5){fiveCount++;}
                            if(diceArray[i] == 6){sixCount++;}
                        }
                        if(oneCount > 2 || twoCount > 2 || threeCount > 2 || fourCount > 2 || fiveCount > 2 || sixCount > 2){
                            for(int i = 0; i < 5; i++){
                                threeKind = threeKind + diceArray[i];
                            }
                        }
                        playerScore = playerScore + threeKind;
                        slotsFilled++;
                        valid = true;
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'h':
                    if(fourKind == -1){
                        fourKind = 0;
                        int oneCount = 0;
                        int twoCount = 0;
                        int threeCount = 0;
                        int fourCount = 0;
                        int fiveCount = 0;
                        int sixCount = 0;
                        
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 1){oneCount++;}
                            if(diceArray[i] == 2){twoCount++;}
                            if(diceArray[i] == 3){threeCount++;}
                            if(diceArray[i] == 4){fourCount++;}
                            if(diceArray[i] == 5){fiveCount++;}
                            if(diceArray[i] == 6){sixCount++;}
                        }
                        if(oneCount > 3 || twoCount > 3 || threeCount > 3 || fourCount > 3 || fiveCount > 3 || sixCount > 3){
                            for(int i = 0; i < 5; i++){
                                fourKind = fourKind + diceArray[i];
                            }
                        }
                        playerScore = playerScore + fourKind;
                        slotsFilled++;
                        valid = true;
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'i':
                    if(fullHouse == -1){
                        fullHouse = 0;
                        int oneCount = 0;
                        int twoCount = 0;
                        int threeCount = 0;
                        int fourCount = 0;
                        int fiveCount = 0;
                        int sixCount = 0;
                        
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 1){oneCount++;}
                            if(diceArray[i] == 2){twoCount++;}
                            if(diceArray[i] == 3){threeCount++;}
                            if(diceArray[i] == 4){fourCount++;}
                            if(diceArray[i] == 5){fiveCount++;}
                            if(diceArray[i] == 6){sixCount++;}
                        }
                    if((oneCount == 2 || twoCount == 2 || threeCount == 2 || fourCount == 2 || fiveCount == 2 || sixCount == 2) && (oneCount == 3 || twoCount == 3 || threeCount == 3 || fourCount == 3 || fiveCount == 3 || sixCount == 3))
                        {
                            fullHouse = 25;
                        }
                        playerScore = playerScore + fullHouse;
                        slotsFilled++;
                        valid = true;
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'j':
                    if(smStraight == -1){
                        smStraight = 0;
                        int oneCount = 0;
                        int twoCount = 0;
                        int threeCount = 0;
                        int fourCount = 0;
                        int fiveCount = 0;
                        int sixCount = 0;
                        
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 1){oneCount++;}
                            if(diceArray[i] == 2){twoCount++;}
                            if(diceArray[i] == 3){threeCount++;}
                            if(diceArray[i] == 4){fourCount++;}
                            if(diceArray[i] == 5){fiveCount++;}
                            if(diceArray[i] == 6){sixCount++;}
                        }
                        if((oneCount >= 1 && twoCount >= 1 && threeCount >= 1 && fourCount >= 1) || (twoCount >= 1 && threeCount >= 1 && fourCount >= 1 && fiveCount >= 1)||(threeCount >= 1 && fourCount >= 1 && fiveCount >= 1 && sixCount >= 1))
                        {
                            smStraight = 30;
                        }
                        playerScore = playerScore + smStraight;
                        slotsFilled++;
                        valid = true;
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'k':
                    if(lrgStraight == -1){
                        lrgStraight = 0;
                        int oneCount = 0;
                        int twoCount = 0;
                        int threeCount = 0;
                        int fourCount = 0;
                        int fiveCount = 0;
                        int sixCount = 0;
                        
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 1){oneCount++;}
                            if(diceArray[i] == 2){twoCount++;}
                            if(diceArray[i] == 3){threeCount++;}
                            if(diceArray[i] == 4){fourCount++;}
                            if(diceArray[i] == 5){fiveCount++;}
                            if(diceArray[i] == 6){sixCount++;}
                        }
                        if((oneCount == 1 && twoCount == 1 && threeCount == 1 && fourCount == 1 && fiveCount == 1) || (twoCount == 1 && threeCount == 1 && fourCount == 1 && fiveCount == 1 && sixCount == 1))
                        {
                            lrgStraight = 40;
                        }
                        playerScore = playerScore + lrgStraight;
                        slotsFilled++;
                        valid = true;
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'l':
                    if(yahtzee == -1){
                        yahtzee = 0;
                        int oneCount = 0;
                        int twoCount = 0;
                        int threeCount = 0;
                        int fourCount = 0;
                        int fiveCount = 0;
                        int sixCount = 0;
                        
                        for (int i = 0; i < 5; i++){
                            if(diceArray[i] == 1){oneCount++;}
                            if(diceArray[i] == 2){twoCount++;}
                            if(diceArray[i] == 3){threeCount++;}
                            if(diceArray[i] == 4){fourCount++;}
                            if(diceArray[i] == 5){fiveCount++;}
                            if(diceArray[i] == 6){sixCount++;}
                        }
                        if(oneCount == 5 || twoCount == 5 || threeCount == 5 || fourCount == 5 || fiveCount == 5 || sixCount == 5)
                        {
                            yahtzee = 50;
                        }
                        playerScore = playerScore + yahtzee;
                        slotsFilled++;
                        valid = true;
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                case 'm':
                    if(chance == -1){
                        chance = 0;
                        
                        for (int i = 0; i < 5; i++){
                            chance = chance + diceArray[i];
                        }
                        playerScore = playerScore + chance;
                        slotsFilled++;
                        valid = true;
                    }
                    else{
                        std::cout<<"You already filled this in."<<std::endl;
                    }
                    break;
                    
                default:
                    std::cout<<"Invalid input."<<std::endl;
                    break;
            }
            
        }
        
    }
}
    endGame();
}
    
    void Player::displayPlayerCard(){
        std::cout << "------------------------------------" <<std::endl;
        if(aces != -1){
        std::cout << "a. Aces           | " <<aces<<std::endl;
        }
        else{
           std::cout << "a. Aces           | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(twos != -1){
            std::cout << "b. 2's            | " <<twos<<std::endl;
        }
        else{
            std::cout << "b. 2's            | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(threes != -1){
            std::cout << "c. 3's            | " <<threes<<std::endl;
        }
        else{
            std::cout << "c. 3's            | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(fours != -1){
            std::cout << "d. 4's            | " <<fours<<std::endl;
        }
        else{
            std::cout << "d. 4's            | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(fives != -1){
            std::cout << "e. 5's            | " <<fives<<std::endl;
        }
        else{
            std::cout << "e. 5's            | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(sixes != -1){
            std::cout << "f. 6's            | " <<sixes<<std::endl;
        }
        else{
            std::cout << "f. 6's            | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(bonus != -1){
            std::cout << "Bonus             | " <<bonus<<std::endl;
        }
        else{
            std::cout << "Bonus             | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        std::cout << "Top Score            | " <<topScore<<std::endl;
        std::cout << "------------------------------------" <<std::endl;
        std::cout << "------------------------------------" <<std::endl;
        if(threeKind != -1){
            std::cout << "g. 3 of a kind       | " <<threeKind<<std::endl;
        }
        else{
            std::cout << "g. 3 of a kind       | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(fourKind != -1){
            std::cout << "h. 4 of a kind       | " <<fourKind<<std::endl;
        }
        else{
            std::cout << "h. 4 of a kind       | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(fullHouse != -1){
            std::cout << "i. Full House        | " <<fullHouse<<std::endl;
        }
        else{
            std::cout << "i. Full House        | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(smStraight != -1){
            std::cout << "j. Sm. Straight      | " <<smStraight<<std::endl;
        }
        else{
            std::cout << "j. Sm. Straight      | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(lrgStraight != -1){
            std::cout << "k. Lrg. Straight     | " <<lrgStraight<<std::endl;
        }
        else{
            std::cout << "k. Lrg. Straight     | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(yahtzee != -1){
            std::cout << "l. Yahtzee           | " <<yahtzee<<std::endl;
        }
        else{
            std::cout << "l. Yahtzee           | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        if(chance != -1){
            std::cout << "m. Chance            | " <<chance<<std::endl;
        }
        else{
            std::cout << "m. Chance            | " <<std::endl;
        }
        std::cout << "------------------------------------" <<std::endl;
        std::cout << "Score                    | " <<playerScore<<std::endl;
        std::cout << "------------------------------------" <<std::endl;
    }

    
    
    //I need the code here to select from scorecard.
    

    
    

