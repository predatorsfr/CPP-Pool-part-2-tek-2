/*
** EPITECH PROJECT, 2019
** float
** File description:
** kevin
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "float.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    this->x = 0;
    return;
}

static Object *Float_add(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    FloatClass *add;
    FloatClass *add2;

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

static Object *Float_sub(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    FloatClass *add;
    FloatClass *add2;

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

static Object *Float_mult(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    FloatClass *add;
    FloatClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x *= add2->x;
    free(add2);
    return (add);
}

static Object *Float_div(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    FloatClass *add;
    FloatClass *add2;

    if (!this || !other)
        return (NULL);
    good = (Class *)this;
    welcome = (Class *)other;
    add = malloc(good->__size__);
    add2 = malloc(welcome->__size__);
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    if (add2->x == 0.0)
        raise("div by 0");
    add->x /= add2->x;
    free(add2);
    return (add);
}

static bool Float_eq(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    FloatClass *add;
    FloatClass *add2;

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

static bool Float_lt(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    FloatClass *add;
    FloatClass *add2;

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

static bool Float_gt(const Object *this, const Object *other)
{
    Class *good;
    Class *welcome;
    FloatClass *add;
    FloatClass *add2;

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

static char const *Float_string(Object *this)
{
    Class *poFloat;
    FloatClass *tt;
    int size = 1000;
    char *str;

    if (!this)
        return (NULL);
    poFloat = (Class *)this;
    tt = (FloatClass *)poFloat;
    size += strlen(poFloat->__name__);
    str = malloc(sizeof(char) * size);
    if (str == NULL)
         raise("out of memory");
    snprintf(str, size, "<%s (%f)>",poFloat->__name__, tt->x);
    return(str);
}

static FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_string,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mult,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0.0
};

Class   *Float = (Class *)&_description;
