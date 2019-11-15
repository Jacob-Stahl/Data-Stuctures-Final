#include <cstdio>
#include <cstdlib>
#include <iostream>
//#include "doubleLL.h"
#include "roll.h"
#include "doubleLL.h"


#ifndef PLAYER_H
#define PLAYER_H
enum Dice{arrow, dynamite, oneShot, twoShot, beer, gatGun};
int TOTAL_ARROWS = 9;

struct Player
{
	int health;
	int MAX_HEALTH;
	int arrows;
	Player* next = NULL;
	Player* prev = NULL;
};

void isDead(Player *player, Player *temp, int pos) {
    if (temp->health <= 0) {
        deleteNode(player, pos);

    }
}

void makeMove(Player *player) {
    Dice die[5];
    int keepDice[5] = {0, 0, 0, 0,
                       0};//used in conjuction with the roll function. index corresponds to dice, 1 to keep 0 to reroll
    int keep;//when weather or not the dice is to be kept needs to be decided
    int leftOrRight;//used when shooting players, 1 for left 0 for right
    int numDynamite = 0; //keeps track of number of dynamite that have been rolled//
    int numGat = 0; // keeps track of number of gatling gun rolls
    Player *temp;
    initialRoll(die);
    for (int i = 0; i < 5; i++) {
        switch (die[i]) {
            case arrow:
                player->arrows += 1;
                TOTAL_ARROWS -= 1;
                if (TOTAL_ARROWS == 0) {//when arrows run out have indians attack
                    temp = player;
                    int pos = 1;//what if the player is killed?
                    while (temp != player) {
                        temp->health -= temp->arrows;
                        isDead(player, temp , pos);
                        temp = temp->next;
                        pos += 1;
                    }
                    TOTAL_ARROWS = 9;
                }
                break;
            case dynamite:
                keepDice[i] = 1;
                numDynamite++;
                if (numDynamite >= 3) {
                    player->health--;
                    //end turn
                }
                break;
            case oneShot:
                keep = rand() % 1;
                if (keep) {
                    keepDice[i] = 1;
                    leftOrRight = rand() % 1;
                    if (leftOrRight) {
                        player->prev->health--;
                    } else {
                        player->next->health--;
                    }
                }

                break;
            case twoShot:
                keep = rand() % 1;
                if (keep) {
                    keepDice[i] = 1;
                    leftOrRight = rand() % 1;
                    if (player->next->next != player) {//makes sure the player does not shoot himself
                        if (leftOrRight) {
                            player->prev->prev->health--;
                            isDead(player->prev->prev);
                        } else {
                            player->next->next->health--;
                            isDead(player->next->next);
                        }
                    } else {
                        if (leftOrRight) {
                            player->prev->health--;
                            isDead(player->prev);
                        } else {
                            player->next->health--;
                            isDead(player->next);
                        }
                    }
                }
                break;
            case beer:
                if (player->health != player->MAX_HEALTH) {//cannot go over max health
                    keep = rand() % 1;
                    if (keep) {
                        keepDice[i] = 1;
                        player->health++;
                    }
                }
                break;
            case gatGun:
                keep = rand() % 1;
                if (keep) {
                    keepDice[i] = 1;
                    numGat++;
                    TOTAL_ARROWS += player->arrows; //add arrows back to pile
                    player->arrows = 0;
                    if (numGat == 3) {
                        temp = player;
                        temp = temp->next;
                        while (temp != player) {//iterate through players and subtract a life point from each
                            temp->health--;
                            isDead(temp);
                            temp = temp->next;
                        }
                    }
                }
                break;
            default:
                cout << "ROLL ERROR\n";
                break;

        }
    }

}

#endif
