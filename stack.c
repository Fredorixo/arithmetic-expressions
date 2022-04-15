// Implements stack.h

#include <stdio.h>

#include "stack.h"

void InitStack(STACK *S) {
    S->T = -1;
}

int  isFull(STACK *S) {
    return S->T == MAX_SIZE_STACK - 1;
}

int  isEmpty(STACK *S) {
    return S->T == -1;
}

void makeEmpty(STACK *S) {
    S->T = -1;
}

char*  Push(STACK *S, char *value) {
    if(!isFull(S)) {
        S->T++;
        S->D[S->T] = value;
        return S->D[S->T];
    }
    else {
        return NULL;
    }
}

char*  Pop(STACK *S) {
    if(isEmpty(S)) {
        return NULL;
    }
    else {
        S->T--;
        return S->D[S->T + 1];
    }
}

char* Top(STACK *S) {
    if(!isEmpty(S)) {
        return S->D[S->T];
    }

    return NULL;
}

int Size(STACK *S) {
    return S->T + 1;
}

void PrintStack(STACK *S) {
    for(int i=0; i<=S->T; i++) {
        printf("%s ",S->D[i]);
    }
    printf("\n\n");
}