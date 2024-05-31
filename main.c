#include <stdlib.h>
#include <stdio.h>

#include "STString.h"

typedef struct TreeNode {
    char* word;
    int count;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Funkcja tworząca nowy węzeł
TreeNode* createNode(char* word) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        newNode->word = strdup(word);
        newNode->count = 1;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Funkcja wstawiająca słowo do drzewa
TreeNode* insertWord(TreeNode* root, char* word) {
    if (root == NULL) {
        return createNode(word);
    }
    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = insertWord(root->left, word);
    } else if (cmp > 0) {
        root->right = insertWord(root->right, word);
    } else {
        root->count++;
    }
    return root;
}

// Funkcja wyświetlająca drzewo w kolejności inorder
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s (%d)\n", root->word, root->count);
        inorderTraversal(root->right);
    }
}

int main() {

    AUTO STString s1 = stringInit("seks seks seks seks\nPiwo Piwo Piwo Piwo");
    printf("%s --- LEN: %zu\n", s1.data, s1.length);

    return 0;
}