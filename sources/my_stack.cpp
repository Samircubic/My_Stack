#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h> //TODO -E
#include "../headers/my_stack.h" //TODO -I/headers g++
#include "../headers/data_typ"

int main ()
{
    stack_t *stk = ctor_stack (); //static - func and ... функция статик транслирует код функции только один раз в один файл, вполне можно использовать для защиты программы от взлома через некоторые функции
    assert (stk);
    stk->creation_file = "stk"; //TODO __FILE__, read about # aqnd ## in define, __FUNC__
    stk->creation_line = 52;

    get_point_stack (stk); //TODO rename swap with ctor

    DUMP; //TODO ifdef DUMP(stk)

    for (int i = 0; i < 100; i++)
    {
        push (stk, 1);
    }

    // steck_error (stk);

    DUMP;

    for (int i = 0; i < 200; i++)
    {
        push (stk, 2);
    }

    DUMP;

    for (int i = 0; i < 200; i++)
    {
        double number = 0;
        pop (stk, &number);
        printf ("%lf\n", number);
    }

    DUMP;

    dtor_stack (stk);
    return 0;
}

//----------------------------------------------------------------------

stack_t* ctor_stack ()
{
    stack_t *stk = (stack_t*) calloc (1, sizeof (stack_t));
    assert (stk);

    return stk;
}

//----------------------------------------------------------------------

void get_point_stack (stack_t *stk) //TODO file
{
    assert (stk);

    stk->data = ((stack_elem_t*) calloc (INITIAL_LENGHT + 3, sizeof (stack_elem_t))) + OFFSET_BIRD; //TODO magic-const
    assert (stk->data);

    stk->size = 0;
    stk->capacity = INITIAL_LENGHT;

    plant_bird (stk); //заполнение птичек func static

    for (int i = stk->size; i < stk->capacity; i++) //TODO Func memcpy
    {
        stk->data[i] = NAN;
    }
}

//----------------------------------------------------------------------

int dump (stack_t *stk, const char *file, int line)
{
    CHECK_BIRD;

    printf ("ctack_t [" blue "%p" black "]\n", stk);

    printf ("called from " green "%s" black ": " green "%d\n" black, file, line);
    printf ("\tname " green "%s " black "born at " green "%d" black ": "green"\n" black, stk->creation_file, stk->creation_line);

    printf ("\t{\n");

    printf ("\t\tcapacity = " green "%d\n" black, stk->capacity); //TODO one - printf(""
//TODO                                                                                "",)
    printf ("\t\tsize = " green "%d\n" black, stk->size); //TODO 331 
    printf ("\t\tdata [" blue "%p" black "]\n", stk->data); //TODO отложим всё с препроцессором, дописать хэш, moew meow

    printf ("\t\t{\n");

    for (int i = 0; i < stk->size; i++)
    {
        printf (green "\t\t\t*[%d] " black "= %lf\n", i, stk->data[i]);
    }

    for (int i = stk->size; i < stk->capacity; i++)
    {
        printf ("\t\t\t[%d] = %lf " red "(POISON)\n" black, i, stk->data[i]);
    }

    printf ("\t\t}\n");

    printf ("\t}\n");

    STACK_ASSERT;

    CHECK_BIRD;
    return 0;
}

//----------------------------------------------------------------------

int dtor_stack (stack_t *stk)
{
    CHECK_BIRD;

    for (int i = 0; i < stk->capacity; i++) //TODO func memcpy
    {
        stk->data[i] = NAN;
    }

    stk->size = POISON;
    stk->capacity = POISON;

    free (stk->data - OFFSET_BIRD);
    stk->data = 0;

    free (stk);
    stk = NULL; //TODO NULL

    return 0;
}

//----------------------------------------------------------------------

enum comparison compare_double (double x, double z)
{
    if (fabs (x - z) < EPSILONT)
    {
        return EQUALS;
    }

    if ((x - z) > EPSILONT)
    {
        return MORE;
    }

    else
    {
        return LESS;
    }
}

//----------------------------------------------------------------------

// 2) макрос dump
// 3) макрос error
// 4) макрос ctor



// вопрос как реализовать кукумбер в масиве с войд звездочками
// то есть, нам нужно одну ячейку заполнить птичкой, а на сколько нам нужно сдвинуться мы не знаем, по скольку не знаем какие данные у нас хранятся в массиве.


//вопрос, я же правильно понял что взлом происходит только через мейн файл?
