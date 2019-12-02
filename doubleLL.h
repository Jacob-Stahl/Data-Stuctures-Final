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
void deleteCurrent(Node* top)
{
    top->prev->next = top->next;
    top->next->prev = top->prev;
    free(top);
}
void deleteNode(Node* top, int pos) 
{
  if (top != NULL)
  {
    if (pos > 0)
    {
      deleteNode(top->next, pos - 1);
    } else if (pos < 0) {
      deleteNode(top->prev, pos + 1);
    } else {
      deleteCurrent(top);
    }
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
    } else {
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
    } else {
      newNode->next = newNode->prev = top;
      top->next = top->prev = newNode;

      return top;
    }
  } else {
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
    switch (curr->type) {
        case rene:
            std::cout << "Type       : Renagade" << std::endl;
            break;

        case sheriff:
            std::cout << "Type       : Sheriff" << std::endl;
            break;

        case outlaw:
            std::cout << "Type       : Outlaw" << std::endl;
            break;

        case deputy:
            std::cout << "Type       : Deputy" << std::endl;
            break;

        default:
            break;
    }
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
      std::cout << "Player     : " << curr->number << std::endl;
      switch (curr->type) {
          case rene:
              std::cout << "Type       : Renagade" << std::endl;
              break;

          case sheriff:
              std::cout << "Type       : Sheriff" << std::endl;
              break;

          case outlaw:
              std::cout << "Type       : Outlaw" << std::endl;
              break;

          case deputy:
              std::cout << "Type       : Deputy" << std::endl;
              break;

          default:
              break;
      }
      std::cout << "Health     : " << curr->health << std::endl;
      std::cout << "Max Health : " << curr->max_h << std::endl;
      std::cout << "Arrows     : " << curr->arrows << std::endl;
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
            std::cout << "\nremoving player" << endl;
            deleteNode(player, pos);
        } else {
            currentDead = 0;
            std::cout << "\nremoving player" << endl;
            deleteNode(player, pos);
        }
        cout << "\nPlayer " << player->data->number << " died\n";

    }
    return currentDead;
}


void makeMove(Node *player) {
    Dice die[6];
    int keepDice[6] = {0, 0, 0, 0, 0, 0};//used in conjunction with the roll function.
    // index corresponds to dice, 1 to keep 0 to reroll
    int keep;//when weather or not the dice is to be kept needs to be decided
    int leftOrRight;//used when shooting players, 1 for left 0 for right
    int numDynamite = 0; //keeps track of number of dynamite that have been rolled//
    int numGat = 0; // keeps track of number of gatling gun rolls
    Node *temp;

    for (int j = 0; j < 3; j++) {
        if (j == 0) {
            cout << "\t\nRoll Player: " << player->data->number << endl;
            roll(die);
            cout << "\nInitial Roll:\n";
            printDice(die);
        } else {
            cout << "\t\nRe-roll Player: " << player->data->number << endl;
            reroll(die, keepDice);
            if (j == 2) {
                cout << "\nFinal Roll:\n";
                printDice(die);
            }
        }
        for (int i = 0; i < 6; i++) {
            switch (die[i]) {
                case arrow:
                    //cout << "\n Arrow\n";
                    TOTAL_ARROWS -= 1;
                    player->data->arrows += 1;
                    if (TOTAL_ARROWS <= 0) {//when arrows run out have indians attack
                       // cout << "\n\t\tBETTTTT\n";
                        temp = player;
                        int pos = 1;
                        while (temp->next != player) {
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
                   // cout << "\n Dynamite\n";
                    keepDice[i] = 1;
                    numDynamite++;
                    if (numDynamite >= 3) {
                        player->data->health--;
                        if (isDead(player, player, 0)) {
                            return;
                        }
                        return;
                    }
                    break;
                case oneShot:
                    //cout << "\n oneShot\n";
                    keep = rand() % 2;
                    if (keep) {
                        keepDice[i] = 1;
                        leftOrRight = rand() % 2;
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
                    //cout << "\n twoShot\n";
                    keep = rand() % 2;
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
                    //cout << "\n beer\n";
                    if (player->data->health != player->data->max_h) {//cannot go over max health
                        keep = rand() % 2;
                        if (keep) {
                            keepDice[i] = 1;
                            player->data->health++;
                        }
                    }
                    break;
                case gatGun:
                    //cout << "\n gatGun\n";
                    keep = rand() % 2;
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
