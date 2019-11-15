#include <cstdio>
#include <cstdlib>
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

enum PlayerType { rene, sheriff, outlaw, deputy };
struct Player
{
	int health;
	int max_h;
	int arrows;
	PlayerType type;
};

#endif