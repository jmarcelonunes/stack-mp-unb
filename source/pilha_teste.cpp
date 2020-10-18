/**
 * @file pilha_teste.cpp
 * @author João Marcelo Nunes Chaves
 * @brief Arquivo de testes para a biblioteca de pilha implementadas por lista encadeada
 * @version 1.0
 * @date 2020-10-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define CATCH_CONFIG_MAIN

#ifndef _Catch
  #define _Catch
    #include "catch.hpp"
#endif

#ifndef _Stack_library
  #define _Stack_library
    #include "pilha.h"
#endif

/**
 * @brief Test case para testar a criação de uma pilha
 * 
 * Aceitação ocorre com uma pilha alocado em memória e com um tamanho máximo definido na chamada da função
 * A pilha também deve estar vazia
 */
TEST_CASE("Criar uma pilha vazia com um tamanho máximo de elementos")
{
  Stack *stack;
  stack = createStack(4);
  REQUIRE( stack->maxSize == 4 );
  REQUIRE( stack->actualSize == 0 );
}

/**
 * @brief Test case para empilhar um elemento na pilha
 * 
 * Ao final do teste, a pilha deve ter sido criada, seu tamanho deve ser de 1 e 
 * o elemento passado na função push deve estar no topo da pilha.
 */
TEST_CASE("Empilhar um elemento do tipo inteiro")
{
  Stack *stack;
  int item = 5;
  stack = createStack(3);
  void *top_item;
  push(stack, &item);
  top_item = top(stack);
  REQUIRE( stack->actualSize == 1 );
  REQUIRE( top_item == &item);
}

/**
 * @brief Test case que empilha 2 elementos e desempilha um elemento da pilha.
 * Aceitação ocorre com a pilha com o tamanho de 1 elemento, o elemento retirado sendo
 * igual ao último elemento inserido e o topo da pilha com o primeiro elemento inserido.
 */
TEST_CASE("Empilha dois inteiros e desempilha um elemento da pilha")
{
  Stack *stack;
  int item1 = 5;
  int item2 = 2;
  void *popped_item;
  void *top_item;
  stack = createStack(3);
  push(stack, &item1);
  push(stack, &item2);
  popped_item = pop(stack);
  top_item = top(stack);
  REQUIRE( stack->actualSize == 1 );
  REQUIRE( top_item == &item1);
  REQUIRE(*(int *)popped_item == item2);
}

/**
 * @brief Test case para testar a capacidade da pilha em empilhar diferentes tipos de elementos.
 * Aceitação ocorre com a pilha criada, seu tamanho igual a 1, seu topo como o primeiro elemento empilhado
 * e o elemento retirado sendo o char que foi empilhado por último.
 * 
 */
TEST_CASE("Empilha um inteiro e um char e desempilha o elemento tipo char")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  void *popped_item;
  void *top_item;

  stack = createStack(3);
  push(stack, &item1);
  push(stack, &item2);
  popped_item = pop(stack);
  top_item = top(stack);
  REQUIRE( stack->actualSize == 1 );
  REQUIRE( top_item == &item1);
  REQUIRE(*(char *)popped_item == item2);
}

/**
 * @brief Test case para testar a capacidade da pilha em empilhar diferentes tipos de elementos.
 * Aceitação ocorre com a pilha criada, seu tamanho igual a 1, seu topo como o primeiro elemento empilhado
 * e o elemento retirado sendo o char que foi empilhado por último.
 * 
 */
TEST_CASE("Empilha um inteiro e um char, desempilha o elemento tipo char e empilha um float")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  float item3 = 10000;
  void *popped_item;
  void *top_item;

  stack = createStack(3);
  push(stack, &item1);
  push(stack, &item2);
  popped_item = pop(stack);
  push(stack, &item3);
  top_item = top(stack);
  REQUIRE( stack->actualSize == 2 );
  REQUIRE( top_item == &item3);
  REQUIRE(*(char *)popped_item == item2);
}

/**
 * @brief Test case para a destruição da pilha na memória.
 * Aceitação ocorre com o ponteiro da pilha sendo NULL.
 * 
 */
TEST_CASE("Destroi uma pilha de 3 elementos")
{
  Stack *stack = NULL;
  int item1 = 5;
  char item2 = 'c';
  int item3 = 10;

  stack = createStack(3);
  push(stack, &item1);
  push(stack, &item2);
  push(stack, &item3);
  destroyStack(&stack);
  REQUIRE( stack == NULL );
}

/**
 * @brief Test case para empilhar em um pilha que já está com capacidade máxima
 * Aceitação ocorre com a pilha com o número de elementos do seu tamanho máximo e
 * o topo sendo o último elemento permitido inserido.
 */
TEST_CASE("Tenta empilhar em uma pilha já cheia")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  float item3 = 10;
  float item4 = 20;
  void *top_item;

  printf("---------------------------------- Teste pilha cheia ----------------------------------\n");
  stack = createStack(3);
  push(stack, &item1);
  push(stack, &item2);
  push(stack, &item3);
  push(stack, &item4);
  top_item = top(stack);
  REQUIRE( stack->actualSize == 3 );
  REQUIRE( top_item == &item3);
  printf("----------------------------------\n");
}

/**
 * @brief Test case para desempilhar em um pilha vazia
 * Ocorre um print para o usuário avisando que a pilha está vazia.
 * Criterio de aceitação ocorre com a pilha criada, seu tamanho em 0 e
 * seu topo como NULL.
 */
TEST_CASE("Empilha 2 elementos e tenta desempilhar três elementos")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  printf("---------------------------------- Teste pilha vazia ----------------------------------\n");
  stack = createStack(2);
  push(stack, &item1);
  push(stack, &item2);
  pop(stack);
  pop(stack);
  pop(stack);

  REQUIRE( stack->actualSize == 0 );
  REQUIRE( stack->top == NULL);
  printf("----------------------------------\n");
}

/**
 * @brief Test case para verificar se a pilha está cheia.
 * Aceitação ocorre com a pilha criada, seu tamanho como o tamanho máximo da pilha e
 * o retorno da função is_full deve ser true.
 * 
 */

TEST_CASE("Empilha 2 elementos verifica se a pilha está cheia")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  bool full = false;
  stack = createStack(2);
  push(stack, &item1);
  push(stack, &item2);
  full = isFull(stack);
  REQUIRE( stack->actualSize == 2 );
  REQUIRE( full == true);
}

/**
 * @brief Test case para verificar se a pilha está vazia.
 * Aceitação ocorre com uma pilha criada, seu tamanho atual como 0
 * e o retorno da função is_empty como true.
 * 
 */

TEST_CASE("Verifica se a pilha está vazia")
{
  Stack *stack;
  bool empty = false;
  stack = createStack(2);
  empty = isEmpty(stack);
  REQUIRE( stack->actualSize == 0 );
  REQUIRE( empty == true);
}

/**
 * @brief Test case que empilha dois elementos, desempilha os mesmos e verifica se a pilha está vazia
 * Aceitação ocorre com a pilha criada, seu tamanho em zero e o retorno da função is_empty como true
 */
TEST_CASE("Empilha dois elementos, desempilha os mesmos e verifica se a pilha está vazia")
{
  Stack *stack;
  bool empty = false;
  int item1 = 5;
  char item2 = 'c';
  stack = createStack(2);
  push(stack, &item1);
  push(stack, &item2);
  pop(stack);
  pop(stack);
  empty = isEmpty(stack);
  REQUIRE( stack->actualSize == 0 );
  REQUIRE( empty == true);
}

/**
 * @brief Test case para retornar o topo da pilha
 * Aceitação ocorre com o elemento retornado da função top como sendo, de fato, o topo da pilha.
 * 
 */
TEST_CASE("Retorna o top da pilha")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  void *s = NULL;
  stack = createStack(2);
  push(stack, &item1);
  push(stack, &item2);
  s = top(stack);
  REQUIRE( s == &item2);
}

/**
 * @brief Test case para testar o aumento do tamanho máximo da pilha.
 * Aceitação ocorre com tamanho da pilha atualizado, seu tamanho máximo atualizado e 
 * o topo sendo o último elemento inserido após a mudança de tamanho máximo.
 * 
 */
TEST_CASE("Cria uma pilha e aumenta seu tamanho máximo")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  char item3 = 'b';
  void *s = NULL;
  stack = createStack(2);
  push(stack, &item1);
  push(stack, &item2);
  
  if(setSize(stack, 3)){
    push(stack, &item3);
  }
  s = top(stack);
  REQUIRE( stack->actualSize == 3);
  REQUIRE( stack->maxSize == 3);
  REQUIRE( s == &item3);
}

/**
 * @brief Test case para a diminuição do tamanho da pilha
 * Aceitação ocorre com um print para o usuário avisando sobre a falha e sobre a por que da falha (perda de dados),
 * pilha criada, seu tamanho máximo ainda sendo o tamanho inicial e seu tamanho atual sendo igual ao tamanho máximo inicial.
 * O retorno da função size deve ser false.
 * 
 */
TEST_CASE("Cria uma pilha e diminui seu tamanho")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  bool size = false;
  stack = createStack(2);
  push(stack, &item1);
  push(stack, &item2);
  printf("---------------------------------- Teste redução pilha ----------------------------------\n");
  size = setSize(stack, 1);

  REQUIRE( stack->actualSize == 2);
  REQUIRE( stack->maxSize == 2);
  REQUIRE(size == false);
  printf("----------------------------------\n");
}

