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

int isDead(Node *player, Node *temp, int pos) {
    int currentDead = 0;//if the current player is dead then 1. is necessary because its a special case where we must
    // move to next turn instantly afterwards
    if (temp->data->health <= 0) {
        if (pos == 0) {
            currentDead = 1;
        } else {
            currentDead = 0;
        }
        deleteNode(player, pos);
    }
    return currentDead;
}


void makeMove(Node *player) {
    Dice die[5];
    int keepDice[5] = {0, 0, 0, 0, 0};//used in conjuction with the roll function.
                                      // index corresponds to dice, 1 to keep 0 to reroll
    int keep;//when weather or not the dice is to be kept needs to be decided
    int leftOrRight;//used when shooting players, 1 for left 0 for right
    int numDynamite = 0; //keeps track of number of dynamite that have been rolled//
    int numGat = 0; // keeps track of number of gatling gun rolls
    Node *temp;
    initialRoll(die);
    for (int i = 0; i < 5; i++) {
        switch (die[i]) {
            case arrow:
                player->data->arrows += 1;
                TOTAL_ARROWS -= 1;
                if (TOTAL_ARROWS == 0) {//when arrows run out have indians attack
                    temp = player;
                    int pos = 1;//what if the player is killed?
                    while (temp != player) {
                        temp->data->health -= temp->data->arrows;
                        if (isDead(player, temp, pos)) {//returns 1 only if the current player is dead;
                            return;
                        }
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
                    player->data->health--;
                    if (isDead(player, player, 0)) {
                        return;
                    }
                    //end turn
                }
                break;
            case oneShot:
                keep = rand() % 1;
                if (keep) {
                    keepDice[i] = 1;
                    leftOrRight = rand() % 1;
                    if (leftOrRight) {
                        player->prev->data->health--;
                        if (isDead(player, player->prev, -1)) {
                            return;
                        }
                    } else {
                        player->next->data->health--;
                        if (isDead(player, player->next, 1)) {
                            return;
                        }
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
                            player->prev->prev->data->health--;
                            if (isDead(player, player->prev->prev, -2)) {
                                return;
                            }
                        } else {
                            player->next->next->data->health--;
                            if (isDead(player, player->next->next, 2)) {
                                return;
                            }
                        }
                    } else {
                        if (leftOrRight) {
                            player->prev->data->health--;
                            if (isDead(player, player->prev, -1)) {
                                return;
                            }
                        } else {
                            player->next->data->health--;
                            if (isDead(player, player, 0)) {
                                return;
                            }
                        }
                    }
                }
                break;
            case beer:
                if (player->data->health != player->data->MAX_HEALTH) {//cannot go over max health
                    keep = rand() % 1;
                    if (keep) {
                        keepDice[i] = 1;
                        player->data->health++;
                    }
                }
                break;
            case gatGun:
                keep = rand() % 1;
                if (keep) {
                    keepDice[i] = 1;
                    numGat++;
                    TOTAL_ARROWS += player->data->arrows; //add arrows back to pile
                    player->data->arrows = 0;

                    if (numGat == 3) {
                        temp = player;
                        temp = temp->next;
                        int pos = 1;
                        while (temp != player) {//iterate through players and subtract a life point from each
                            temp->data->health--;
                            if (isDead(player, temp, pos)) {
                                return;
                            }
                            temp = temp->next;
                            pos++;
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
