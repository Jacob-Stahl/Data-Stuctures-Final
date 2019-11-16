#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "player.h"
#ifndef LAB_5_DOUBLELL_H
#define LAB_5_DOUBLELL_H

struct Node
{
    Player* data;
    Node* next;
    Node* prev;
};

// returns new Node
Node* getNewNode(void);
// add node to next position
Node* addNodeNext(Node* top, Node* newNode);
// add node to previous position
Node* addNodePrev(Node* top, Node* newNode);
// recursive helper function used by pprint
void pprint_helper(Node* start, Node* current);
// prints all nodes and player data
void pprint(Node* top);
// delete node at any position. negative int to go backwards
// use this when deleting player nodes when they die
void deleteNode(Node* top, int pos);
// recursive helper function that is called by validateList, similar to pprint
void validateList_helper(Node* start, Node* current);
// attempts to traverse list for testing purposes
void validateList(Node* top);

Node* getNewNode(void)
{
  Node* newNode = new Node;

  newNode->next = newNode;
  newNode->prev = newNode;

  return newNode;
}
Node* deleteNode(Node* top, int pos, bool check = 0) 
{
    Node *temp;
  if (check == 0 && pos == 0)
  {
    temp = top->next;
    free(top);
    return temp;
  }
  else if (check == 0 && pos != 0)
  {
    temp = top;
  }
  if (pos > 0)
  {
    deleteNode(top->next, pos - 1, 1);
  }
  else if (pos < 0)
  {
    deleteNode(top->prev, pos + 1, 1);
  }
  else
  {
    top->prev->next = top->next;
    top->next->prev = top->prev;
    free(top);
    return temp;
  }
}
Node* addNodeNext(Node* top, Node* newNode)
{
  if (top != NULL)
  {
    Node* temp = top->next;
    if(top != top->next)
    {
      temp->prev = newNode;
      newNode->next = temp;
      top->next = newNode;
      newNode->prev = top;

      return top;
    }
    else
    {
      newNode->next = newNode->prev = top;
      top->next = top->prev = newNode;

      return top;
    }
  }
  else
  {
    top = newNode;

    return top;
  }
}
Node* addNodePrev(Node* top, Node* newNode)
{
  if (top != NULL)
  {
    Node* temp = top->prev;
    if(top != top->next)
    {
      temp->next = newNode;
      newNode->prev = temp;
      top->prev = newNode;
      newNode->next = top;

      return top;
    }
    else
    {
      newNode->next = newNode->prev = top;
      top->next = top->prev = newNode;

      return top;
    }
  }
  else
  {
    top = newNode;

    return top;
  }
}
//prints first player and then calls recursive function to do the rest
void pprint(Node* top)
{
  Player* curr;
  curr = top->data;
  std::cout << "player     : " << curr->number << std::endl;
  std::cout << "health     : " << curr->health << std::endl;
  std::cout << "max health : " << curr->max_h << std::endl;
  std::cout << "arrows     : " << curr->arrows << std::endl;
  std::cout << std::endl;
  pprint_helper(top, top->next);
}
void pprint_helper(Node* start, Node* current)
{
  if (current != start)
  {
    Player* curr;

    curr = current->data;
    std::cout << "player     : " << curr->number << std::endl;
    std::cout << "health     : " << curr->health << std::endl;
    std::cout << "max health : " << curr->max_h << std::endl;
    std::cout << "arrows     : " << curr->arrows << std::endl;
    std::cout << std::endl;
    pprint_helper(start, current->next);
  }
}
void validateList(Node* top)
{
  std::cout << top->prev << "   ";
  std::cout << top << "   ";
  std::cout << top->next << std::endl;
  validateList_helper(top, top->next);
}
void validateList_helper(Node* start, Node* current)
{
  if (current != start)
  {
  std::cout << current->prev << "   ";
  std::cout << current << "   ";
  std::cout << current->next << std::endl;
  validateList_helper(start, current->next);
  }
}
int isDead(Node *player, Node *temp, int pos) {
    int currentDead = 0;//if the current player is dead then 1. is necessary because its a special case where we must
    // move to next turn instantly afterwards
    if (temp->data->health <= 0) {
        if (pos == 0) {
            currentDead = 1;
            deleteNode(player, pos, 1);
        } else {
            currentDead = 0;
            deleteNode(player, pos, 0);
        }

    }
    return currentDead;
}


void makeMove(Node *player) {
    Dice die[6];
    int test[6] = {1, 1, 1, 1, 1, 1};
    int keepDice[6] = {0, 0, 0, 0, 0, 0};//used in conjuction with the roll function.
                                      // index corresponds to dice, 1 to keep 0 to reroll
    int keep;//when weather or not the dice is to be kept needs to be decided
    int leftOrRight;//used when shooting players, 1 for left 0 for right
    int numDynamite = 0; //keeps track of number of dynamite that have been rolled//
    int numGat = 0; // keeps track of number of gatling gun rolls
    Node *temp;

    for (int j = 0; j < 3; j++) {
        if (j == 0) {
            roll(die);
        } else {
            if (keepDice == test) {
                return;
            }
            reroll(die, keepDice);
        }
        for (int i = 0; i < 6; i++) {
            switch (die[i]) {
                case arrow:
                    player->data->arrows += 1;
                    TOTAL_ARROWS -= 1;
                    if (TOTAL_ARROWS == 0) {//when arrows run out have indians attack
                        temp = player;
                        int pos = 1;//what if the player is killed?
                        while (temp != player) {
                            temp->data->health -= temp->data->arrows;
                            temp->data->arrows = 0;
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
                    if (player->data->health != player->data->max_h) {//cannot go over max health
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
}
#endif //LAB_5_DOUBLELL_H
