//
// Created by Troll on 10/11/2019.
//

#ifndef LAB_5_DOUBLELL_H
#define LAB_5_DOUBLELL_H
typedef struct listHead *LinkedList;
template T;
typedef struct node {
    T data;
    struct node *next;
    struct node *prev;
} Node;

struct listHead {
    Node *head;
};

void addNodeEnd(LinkedList h, int data);
// NAME : addNodeEnd
// INPUT PARAMETERS: Linked list h, int data
// OUTPUT: Na
// PURPOSE: Adds a node to end end of a given linked list

void addNodeBegin(LinkedList h, int data);
// NAME : addNodeBegin
// INPUT PARAMETERS: Linked list h, int data
// OUTPUT: Na
// PURPOSE: Adds a node to beginning end of a given linked list

void printList(LinkedList h);
// NAME : printList
// INPUT PARAMETERS: LinkedList h
// OUTPUT: na
// PURPOSE: prints the list
int isEmpty(LinkedList h);
// NAME : isEmpty
// INPUT PARAMETERS: Linked list h
// OUTPUT: int
// PURPOSE: returns 1 if the list is empty and 0 if not

void delEndNode(LinkedList h);
// NAME : delEndNode
// INPUT PARAMETERS: LinkedList h
// OUTPUT: na
// PURPOSE: deletes end node of list

Node *reverseList(Node *temp);
// NAME : reverseList
// INPUT PARAMETERS: Node *temp
// OUTPUT: Node *
// PURPOSE: reverses a linked list recursivly

LinkedList create();

#endif //LAB_5_DOUBLELL_H
