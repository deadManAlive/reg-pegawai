#ifndef CONTAINER_H_
#define CONTAINER_H_

//Linked List
typedef struct LLNODE {
    char nip[20];
    char nama[50];
    char gender;
    char gol[5];
    struct LLNODE* next;
} node;

#endif