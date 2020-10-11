#include "pilha.h"

Stack* create_stack(int maxsize)
{
    Stack* p = (Stack*) malloc(sizeof(Stack));
    p->top = NULL;
    p->maxSize = maxsize;
    p->actualSize = 0;
    return p;
}


