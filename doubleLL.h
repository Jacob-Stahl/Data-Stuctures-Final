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
void addNodeNext(Node* top, Node* newNode);
// add node to previous position
void addNodePrev(Node* top, Node* newNode);
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
void addNodeNext(Node* top, Node* newNode)
{
  if (top != NULL)
  {
    Node* temp = top->next;
    if(top != top->next)
    {
      std::cout << "list size > 1" << std::endl;
      temp->prev = newNode;
      newNode->next = temp;
      top->next = newNode;
      newNode->prev = top;
    }
    else
    {
      std::cout << "list size 1" << std::endl;
      newNode->next = newNode->prev = top;
      top->next = top->prev = newNode;
    }
  }
  else
  {
    std::cout << "top == null" << std::endl;
    top = getNewNode();
  }
}
void addNodePrev(Node* top, Node* newNode)
{
  if (top != NULL)
  {
    Node* temp = top->prev;
    if(top == top->next)
    {
      newNode->next = newNode->prev = top;
      top->next = top->prev = newNode;
    }
    else
    {
      temp->next = newNode;
      newNode->prev = temp;
      top->prev = newNode;
      newNode->next = top;
    }
  }
  else
  {
    top = getNewNode();
  }
}
//prints first player and then calls recursive function to do the rest
void pprint(Node* top)
{
  Player* curr;

  std::cout << "getting first player" << std::endl;
  curr = top->data;
  std::cout << "printing player data" << std::endl;
  std::cout << "health     : " << curr->health << std::endl;
  std::cout << "max health : " << curr->max_h << std::endl;
  std::cout << "arrows     : " << curr->arrows << std::endl;

  std::cout << "calling recursive helper" << std::endl << std::endl;
  pprint_helper(top, top->next);
}
void pprint_helper(Node* start, Node* current)
{
  if (current != start)
  {
    Player* curr;

    std::cout << "data : " << std::endl << std::endl;
    curr = current->data;
    std::cout << "health     : " << curr->health << std::endl;
    std::cout << "max health : " << curr->max_h << std::endl;
    std::cout << "arrows     : " << curr->arrows << std::endl;
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
#endif //LAB_5_DOUBLELL_H