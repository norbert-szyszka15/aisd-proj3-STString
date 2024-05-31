#include "STString.h"
#include "STStringHelpers.h"

#include <stdlib.h>
#include <stdio.h>

STString stringInit(const char *initSTString) {
    STString sts;
    sts.length = ststrlen(initSTString);
    sts.data = (char*)malloc((sts.length + 1) * sizeof(char));

    if (sts.data == NULL) {
        printf("Critical memory allocation error.\n");
        exit(1);
    }
    ststrcpy(sts.data, initSTString);

    return sts;
}


size_t stringLength(const STString *sts) {
    return sts->length;
}

void stringCat(STString *destination, const STString *source) {
    size_t newLength = destination->length + source ->length;
    destination->data = (char*)realloc(destination->data, (newLength + 1) * sizeof(char));
    if (destination->data != NULL) {
        ststrcat(destination->data, source->data);
        destination->length = newLength;
    }
}

STString stringCopy(const STString *source) {
    return stringInit(source->data);
}

int stringCompare(const STString *sts1, const STString *sts2) {
    return ststrcmp(sts1->data, sts2->data);
}


void stringFree(STString *sts) {
    if (sts->data != NULL) {
        free(sts->data);
        sts->data = NULL;
    }
    sts->length = 0;
}

void stringClean(STString *sts) {
    stringFree(sts);
}