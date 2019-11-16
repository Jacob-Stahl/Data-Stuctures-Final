#include <iostream>
#include "doubleLL.h"
#include "player.h"

using namespace std;

int TOTAL_ARROWS = 0;

// generates double circular linked list of nodes, returns the sheriff at the startinf position
Node* generateGame(int numPlayers);
// returns new Player
Player* getNewPlayer();

int main() 
{

    int numPlayers;
    Node* top;
    cout << "Number of players: ";
    cin >> numPlayers;
    top = generateGame(numPlayers);
    cout << "game generated" << endl;
    cout << "printing game" << endl << endl;
    pprint(top);
    return 0;
}
Player* getNewPlayer()
{
  Player* newPlayer = new Player;
  newPlayer->health = 8;
	newPlayer->max_h = 8;
  newPlayer->arrows = 0;

  return newPlayer;
}
Node* generateGame(int numPlayers)
{
	Player* first;
	Player* newPlayer;
  Node* top = NULL;
	Node* newNode = NULL;
	int renes;
	int outlaws;
	int deps;
	int role_arr[3];
	int j = 0;

  first = new Player;
  cout << "running generateGame" << endl;
	newNode = getNewNode();
  cout << "got first Node" << endl;
  
  first = getNewPlayer();
	first->type = sheriff;
	first->max_h = 10;
	first->health = 10;
  newNode->data = first;

  cout << "adding first Node to list" << endl;
	top = addNodeNext(top, newNode);

  cout << "added sheriff" << endl;
	switch (numPlayers)
	{
		case 4:
		{
		renes = 1;
		outlaws = 2;
		deps = 0;
		break;
		}
		case 5:
		{
			renes = 1;
			outlaws = 2;
			deps = 1;
    break;
		}
		case 6:
		{
			renes = 1;
			outlaws = 3;
			deps = 1;
    break;
		}
		case 7:
		{
			renes = 1;
			outlaws = 3;
			deps = 2;
    break;
		}
		case 8:
		{
			renes = 2;
			outlaws = 3;
			deps = 2;
    break;
		}
	}
	role_arr[0] = renes;
	role_arr[1] = outlaws;
	role_arr[2] = deps;
	
	for(int i = 0; i < ( numPlayers - 1); i++)
	{
		newNode = getNewNode();
    newPlayer = getNewPlayer();
    j = 0;
		while (role_arr[j] <= 0)
		{
			j += 1;
		}	
		switch (j)
		{
			case 0:
			{
				newPlayer->type = rene;
        cout << "added renegade" << endl;
        break;
			}
			case 1:
			{
				newPlayer->type = outlaw;
        cout << "added outlaw" << endl;
        break;
			}
			case 2:
			{
				newPlayer->type = deputy;
        cout << "added deputy" << endl;
        break;
			}
		}
    role_arr[j] -= 1;
    newNode->data = newPlayer;
		top = addNodeNext(top, newNode);
	}
	return top;
}