#ifndef SAFETY_H
#define SAFETY_H

//----------------------------------------------------------------------

#define red     "\033[31m"                          ///< изменения цвета вывода на красный
#define blue    "\x1b[34m"                          ///< изменения цвета вывода на синий
#define white   "\x1b[37m"                          ///< изменения цвета вывода на белый
#define green   "\x1b[32m"                          ///< изменения цвета вывода на зеленый
#define black   "\x1b[30m"                          ///< изменения цвета вывода на черный

#define STACK_ASSERT    stack_error (stk, __FILE__, __LINE__);  ///< легкая подстановка функции проверки данных стека
#define CHECK_BIRD      check_bird  (stk, __FILE__, __LINE__);  ///< легкая подстановка функция проверки целостности данных

//----------------------------------------------------------------------

enum comparison                                     ///< необходим для возврата итогов функции сранения двух даболовских чисел
{
    MORE,
    EQUALS,
    LESS
};

//----------------------------------------------------------------------

const int       INITIAL_LENGHT      = 100;          ///< начальная длина инициализации стека
const int       DELTA_REALLOC       = 10;           ///< дельтя отступа перед уменьшением массива, во избежание скачков на граничном положение
const int       MEMORY_MULTIPLIER   = 2;            ///< множитель на который массив уменьшается и увеличивается
const int       POISON              = -1;           ///< ядовитое значение
const double    POISON_ELEM_STACK   = -121620;      ///< ядовито значение для заполнения пустых пространств
const double    TORTURE_CKAMBER     = 0xFACAD;      ///< птица, определенное значение для проверки целостности данных
const int       OFFSET_BIRD         = 1;            ///< двигаемся для того чтобы оставить место птице
const double    EPSILONT            = 0.00001;      ///< минимальная погрешность

//----------------------------------------------------------------------

typedef double stack_elem_t;

typedef struct stack
{
    stack_elem_t*   data;
    int             size;
    int             capacity;
    char            *creation_file;
    int             creation_line;
} stack_t;

//----------------------------------------------------------------------

/*!
на вход принимаются два числа double для сравнения, функция возвращает итог сравнения\n
\param[in] x первый сравниваемый параметр\n
\param[in] z второй сравниваемый параметр\n
\return возврат результата сравнения
*/
enum comparison     compare_double      (double x, double z);

stack_t*            ctor_stack          ();
int                 dump                (stack_t *stk, const char *file, int line);
int                 push                (stack_t *stk, double elem);
int                 dtor_stack          (stack_t *stk);
int                 pop                 (stack_t *stk, double *elem);
int                 stack_error         (stack_t *stk, const char *file, int line);
void                get_point_stack     (stack_t *stk);
void                plant_bird          (stack_t *stk);
void                check_bird          (stack_t *stk, const char *file, int line);

//----------------------------------------------------------------------

#endif  //SAFETY_H
