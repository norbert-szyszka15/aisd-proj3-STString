#pragma once

#include <stddef.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct STSTRING {
    char *data;
    size_t length;
} STSTRING;

typedef struct Node {
    char *word;
    int count;
    struct Node *left;
    struct Node *right;
} Node;

/************************
 FUNKCJE GŁÓWNE STSTRING
************************/
STSTRING stringInit(const char *initSTString);
size_t stringLength(const STSTRING *sts);
void stringCat(STSTRING *destination, const STSTRING *source);
STSTRING stringCopy(const STSTRING *source);
int stringCompare(const STSTRING *sts1, const STSTRING *sts2);
void stringPrint(STSTRING sts);
void stringFree(STSTRING *sts);
void stringClean(STSTRING *sts);

/**************************
 FUNKCJE GŁÓWNE DRZEWA BST
**************************/
Node* createNode(const char *word);
Node* insertNode(Node *root, const char *word);
void inorderTraversal(Node *root);
void freeTree(Node *root);
Node* splitTextIntoWordsAndInsert(STSTRING *text);
Node* searchNode(Node *root, const char *word);

#define STString STSTRING __attribute__((cleanup(stringClean)))