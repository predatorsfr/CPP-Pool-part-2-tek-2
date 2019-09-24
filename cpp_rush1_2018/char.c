/*
** EPITECH PROJECT, 2019
** char
** File description:
** kevin
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "char.h"

#include "new.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = 0;
    this->x = (char)va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    this->x = 0;
    return;
}

static Object *Char_add(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    CharClass *add;
    CharClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x = add->x + add2->x;
    free(add2);
    return (add);
}

static Object *Char_sub(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    CharClass *add;
    CharClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x = add->x - add2->x;
    free(add2);
    return (add);
}

static Object *Char_mult(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    CharClass *add;
    CharClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x = add->x * add2->x;
    free(add2);
    return (add);
}

static Object *Char_div(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    CharClass *add;
    CharClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    if ((int)add2->x == 0)
        raise("div by 0");
    add->x = add->x / add2->x;
    free(add2);
    return (add);
}

static bool Char_eq(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    CharClass *add;
    CharClass *add2;

    if (!this || !other)
        return (false);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    if (add->x == add2->x)
        return (true);
    return (false);
}

static bool Char_lt(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    CharClass *add;
    CharClass *add2;

    if (!this || !other)
        return (false);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    if (add->x < add2->x)
        return (true);
    return (false);
}

static bool Char_gt(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    CharClass *add;
    CharClass *add2;

    if (!this || !other)
        return (false);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    if (add->x > add2->x)
        return (true);
    return (false);
}

static char const *Char_string(Object *this)
{
    Class *poChar;
    CharClass *tt;
    int size = 1000;
    char *str;

    if (!this)
        return (NULL);
    poChar = (Class *)this;
    tt = (CharClass *)poChar;
    size += strlen(poChar->__name__);
    str = malloc(sizeof(char) * size);
    if (str == NULL)
         raise("out of memory");
    snprintf(str, size, "<%s (%c)>",poChar->__name__, tt->x);
    return(str);
}

static CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_string,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mult,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0
};

Class   *Char = (Class *)&_description;
