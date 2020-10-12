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

Stack* create_stack(int);
void push(Stack *, void *);
void* pop(Stack *);
void* top(Stack *);
bool set_size(Stack *, int);
bool is_full(Stack *);
bool is_empty(Stack *);
void destroy_stack(Stack **);