//
//  main.cpp
//  Yahtzee
//
//  Created by Tyrone Forte on 4/25/20.
//  Copyright © 2020 Tyrone. All rights reserved.
//

#include <iostream>
#include "yahtzee.hpp"


int main() {
    srand(time(NULL));
    
    Player a;
    
    a.takeTurn();
    
    return 0;
}
