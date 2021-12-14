#ifndef STACK_H_
#define STACK_H_

#include "gtypes.h"
#include <stdbool.h>

//linked list-like stack
typedef struct StructOfAStackNode {
    char nip[20];
    char nama[50];
    char gender;
    char gol[5];
    struct StructOfAStackNode* next;
} StackNode;

StackNode* constructStack(CONSTR nip, CONSTR nama, char gender, CONSTR gol);
void push(StackNode** top, CONSTR nip, CONSTR nama, char gender, CONSTR gol);
StackNode pop(StackNode** top); //return top, delete top
StackNode stackPeek(const StackNode* top); //return top
//ll-like stack has no definite size.

#endif