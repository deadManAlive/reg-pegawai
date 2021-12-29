#include <linkedlist.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
===case insensitive strcmp===
Implemented as non-standard c func.
Use DIY implementation if compiler doesn't provide one.
*/
#ifndef strcasecmp  //gcc?
#ifndef stricmp     //msvc?
static int strcasecmp(CONSTR a, CONSTR b){
    if(a == NULL || b == NULL){
        return 0;
    }

    int diff;
    int minlen = (strlen(a) < strlen(b))?strlen(a):strlen(b);
    for(int i = 0; i < minlen; i++){
        diff = tolower(a[i]) - tolower(b[i]);
        if(diff != 0 && a[i] != '\n' && b[i] != '\n'){
            return diff;
        }
        if(i + 1 == minlen && strlen(a) != strlen(b)){
            return tolower(a[i + 1]) - tolower(b[i + 1]);
        }
    }
    return 0;
}
#else
#define strcasecmp stricmp
#endif
#endif

//append
static void pushback(ListNode* head, CONSTR nip, CONSTR nama, char gender, CONSTR gol){
    ListNode* current = head;
    ListNode* new = malloc(sizeof(ListNode)); //no need to cast in C

    while(current->next != NULL){
        current = current->next;
    }

    strcpy(new->nip, nip);
    strcpy(new->nama, nama);
    new->gender = gender;
    strcpy(new->gol, gol);

    current->next = new;
}

//prepend
static void pushfront(ListNode** head, CONSTR nip, CONSTR nama, char gender, CONSTR gol){
    ListNode* newhead = malloc(sizeof(ListNode));

    strcpy(newhead->nip, nip);
    strcpy(newhead->nama, nama);
    newhead->gender = gender;
    strcpy(newhead->gol, gol);

    newhead->next = *head;
    *head = newhead;
}

ListNode constructList(CONSTR nip, CONSTR nama, char gender, CONSTR gol){
    ListNode new;

    strcpy(new.nip, nip);
    strcpy(new.nama, nama);
    new.gender = gender;
    strcpy(new.gol, gol);

    return new;
}

//NIP-aware data insertion func. to linked list: new inserted data sorted ny NIP, 'addAt' alternative
void insert(ListNode** head, CONSTR nip, CONSTR nama, char gender, CONSTR gol){
    ListNode* current = *head;
    ListNode* new = malloc(sizeof(ListNode));

    strcpy(new->nip, nip);
    strcpy(new->nama, nama);
    new->gender = gender;
    strcpy(new->gol, gol);
    new->next = NULL;

    if(current == NULL){
        pushfront(head, nip, nama, gender, gol);
        return;
    }

    if(strcasecmp(current->nip, nip) > 0){
        pushfront(head, nip, nama, gender, gol);
        return;
    }

    while(current->next != NULL){
        if(strcasecmp(nip, current->nip) >= 0 && strcasecmp(current->next->nip, nip) > 0){
            new->next = current->next;
            current->next = new;
            return;
        }
        current = current->next;
    }
    current->next = new;
}

int delete(ListNode** head, CONSTR nipQuery){
    if(head==NULL){
        return -1;
    }

    ListNode* current = *head;
    ListNode* prev = *head;

    int pos = 0;

    if(strcasecmp(current->nip, nipQuery) == 0){
        *head = current->next;
        free(current);
        return pos;
    }
    pos++;
    current = current->next;

    while(current != NULL){
        if(strcasecmp(current->nip, nipQuery) == 0){
            prev->next = current->next;
            free(current);
            return pos;
        }
        pos++;
        prev = prev->next;
        current = current->next;
    }

    return -1;
}

void printList(const ListNode* head){
    if(head == NULL){
        printf("~~TIDAK ADA DATA.~~\n");
    }

    int maxnamelen = 0;
    const ListNode* seekPtr = head;
    while(seekPtr != NULL){
        int seeknamelen = strlen(seekPtr->nama);
        maxnamelen = (seeknamelen > maxnamelen)?seeknamelen:maxnamelen;
        seekPtr = seekPtr->next;
    }

    int pos = 1;
    int headerlen = printf("No. %-20s %-*s %10s %10s\n", "NIP", maxnamelen, "Nama", "Gender", "Golongan") - 1;
    for(int i = 0; i < headerlen; i++){
        printf("%c", '=');
    }
    printf("\n");

    while(head != NULL){
        printf("%3d %-20s %-*s %10c %10s\n", pos, head->nip, maxnamelen, head->nama, head->gender, head->gol);
        head = head->next;
        pos++;
    }
}

//get linked list size recussively
int getSize(const ListNode* head){
    if(head == NULL){
        return 0;
    }
    else{
        return 1 + getSize(head->next);
    }
}

//get node by position,returns pointer to node
ListNode *getByPosition(const ListNode* head, const int pos){
    ListNode* current = head;
    int seek = 0;

    while(current != NULL){
        if(seek == pos){
            return current;
        }
        seek++;
        current = current->next;
    }
    return NULL;
}

int deleteByPosition(ListNode** head, const int pos){
    if(head == NULL){
        return -1;
    }

    ListNode* current = *head;
    ListNode* prev = *head;

    int seek = 0;

    if(pos == 0){
        *head = current->next;
        free(current);
        return seek;
    }
    seek++;
    current = current->next;

    while(current != NULL){
        if(seek == pos){
            prev->next = current->next;
            free(current);
            return seek;
        }
        seek++;
        prev = prev->next;
        current = current->next;
    }

    return -1;
}