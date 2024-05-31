#pragma once

#include <stddef.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char *data;
    size_t length;
} STString;

// Funkcje glowne STString
STString stringInit(const char *initSTString);

size_t stringLength(const STString *sts);
void stringCat(STString *destination, const STString *source);
STString stringCopy(const STString *source);
int stringCompare(const STString *sts1, const STString *sts2);

void stringFree(STString *sts);
void stringClean(STString *sts);

#define AUTO __attribute__((cleanup(stringClean)))