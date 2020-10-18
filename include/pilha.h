#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode StackNode;
typedef struct stack Stack;
typedef struct itemType ItemType;

struct itemType {
    void* data;
};

struct stackNode {
    ItemType* itemType;
    StackNode* next;
};

struct stack {
    StackNode* top; //implementação por lista encadeada
    int maxSize;
    int actualSize;
    ItemType* vector; //implementação por vetor
};

Stack* createStack(int);
void push(Stack *, void *);
void* pop(Stack *);
void* top(Stack *);
bool setSize(Stack *, int);
bool isFull(Stack *);
bool isEmpty(Stack *);
void destroyStack(Stack **);