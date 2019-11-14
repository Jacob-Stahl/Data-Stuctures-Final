#include <cstdio>
#include <cstdlib>
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	int health;
	int MAX_HEALTH;
	int arrows;
	Player* next = NULL;
	Player* prev = NULL;
};

#endif
