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