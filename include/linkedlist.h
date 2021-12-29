#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "gtypes.h"

//sorted linked list
typedef struct LinkedListNode{
    char nip[20];
    char nama[50];
    char gender;
    char gol[5];
    struct LinkedListNode* next;
} ListNode;

ListNode constructList(CONSTR nip, CONSTR nama, char gender, CONSTR gol);
void insert(ListNode** head, CONSTR nip, CONSTR nama, char gender, CONSTR gol);
int delete(ListNode** head, CONSTR nip_query);
void printList(const ListNode* head);

#endif