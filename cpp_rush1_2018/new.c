/*
** EPITECH PROJECT, 2019
** new
** File description:
** kevin
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "new.h"
#include "object.h"

char *itoa(int i, char *b)
{
    char const *digit = "0123456789";
    char *p = b;
    int j = i;

    if (i == 0)
        return("0");
    if (i < 0) {
        *p++ = '-';
        i *= -1;
    }
    while (j) {
        ++p;
        j = j/10;
    }
    *p = '\0';
    while (i) {
        *--p = digit[i%10];
        i = i/10;
    }
    return b;
}

Object *new(Class *this, ...)
{
    Object *new = NULL;
    va_list ap;

    va_start(ap, this);
    new = va_new(this, &ap);
    va_end(ap);
    return (new);
}

Object  *va_new(Class *this, va_list* ap)
{
    Object *new = NULL;

    if (!(new = malloc(this->__size__)))
        raise("out of memory");
    memcpy(new, this, this->__size__);
    if (this->__ctor__)
        this->__ctor__(new, ap);
    return (new);
}

void delete(Object *ptr)
{
    Class *lol;

    if (ptr == NULL)
        return;
    lol = (Class *)ptr;
    if (lol->__dtor__)
        lol->__dtor__(ptr);
    free(ptr);
}
