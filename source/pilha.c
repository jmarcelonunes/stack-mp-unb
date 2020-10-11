#include "pilha.h"

Stack* create_stack(int maxsize)
{
    Stack* p = (Stack*) malloc(sizeof(Stack));
    p->top = NULL;
    p->maxSize = maxsize;
    p->actualSize = 0;
    return p;
}
void push (Stack *p, void *element){
    if(p->actualSize < p->maxSize){
        StackNode* s = (StackNode*) malloc(sizeof(StackNode));
        ItemType* e = (ItemType*)malloc(sizeof(element));
        e->data = element;
        s->itemType = e;
        s->next = p->top;
        p->actualSize++;
        p->top = s;
    }
    else{
        printf("Pilha está cheia!\n");
    }

}

void* pop(Stack *p){
    if(p->top != NULL){
        StackNode* s = p->top;
        void *e = s->itemType->data;
        p->top = s->next;
        p->actualSize--;
        free(s);
        return e;
    }else{
        printf("Pilha está vazia.\n");
        int i = -1;
        void *r = &i;
        return r;
    }
}

void destroy_stack (Stack **p){
    StackNode *s = (*p)->top;
    while (s != NULL){
        StackNode *aux = s->next;
        free(s);
        s = aux;
    } 
    free(*p);
    *p = NULL;
}

