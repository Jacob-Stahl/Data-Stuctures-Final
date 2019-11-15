#include <iostream>
#include "doubleLL.h"
#include "player.h"

using namespace std;

TOTAL_ARROWS = 0;

Node* getNewNode()
{
	Node* newNode = new Node;

	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}
Node* generateGame(int numPlayers)
{
	Player* first;
	Player* newPlayer;
	Node* newNode;
	int renes;
	int outlaws;
	int deps;
	int* role_arr[3];
	int j = 0;

	newNode = getNewNode();
	first->type = sheriff;
	first->MAX_HEALTH = 10;
	first->health = 10;

	addNodeEnd(newNode, first);

	switch numPlayers
	{
		case: 4
		{
		renes = 1;
		outlaws = 2;
		deps = 0;
		break;
		}
		case: 5
		{
			renes = 1;
			outlaws = 2;
			deps = 1;
		}
		case: 6
		{
			renes = 1;
			outlaws = 3;
			deps = 1;
		}
		case: 7
		{
			renes = 1;
			outlaws = 3;
			deps = 2;
		}
		case: 8
		{
			renes = 2;
			outlaws = 3;
			deps = 2;
		}
	}
	role_arr[0] = renes
	role_arr[1] = outlaws
	role_arr[2] = deps
	
	for(int i = 0; i < ( numPlayers - 1); i++)
	{
		newNode = getNewNode();
		while (role_arr[j] == 0)
		{
			j += 1;
		}	
		switch j
		{
			case: 0
			{
				newPlayer->health = 8;
				newPlayer->MAXHEALTH = 8;
				newPlayer->type = rene;
			}
			case: 1
			{
				newPlayer->health = 8;
				newPlayer->MAXHEALTH = 8;
				newPlayer->type = outlaw;
			}
			case: 2
			{
				newPlayer->health = 8;
				newPlayer->MAXHEALTH = 8;
				newPlayer->type = deputy;
			}
		}
		addNodeEnd(newNode, newplayer)
	}

	return first;

}
int main() {

    int numPlayers;
    cout << "Number of players: ";
    cin >> numPlayers;

    for(int)
    return 0;
}
