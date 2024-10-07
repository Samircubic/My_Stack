#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

#include "../headers/push_pop.h"

int push (stack_t *stk, double elem)
{
    CHECK_BIRD;

    if (stk->size == stk->capacity) //TODO func
    {
        int new_capacity = stk->capacity * MEMORY_MULTIPLIER;

        stk->data = ((stack_elem_t*) realloc (stk->data - OFFSET_BIRD, ((long unsigned int) (new_capacity + 3)) * sizeof (stack_elem_t))) + OFFSET_BIRD; //TODO magic-const
        stk->capacity = new_capacity;

        plant_bird (stk); //заполнение птичек func static
    }

    stk->data[stk->size] = elem;
    stk->size++;

    for (int i = stk->size; i < stk->capacity; i++) //TODO
    {
        stk->data[i] = NAN;
    }

    CHECK_BIRD;
    return 0;
}

//----------------------------------------------------------------------

int pop (stack_t *stk, double *elem)
{
    CHECK_BIRD;

    if (stk->size + DELTA_REALLOC < stk->capacity / MEMORY_MULTIPLIER) //TODO func
    {
        int new_capacity = stk->capacity / MEMORY_MULTIPLIER;

        stk->data = ((stack_elem_t*) realloc (stk->data - OFFSET_BIRD, ((long unsigned int) (new_capacity + 3)) * sizeof (stack_elem_t))) + OFFSET_BIRD; //TODO rename
        stk->capacity = new_capacity;

        plant_bird (stk); //заполнение птичек func static
    }

    stk->size--;
    *elem = stk->data[stk->size];
    stk->data[stk->size] = NAN;

    CHECK_BIRD;
    return 0; //TODO return error
}

//----------------------------------------------------------------------
