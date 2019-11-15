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

void addNodeNext(Node* top, Player* player);
void addNodePrev(Node* top, Player* player);
void pprint_helper(Node* start, Node* next);
void pprint(Node* top);
// delete node at any position. negative int to go backwards
// use this when freeing player nodes when they die
void deleteNode(Node* top, int pos);

Node* getNewNode(void)
{
  Node* newNode = new Node;

  newNode->next = newNode;
  newNode->prev = newNode;

  return newNode;
}
void deleteNode(Node* top, int pos) 
{
  if (pos > 0)
  {
    deleteNode(top->next, pos - 1);
  }
  else if (pos < 0)
  {
    deleteNode(top->prev, pos + 1);
  }
  else
  {
    top->prev->next = top->next;
    top->next->prev = top->prev;
    free(top);
  }
}

void addNodeNext(Node* top, Player* player)
{
  if (top != NULL)
  {
    Node* newNode;

    newNode = getNewNode();
    newNode->data = player;

    top->next->prev = newNode;
    newNode->next = top->next;
    top->next = newNode;
    newNode->prev = top;
  }
  else
  {
    top = getNewNode();
    top->data = player;
  }
}
void addNodePrev(Node* top, Player* player)
{
  if (top != NULL)
  {
    Node* newNode;

    newNode = getNewNode();
    newNode->data = player;

    top->prev->next = newNode;
    newNode->prev = top->prev;
    top->prev = newNode;
    newNode->next = top;
  }
  else
  {
    top = getNewNode();
    top->data = player;
  }
}

//prints first player and then calls recursive function to do the rest
void pprint(Node* top)
{
  Player* curr;

  curr = top->data;
  std::cout << "health     : " << curr->health << std::endl;
  std::cout << "max health : " << curr->max_h << std::endl;
  std::cout << "arrows     : " << curr->arrows << std::endl;

  pprint_helper(top, top->next);
}
void pprint_helper(Node* start, Node* current)
{
  if (current != start)
  {
    Player* curr;

    curr = current->data;
    std::cout << "health     : " << curr->health << std::endl;
    std::cout << "max health : " << curr->max_h << std::endl;
    std::cout << "arrows     : " << curr->arrows << std::endl;
    pprint_helper(start, current->next);
  }
}

#endif //LAB_5_DOUBLELL_H