#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "doubleLL.h"
#include "player.h"
using namespace std;

void addNodeEnd(LinkedList list, Player player) {
    Node *temp;
    if (isEmpty(list)) {
        temp = new Node;
        temp->next = NULL;
        temp->data = player;
        temp->prev = NULL;
        list->head = temp;
    } else {
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

void addNodeBegin(LinkedList list, Player player) {
    Node *temp1 = list->head;
    Node *temp2;
    temp2->data = player;
    temp2->next = temp1;
    temp2->prev = NULL;
    list->head = temp2;
}

void delEndNode(LinkedList list) {
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

int isEmpty(LinkedList list) {
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