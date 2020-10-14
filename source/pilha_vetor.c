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
 * Aloca espaço de memória, atribui o tamanho máximo e atribui o tamanho atual como 0.
 * @param maxsize 
 * @return Stack* 
 */
Stack* create_stack(int maxsize)
{
    Stack* p = (Stack*) malloc(sizeof(Stack));
    p->maxSize = maxsize;
    p->vector = (ItemType *) malloc(p->maxSize * sizeof(ItemType));
    p->actualSize = 0;
    p->top = NULL;
    return p;
}

/**
 * @brief Função para empilhar elementos na pilha.
 * Recebe a pilha e o endereço de memória do elemento. 
 * Aloca memória para o elemento
 * Atribui o elemento passado como parâmetro para o endereço de memória alocado
 * Incrementa a posição da vetor e atribui o ItemType alocado para essa posição do vetor.
 * 
 * @param p 
 * @param element 
 */
void push (Stack *p, void *element){
    if(is_full(p)){
        printf("Pilha está cheia!\n");
    }
    else{
        ItemType *e = (ItemType*)malloc(sizeof(element));
        e->data = element;
        p->vector[p->actualSize++] = *e;
        free(e);
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
    if(!is_empty(p)){
        void *e = p->vector[--p->actualSize].data;
        return e;
    }else{
        void *r = NULL;
        printf("Pilha está vazia.\n");
        return r;
    }
}

/**
 * @brief Função para desalocar uma pilha por completo
 * Recebe um ponteiro de ponteiro da pilha
 * Desaloca o vetor contido na pilha
 * Desaloca o ponteiro da pilha
 * Atribui o ponteiro da pilha como NULL
 * 
 * @param p 
 */
void destroy_stack (Stack **p){
    free((*p)->vector);
    free(*p);
    *p = NULL;
}

/**
 * @brief Função para checar se a pilha está vazia
 * Verifica se a array está vazia
 * Caso esteja vazia retorna true,
 * caso contrário retorna false.
 * 
 * @param p 
 * @return true 
 * @return false 
 */
bool is_empty (Stack *p){
    if(p->actualSize == 0)
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
 * @brief Função que retorna o topo da pilha
 * Retorna o topo da pilha passada para a função
 * 
 * @param p 
 * @return StackNode* 
 */
void* top (Stack *p){
    return p->vector[p->actualSize - 1].data;
}


bool set_size (Stack *p, int size){
    if(p->actualSize < size){
        p->maxSize = size;
        p->vector = (ItemType *)realloc(p->vector, p->maxSize*sizeof(ItemType));
        return true;
    }
    else{
        printf("o tamanho da pilha não pode ser reduzido pois haverá perda de dados\n");
        return false;
    }
}

