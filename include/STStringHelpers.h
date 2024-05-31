#pragma once

#include "STString.h"

// Funkcje pomocnicze STString
size_t ststrlen(const char *str);
char *ststrcpy(char *destination, const char *source);
char *ststrcat(char *destination, const char *source);
int ststrcmp(const char *ststr1, const char *ststr2);