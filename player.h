#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "roll.h"


#ifndef PLAYER_H
#define PLAYER_H

int TOTAL_ARROWS = 9;
enum PlayerType {
    rene, sheriff, outlaw, deputy
};
struct Player {
    int health;
    int max_h;
    int arrows;
    PlayerType type;
};

#endif
