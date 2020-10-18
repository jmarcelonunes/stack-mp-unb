/**
 * @file pilha.h
 * @author João Marcelo Nunes Chaves
 * @brief Arquivo header que define os protótipos das funções utilizadas e as estruturas definidas.
 * @version 1.0
 * @date 2020-10-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * @brief Define o tipos StackNode.
 * 
 */
typedef struct stackNode StackNode;
/**
 * @brief Define o tipos Stack.
 * 
 */
typedef struct stack Stack;
/**
 * @brief Define o tipo itemType.
 * 
 */
typedef struct itemType ItemType;

/**
 * @brief Estrutura do itemType. 
 * O conteúdo é armazenado no atributo data. 
 * Data é um ponteiro para void, 
 * permitindo assim armazenar os mais variados tipos.
 * 
 */
struct itemType {
    void* data;
};

/**
 * @brief Estrutura do nó da implementação da pilha por lista encadeada.
 * Possui um ponteiro next para o próximo item.
 * Possui um ponteiro para o itemType armazenado no nó.
 * 
 */
struct stackNode {
    ItemType* itemType;
    StackNode* next;
};

/**
 * @brief Estrutura geral da pilha. Possui um ponteiro para o nó do topo, utilizado na implementação
 * por lista encadeada.
 * Um inteiro maxSize que define o tamanho máximo da pilha.
 * Um inteiro actualSize que define o tamanho atual da pilha.
 * Um vetor de itemType chamado vector, utilizado na implementação por vetor.
 * 
 */
struct stack {
    StackNode* top; //implementação por lista encadeada
    int maxSize;
    int actualSize;
    ItemType* vector; //implementação por vetor
};

/**
 * @brief Protótipo da função de criar a pilha.
 * 
 * @return retorna um ponteiro para a pilha.
 */
Stack* createStack(int);
/**
 * @brief Protótipo da função de empilhar um item.
 * Recebe a pilha e elemento (ponteiro para void).
 * 
 * @return
 */
void push(Stack *, void *);
/**
 * @brief Protótipo da função de desempilhar um item.
 * Recebe a pilha.
 * 
 * @return O ponteiro para o item retirado.
 */
void* pop(Stack *);
/**
 * @brief Retorna o topo da pilha.
 * 
 * @return Retorna o ponteiro para o elemento no topo. 
 */
void* top(Stack *);
/**
 * @brief Altera o tamanho da pilha. Recebe a pilha e um inteiro com
 * o tamanho solicitado.
 * 
 * @return true se foi possível realizar a alteração de tamanho.
 * @return false se não foi possível realizar a alteração de tamanho.
 */
bool setSize(Stack *, int);
/**
 * @brief Confere se a pilha está cheia.
 * 
 * @return true se a pilha está cheia.
 * @return false se não está cheia.
 */
bool isFull(Stack *);
/**
 * @brief Confere se a pilha está vazia
 * 
 * @return true se a pilha está vazia
 * @return false se a pilha não está vazia
 */
bool isEmpty(Stack *);
/**
 * @brief Função que retira a pilha da memória.
 * 
 */
void destroyStack(Stack **);