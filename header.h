#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  t_flags
{
    int         d;
    int         i;
    char        error;
    int         arg_error;
    int         order_error;
}               s_flags;

int             imgcmp(int , char **);

s_flags         flags(int , char **, s_flags);

#endif HEADER_H
