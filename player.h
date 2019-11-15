#include <cstdio>
#include <cstdlib>
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

enum PlayerType { rene, sheriff, outlaw, deputy };
struct Player
{
	int health;
	int MAX_HEALTH;
	int arrows = 0;
	PlayerType type;
};

#endif
