#include <iostream>
#include "doubleLL.h"
#include "player.h"

using namespace std;
/* Function Name: getNewPlayer
  Function Inputs: n/a
  Function Purpose: creates a new player node

  Function Name: generateGame
  Function Inputs: number of players in the game
  Function Purpose: generates a circular linked list of players in the game

  Function Name: checkForWins
  Function Inputs: node pointer in the circular loop
  Function Purpose: traverses the entire loop to check if a player has won the game by another player dying


*/

// generates double circular linked list of nodes, returns the sheriff at the startinf position
Node* generateGame(int numPlayers);
// returns new Player
Player* getNewPlayer();
// check win
bool checkForWins(Node *top);

int main() 
{

    int numPlayers;
    Node *player;
    cout << "Number of players: ";
    cin >> numPlayers;
    player = generateGame(numPlayers);//player is the start of the circular doubleLL not just a single player

    cout << "game generated" << endl;
    cout << "printing game" << endl << endl;
    pprint(player);


    while (!checkForWins(player)) {
        makeMove(player);
        player = player->next;
    }
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

bool checkForWins(Node *top) {
    Node *ptr;
    int rene_ = 0, sheriff_ = 0, outlaw_ = 0, deputy_ = 0;

    ptr = top->next;

    switch (top->data->type) {
        case rene:
            rene_ += 1;
            break;
        case sheriff:
            sheriff_ += 1;
            break;
        case outlaw:
            outlaw_ += 1;
            break;
        case deputy:
            deputy_ += 1;
            break;
    }
    while (ptr != top) {
        switch (ptr->data->type) {
            case rene:
                rene_ += 1;
                break;
            case sheriff:
                sheriff_ += 1;
                break;
            case outlaw:
                outlaw_ += 1;
                break;
            case deputy:
                deputy_ += 1;
                break;
        }
    }

    if (sheriff == 0) {
        if (outlaw > 0) {
            cout << "outlaws win!" << endl;
            return 1;
        } else {
            cout << "renegades win!" << endl;
            return 1;
        }
    } else {
        if (outlaw == 0 && rene == 0) {
            cout << "sheriff!" << endl;
            return 1;
        }
    }
    return 0;
}
