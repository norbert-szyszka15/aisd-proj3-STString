#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "STString.h"

int countOccurrences(char *str, char *word) {
    int count = 0;
    char *token;
    char *delimiters = " ,.!?;:\n";

    char *strCopy = strdup(str);

    token = strtok(strCopy, delimiters);
    while (token != NULL) {
        if (strcasecmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, delimiters);
    }

    free(strCopy);
    return count;
}

int main() {
    {
        FILE *file;
        char *buffer;
        long fileSize;

        file = fopen("./../panTadeusz.txt", "r");
        if (file == NULL) { return 1; }

        fseek(file, 0, SEEK_END);
        fileSize = ftell(file);
        rewind(file);

        buffer = (char *)malloc(fileSize * sizeof(char));
        if (buffer == NULL) { fclose(file); return 1; }

        fread(buffer, sizeof(char), fileSize, file);
        fclose(file);

        char* word = "Tadeusz";
        clock_t start = clock();
        int wordCount = countOccurrences(buffer, word);
        clock_t end = clock();
        double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Liczba wystapien slowa '%s' : %d\n", word, wordCount);
        printf("Czas wykonania dzialania bez drzewa BST: %f sec\n\n", timeSpent);

        free(buffer);
    }

    {
        FILE *file;
        char *tmp;
        long fileSize;

        file = fopen("./../panTadeusz.txt", "r");
        if (file == NULL) { return 1; }

        fseek(file, 0, SEEK_END);
        fileSize = ftell(file);
        rewind(file);

        tmp = (char *)malloc(fileSize * sizeof(char));
        if (tmp == NULL) { fclose(file); return 1; }

        fread(tmp, sizeof(char), fileSize, file);
        fclose(file);

        STString buffer = stringInit(tmp);
        Node *root = splitTextIntoWordsAndInsert(&buffer);

        const char *word = "Tadeusz";
        clock_t start = clock();
        Node *foundWord = searchNode(root, word);
        clock_t end = clock();
        double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Liczba wystapien slowa '%s' : %d\n", word, foundWord->count);
        printf("Czas wykonania dzialania z drzewem BST: %f sec\n\n", timeSpent);

        freeTree(root);
        free(tmp);
    }

    return 0;
}
                // POMYSŁY NA TESTY
/******************************************************************
    1. Wyszukanie danego słowa w długim tekście
    2. Zliczanie wystąpień konkretnych słów w tym tekście - gotowe
******************************************************************/