#include <iostream>
#include "doubleLL.h"
#include "player.h"

using namespace std;

int TOTAL_ARROWS = 0;
Node* generateGame(int numPlayers)
{
	Player* first;
	Player* newPlayer;
  Node* top;
	Node* newNode;
	int renes;
	int outlaws;
	int deps;
	int role_arr[3];
	int j = 0;

  first = new Player;
  cout << "running generateGame" << endl;
	top = getNewNode();
  cout << "got new Node" << endl;
	first->type = sheriff;
	first->max_h = 10;
	first->health = 10;

  cout << "adding new Node to list" << endl;
	addNodeNext(top, first);

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
    newPlayer = new Player;
		while (role_arr[j] == 0)
		{
			j += 1;
		}	
		switch (j)
		{
			case 0:
			{
				newPlayer->health = 8;
				newPlayer->max_h = 8;
				newPlayer->type = rene;
        cout << "added renegade" << endl;
        break;
			}
			case 1:
			{
				newPlayer->health = 8;
				newPlayer->max_h = 8;
				newPlayer->type = outlaw;
        cout << "added outlaw" << endl;
        break;
			}
			case 2:
			{
				newPlayer->health = 8;
				newPlayer->max_h = 8;
				newPlayer->type = deputy;
        cout << "added deputy" << endl;
        break;
			}
		}
		addNodeNext(newNode, newPlayer);
	}

	return top;

}
int main() {

    int numPlayers;
    Node* top;
    cout << "Number of players: ";
    cin >> numPlayers;

    top = generateGame(numPlayers);

    cout << "game generated" << endl;

    pprint(top);
    return 0;
}
