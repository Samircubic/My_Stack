#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

#include "../headers/safety.h"
    //TODO func- verify check
void plant_bird (stack_t *stk) //TODO my_assert -Dassert
{
    STACK_ASSERT;

    stk->data[-1] = TORTURE_CKAMBER; //TODO сделай возможность легко менять типы через дефанйы

    stk->data[stk->capacity + 1] = TORTURE_CKAMBER;
}

//----------------------------------------------------------------------

void check_bird (stack_t *stk, const char *file, int line) //TODO static-func
{
    STACK_ASSERT;

    if (compare_double (stk->data[-1], TORTURE_CKAMBER) != EQUALS)
    {
        printf (red "Attack on the bird!" black "\n");
        printf (blue "%s" black ", line = " blue "%d" black "\n", file, line);
        printf ("The left bird is gone\n");

        assert (0);
    }

    if (compare_double (stk->data[stk->capacity + 1], TORTURE_CKAMBER) != EQUALS)
    {
        printf (red "Attack on the bird!" black "\n");
        printf ("The right bird is gone\n");

        assert (0);
    }
}

//----------------------------------------------------------------------

int stack_error (stack_t *stk, const char *file, int line)
{
    if (stk == 0) //TODO macro-local MACRO_
    {
        printf (red "ERROR " black "from " blue "%s" black ": " blue "%d\n" black, file, line);
        printf ("stk == " red "0" black "\n");

        assert (0);
    }

    if (stk->data == 0)
    {
        printf (red "ERROR " black "from " blue "%s" black ": " blue "%d\n" black, file, line);
        printf ("stk->data == " red "0" black "\n");

        assert (0);
    }

    if ((stk->size > stk->capacity && stk->capacity > 0 )|| stk->size < 0)
    {
        printf (red "ERROR " black "from " blue "%s" black ": " blue "%d\n" black, file, line);
        printf ("Incorrect value, size = " red "%d" black "\n", stk->size);

        assert (0);
    }

    if (stk->capacity < 0)
    {
        printf (red "ERROR " black "from " blue "%s" black ": " blue "%d\n" black, file, line);
        printf ("Incorrect value, capacity = " red "%d" black "\n", stk->capacity);

        assert (0);
    }
    return 0;
}

//----------------------------------------------------------------------

