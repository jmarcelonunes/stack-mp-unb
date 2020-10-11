#define CATCH_CONFIG_MAIN

#ifndef _Catch
  #define _Catch
    #include "catch.hpp"
#endif

#ifndef _Stack_library
  #define _Stack_library
    #include "pilha.h"
#endif

TEST_CASE("Criar uma pilha vazia com um tamanho máximo de elementos")
{
  Stack *stack;
  stack = create_stack(4);
  REQUIRE( stack != NULL );
  REQUIRE( stack->maxSize == 4 );
  REQUIRE( stack->actualSize == 0 );
}

TEST_CASE("Empilhar um elemento do tipo inteiro")
{
  Stack *stack;
  int item = 5;
  stack = create_stack(3);
  push(stack, &item);

  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 1 );
  REQUIRE( stack->top->itemType->data == &item);
}

TEST_CASE("Empilha dois inteiros e desempilha um elemento da pilha")
{
  Stack *stack;
  int item1 = 5;
  int item2 = 2;
  void * popped_item;

  stack = create_stack(3);
  push(stack, &item1);
  push(stack, &item2);
  popped_item = pop(stack);
  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 1 );
  REQUIRE( stack->top->itemType->data == &item1);
  REQUIRE(*(int *)popped_item == item2);
}

TEST_CASE("Empilha um inteiro e um char e desempilha o elemento tipo char")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  void * popped_item;

  stack = create_stack(3);
  push(stack, &item1);
  push(stack, &item2);
  popped_item = pop(stack);
  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 1 );
  REQUIRE( stack->top->itemType->data == &item1);
  REQUIRE(*(char *)popped_item == item2);
}

TEST_CASE("Destroi uma pilha de 3 elementos")
{
  Stack *stack = NULL;
  int item1 = 5;
  char item2 = 'c';
  int item3 = 10;

  stack = create_stack(3);
  push(stack, &item1);
  push(stack, &item2);
  push(stack, &item3);
  destroy_stack(&stack);
  REQUIRE( stack == NULL );
}

TEST_CASE("Tenta empilhar em uma pilha já cheia")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  float item3 = 10;
  float item4 = 20;

  printf("---------------------------------- Teste pilha cheia ----------------------------------\n");
  stack = create_stack(3);
  push(stack, &item1);
  push(stack, &item2);
  push(stack, &item3);
  push(stack, &item4);

  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 3 );
  REQUIRE( stack->top->itemType->data == &item3);
  printf("----------------------------------\n");
}

TEST_CASE("Empilha 2 elementos e tenta desempilhar três elementos")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  printf("---------------------------------- Teste pilha vazia ----------------------------------\n");
  stack = create_stack(2);
  push(stack, &item1);
  push(stack, &item2);
  pop(stack);
  pop(stack);
  pop(stack);

  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 0 );
  REQUIRE( stack->top == NULL);
  printf("----------------------------------\n");
}

TEST_CASE("Empilha 2 elementos verifica se a pilha está cheia")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  bool full = false;
  stack = create_stack(2);
  push(stack, &item1);
  push(stack, &item2);
  full = is_full(stack);
  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 2 );
  REQUIRE( full == true);
}

TEST_CASE("Verifica se a pilha está vazia")
{
  Stack *stack;
  bool empty = false;
  stack = create_stack(2);
  empty = is_empty(stack);
  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 0 );
  REQUIRE( empty == true);
}


TEST_CASE("Empilha dois elementos, desempilha os mesmos e verifica se a pilha está vazia")
{
  Stack *stack;
  bool empty = false;
  int item1 = 5;
  char item2 = 'c';
  stack = create_stack(2);
  push(stack, &item1);
  push(stack, &item2);
  pop(stack);
  pop(stack);
  empty = is_empty(stack);
  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 0 );
  REQUIRE( empty == true);
}

TEST_CASE("Retorna o top da pilha")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  StackNode *s = NULL;
  stack = create_stack(2);
  push(stack, &item1);
  push(stack, &item2);
  s = top(stack);
  REQUIRE( stack != NULL );
  REQUIRE( s->itemType->data == &item2);
}

TEST_CASE("Cria uma pilha e aumenta seu tamanho máximo")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  char item3 = 'b';
  StackNode *s = NULL;
  stack = create_stack(2);
  push(stack, &item1);
  push(stack, &item2);
  
  if(set_size(stack, 3)){
    push(stack, &item3);
  }
  s = top(stack);
  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 3);
  REQUIRE( stack->maxSize == 3);
  REQUIRE(s->itemType->data == &item3);
}

TEST_CASE("Cria uma pilha e diminui seu tamanho")
{
  Stack *stack;
  int item1 = 5;
  char item2 = 'c';
  bool size = false;
  stack = create_stack(2);
  push(stack, &item1);
  push(stack, &item2);
  printf("---------------------------------- Teste redução pilha ----------------------------------\n");
  size = set_size(stack, 1);

  REQUIRE( stack != NULL );
  REQUIRE( stack->actualSize == 2);
  REQUIRE( stack->maxSize == 2);
  REQUIRE(size == false);
  printf("----------------------------------\n");
}

