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

TEST_CASE("Empilha um inteiro e um char e retira desempilha o elemento tipo char")
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