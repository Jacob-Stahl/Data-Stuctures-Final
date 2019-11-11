//
// Created by Troll on 10/11/2019.
//
#include <cstdio>
#include<cstdlib>
#include <iostream>
#include "doubleLL.h"

using namespace std;


LinkedList create() {
    LinkedList list;
    list = new listHead;
    list->head = NULL;
    return list;
}

void addNodeEnd(LinkedList list, int data) {
    Node *temp;
    if (isEmpty(list)) {
        temp = new Node;
        temp->next = NULL;
        temp->data = data;
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

void addNodeBegin(LinkedList list, int data) {
    Node *temp1 = list->head;
    Node *temp2;
    temp2->data = data;
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

void printList(LinkedList list) {
    Node *temp = list->head;
    cout << "your List: ";
    while (temp != NULL) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;

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






