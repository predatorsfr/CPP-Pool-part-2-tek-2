/*
** EPITECH PROJECT, 2019
** int
** File description:
** kevin
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "int.h"
#include "new.h"
#include "object.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    this->x = 0;
    return;
}

static Object *Int_add(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    IntClass *add;
    IntClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x += add2->x;
    free(add2);
    return (add);
}

static Object *Int_sub(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    IntClass *add;
    IntClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x -= add2->x;
    free(add2);
    return (add);
}

static Object *Int_mult(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    IntClass *add;
    IntClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x = add2->x * add->x;
    free(add2);
    return (add);
}

static Object *Int_div(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    IntClass *add;
    IntClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    if (add2->x == 0)
        raise("div by 0");
    add->x = add2->x / add->x;
    free(add2);
    return (add);
}

static bool Int_eq(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    IntClass *add;
    IntClass *add2;

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
    return(false);
}

static bool Int_lt(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    IntClass *add;
    IntClass *add2;

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
    return(false);
}

static bool Int_gt(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    IntClass *add;
    IntClass *add2;

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
    return(false);
}

static char const *Int_string(Object *this)
{
    Class *point;
    char *nb1;
    IntClass *tt;
    int size = 9;
    char *str;

    if (!this)
        return (NULL);
    point = (Class *)this;
    nb1 = malloc(sizeof(int));
    tt = (IntClass *)point;
    nb1 = itoa(tt->x, nb1);
    size += strlen(nb1);
    size += strlen(point->__name__);
    str = malloc(sizeof(char) * size);
    if (str == NULL)
         raise("out of memory");
    snprintf(str, size, "<%s (%s)>",point->__name__, nb1);
    free(nb1);
    return(str);
}

static IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_string,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mult,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

Class   *Int = (Class *)&_description;
