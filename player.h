#include <cstdio>
#include <cstdlib>
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

enum PlayerType { rene, sheriff, outlaw };
struct Player
{
	int health;
	int MAX_HEALTH;
	int arrows;
	PlayerType type;
	Player* next = NULL;
	Player* prev = NULL;
};

#endif
