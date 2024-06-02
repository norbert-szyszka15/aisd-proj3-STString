#include "STString.h"
#include "STStringHelpers.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/************************
 FUNKCJE GŁÓWNE STSTRING
************************/
STSTRING stringInit(const char *initSTString) {
    STSTRING sts;
    sts.length = ststrlen(initSTString);
    sts.data = (char*)malloc(sts.length + 1);
    if (sts.data != NULL) {
        ststrcpy(sts.data, initSTString);
    }
    return sts;
}

size_t stringLength(const STSTRING *sts) {
    return sts->length;
}

void stringCat(STSTRING *destination, const STSTRING *source) {
    size_t newLength = destination->length + source ->length;
    destination->data = (char*)realloc(destination->data, (newLength + 1) * sizeof(char));
    if (destination->data != NULL) {
        ststrcat(destination->data, source->data);
        destination->length = newLength;
    }
}

STSTRING stringCopy(const STSTRING *source) {
    return stringInit(source->data);
}

int stringCompare(const STSTRING *sts1, const STSTRING *sts2) {
    return ststrcmp(sts1->data, sts2->data);
}

void stringPrint(STSTRING sts) {
    printf("%s\n", sts.data);
}

void stringFree(STSTRING *sts) {
    if (sts != NULL) {
        free(sts->data);
        sts->data = NULL;
    }
    sts->length = 0;
}

void stringClean(STSTRING *sts) {
    stringFree(sts);
}


/**************************
 FUNKCJE GŁÓWNE DRZEWA BST
**************************/
Node* createNode(const char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->word = strdup(word);
    if (newNode->word == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, const char *word) {
    if (root == NULL) {
        return createNode(word);
    }

    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = insertNode(root->left, word);
    } else if (cmp > 0) {
        root->right = insertNode(root->right, word);
    } else {
        root->count++;
    }

    return root;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s (count: %d)\n", root->word, root->count);
        inorderTraversal(root->right);
    }
}

void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root);
    }
}

Node* splitTextIntoWordsAndInsert(STSTRING *text) {
    Node* root = NULL;
    char *textCopy = strdup(text->data);
    if (textCopy == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(textCopy, " ,.!?;:\n"); 

    while (token != NULL) {
        root = insertNode(root, token);
        token = strtok(NULL, " ,.!?;:\n");
    }

    free(textCopy);
    return root;
}

Node* searchNode(Node *root, const char *word) {
    if (root == NULL || strcmp(root->word, word) == 0) {
        return root;
    }

    if (strcmp(word, root->word) < 0) {
        return searchNode(root->left, word);
    }

    return searchNode(root->right, word);
}