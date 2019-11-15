#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "player.h"
#ifndef LAB_5_DOUBLELL_H
#define LAB_5_DOUBLELL_H

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
void addNodeEnd(Node* list, Player* player);
// NAME : addNodeBegin
// INPUT PARAMETERS: Linked list h, int data
// OUTPUT: Na
// PURPOSE: Adds a node to beginning end of a given linked list
void addNodeBegin(Node* list, Player* player);
// NAME : isEmpty
// INPUT PARAMETERS: Linked list h
// OUTPUT: int
// PURPOSE: returns 1 if the list is empty and 0 if not

int isEmpty(Node* list);
// NAME : delEndNode
// INPUT PARAMETERS: LinkedList h
// OUTPUT: na
// PURPOSE: deletes end node of list

void delEndNode(Node* list);
// NAME : reverseList
// INPUT PARAMETERS: Node *temp
// OUTPUT: Node *
// PURPOSE: reverses a linked list recursivly

Node* reverseList(Node* temp);

void addNodeEnd(Node* list, Player* player) {
	Node *temp;
	if (isEmpty(list)) {
		temp = new Node;
		temp->next = NULL;
		temp->data = player;
		temp->prev = NULL;
		list->head = temp;
	}
	else {
		temp = list->head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->next = NULL;
		temp->next->prev = new Node;
		temp->next->prev = temp;
		temp->next->data = data;
	}
}

void addNodeBegin(Node* list, Player* player) {
	Node *temp1 = list->head;
	Node *temp2;
	temp2->data = player;
	temp2->next = temp1;
	temp2->prev = NULL;
	list->head = temp2;
}

void delEndNode(Node* list) {
	Node *temp1;
	if (!isEmpty(list)) {
		Node *temp = list->head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->prev->next = NULL;
		free(temp);
	}
}

int isEmpty(Node* list) {
	if (list->head == NULL) {
		return 1;
	}
	return 0;
}

Node *reverseList(Node *temp) {
	if (!temp)
		return NULL;
	Node *temp1 = temp->next;
	temp->next = temp->prev;
	temp->prev = temp1;
	if (!temp->prev)
		return temp;
	return reverseList(temp->prev);
}

#endif //LAB_5_DOUBLELL_H
