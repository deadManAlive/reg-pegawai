#ifndef TREE_H_
#define TREE_H_

//simple tree implementation of BST "trie" data struct.
//used in name search.
#include "gtypes.h"
#include <stdbool.h>
#include "linkedlist.h"

typedef struct StructOfATrieNode {
    struct StructOfATrieNode* children[ASCIISIZE];
    bool isEnd;                         //is node marks end of a word?
    ListNode* dataPtrToMainContainer;   //if isEnd = false, this is NULL. ??redundant??
} TrieNode;


void grow(TrieNode** root, const ListNode* data);
int shrink(TrieNode** root, TrieNode* data);
TrieNode* search(const TrieNode* root, CONSTR name_query);
TrieNode* contructTrieFromScratch(void);
TrieNode* constructTrie(const ListNode* head);

#endif