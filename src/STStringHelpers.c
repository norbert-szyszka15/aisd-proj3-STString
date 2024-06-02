#include "STStringHelpers.h"

// Obliczanie długości stringa
size_t ststrlen(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Kopiowanie stringów
char *ststrcpy(char *destination, const char *source) {
    char *strPtr = destination;
    while (*source) {
        *strPtr++ = *source++;
    }
    *strPtr = '\0';
    return destination;
}

// Łączenie stringów
char *ststrcat(char *destination, const char *source) {
    char *strPtr = destination + ststrlen(destination);
    while (*source) {
        *strPtr++ = *source++;
    }
    *strPtr = '\0';
    return destination;
}

// Porównywanie stringów
int ststrcmp(const char *ststr1, const char *ststr2) {
    while (*ststr1 && (*ststr1 == *ststr2)) {
        ststr1++;
        ststr2++;
    }
    return *(unsigned char*)ststr1 - *(unsigned char*)ststr2;
}