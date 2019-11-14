
include "player.h"
#ifndef LAB_5_DOUBLELL_H
#define LAB_5_DOUBLELL_H

template<typename T>
struct Node 
{
    Player data;
    Node *next;
    Node *prev;
};

// NAME : addNodeEnd
// INPUT PARAMETERS: Linked list h, int data
// OUTPUT: Na
// PURPOSE: Adds a node to end end of a given linked list
void addNodeEnd(Node h, Player player);
// NAME : addNodeBegin
// INPUT PARAMETERS: Linked list h, int data
// OUTPUT: Na
// PURPOSE: Adds a node to beginning end of a given linked list
void addNodeBegin(Node h, Player player);
// NAME : isEmpty
// INPUT PARAMETERS: Linked list h
// OUTPUT: int
// PURPOSE: returns 1 if the list is empty and 0 if not

int isEmpty(Node* h);
// NAME : delEndNode
// INPUT PARAMETERS: LinkedList h
// OUTPUT: na
// PURPOSE: deletes end node of list

void delEndNode(Node* h);
// NAME : reverseList
// INPUT PARAMETERS: Node *temp
// OUTPUT: Node *
// PURPOSE: reverses a linked list recursivly

Node* reverseList(Node* temp);

#endif //LAB_5_DOUBLELL_H
