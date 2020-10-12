/**
 * @file pilha.c
 * @author João Marcelo Nunes Chaves
 * @brief Arquivo que implementa funções para a biblioteca de pilha com lista encadeada
 * @version 1.0
 * @date 2020-10-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "pilha.h"


/**
 * @brief Função para a criação da pilha. Recebe seu tamanho máximo e retorna o ponteiro da pilha criada.
 * Aloca espaço de memória, atribui um topo NULL, atribui o tamanho máximo e atribui o tamanho atual como 0.
 * @param maxsize 
 * @return Stack* 
 */
Stack* create_stack(int maxsize)
{
    Stack* p = (Stack*) malloc(sizeof(Stack));
    p->top = NULL;
    p->maxSize = maxsize;
    p->actualSize = 0;
    return p;
}

/**
 * @brief Função para empilhar elementos na pilha.
 * Recebe a pilha e o endereço de memória do elemento. 
 * Aloca memória para o nó da pilha e para o elemento a ser adicionado na pilha
 * Atribui o elemento passado para o dado na pilha.
 * Atribui o endereço de memória de itemType para o nó da pilha
 * Atribui o próximo elemento da pilha.
 * Aumenta o tamanho da pilha.
 * Atribui o topo da pilha.
 * 
 * @param p 
 * @param element 
 */
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

/**
 * @brief Função para desempilhar elementos da pilha.
 * Recebe a pilha e retira o elemento do topo
 * Atribui o novo topo.
 * Reduz o tamanho da pilha.
 * Desaloca o ponteiro retirado da pilha.
 * Retorna o endereço do elemento desempilhado.
 * 
 * @param p 
 * @return void* 
 */
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

/**
 * @brief Função para desalocar uma pilha por completo
 * Recebe um ponteiro de ponteiro da pilha
 * Realiza um loop desalocando todos os elementos até o topo (sem perder referência)
 * Desaloca o ponteiro da pilha
 * Atribui o ponteiro da pilha como NULL
 * 
 * @param p 
 */
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

/**
 * @brief Função que retorna o topo da pilha
 * Retorna o topo da pilha passada para a função
 * 
 * @param p 
 * @return StackNode* 
 */
void* top (Stack *p){
    return p->top->itemType->data;
}


/**
 * @brief Função para checar se a pilha está vazia
 * Verifica se o topo é nulo
 * Caso esteja vazia retorna true,
 * caso contrário retorna false.
 * 
 * @param p 
 * @return true 
 * @return false 
 */
bool is_empty (Stack *p){
    if(p->top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Função para verificar se a pilha está cheia
 * Caso o tamanho atual seja igual ao tamanho máximo retorna true,
 * caso contrário retorna false
 * 
 * @param p 
 * @return true 
 * @return false 
 */
bool is_full (Stack *p){
    if(p->actualSize == p->maxSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Função que realiza a mudança do tamanho máximo da pilha.
 * Verifica se é possível realizar a mudança do tamanho sem que haja perda de dados.
 * Retorna true se o tamanho pôde ser alterado ou retorna false caso o tamanho passado
 * seja menor que o tamanho atual da pilha.
 * 
 * @param p 
 * @param size 
 * @return true 
 * @return false 
 */
bool set_size (Stack *p, int size){
    if(p->actualSize < size){
        p->maxSize = size;
        return true;
    }
    else{
        printf("o tamanho da pilha não pode ser reduzido pois haverá perda de dados\n");
        return false;
    }
}

