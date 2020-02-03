#include "header.h"

/* Привет, это будет библиотека для поиска картинок

Есть несколько простых правил для использования:
    1. Сперва идут флаги, а только потом остальные аргументы
    2. Сдедующий аргумент после флагов - название картинки, а только
    директория для поиска

Ну вродь все, удачи в использовании.
*/

s_flags     flags(int count, char **argument, s_flags flag)
{
    int     tmp = 1, i = 1;

    while (tmp < count && argument[tmp][0] == '-')
    {
        while (argument[tmp][i] != '\0')
        {
            if (argument[tmp][i] == 'd')
                flag.d = 1;
            else if (argument[tmp][i] == 'i')
                flag.i = 1;
            else
                flag.error = argument[tmp][i];
            i++;
        }
        tmp++;
        i = 1;
    }
    (count - tmp) == 2 ? tmp : (flag.arg_error = 1);
    if (flag.arg_error == 0 && argument[tmp + 1][0] == '-')
        flag.order_error = 1;
    return (flag);
}

int     imgcmp(int count, char **argument)
{
    s_flags flag;

    flag.error = ' ';
    flag.d = 1;
    flag.order_error = 0;
    flag.arg_error = 0;
    flag.i = 0;

    flag = flags(count, argument, flag);
    if (flag.error != ' ')
    {
        printf("Incorrect flag -%c, try to use -di\n", flag.error);
        return (-1);
    }
    if (flag.i == 1)
    {
        printf("Welcome to imgcmplib :)\n");
        return (0);
    }
    if (flag.arg_error == 1)
    {
        printf("Incorrect argument\n");
        return (-1);
    }
    if (flag.order_error == 1)
    {
        printf("Flag %s after argument\n", argument[count - 1]);
        return (-1);
    }
    return (0);
}

int     main(int argc, char **argv)
{
    imgcmp(argc, argv);
    return (0);
}