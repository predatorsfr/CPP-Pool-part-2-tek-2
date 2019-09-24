/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    this->x = 0;
    this->y = 0;
    return;
}

static Object *Point_add(const Object *this, const Object *other)
{
    Class *good = (Class *)this;
    Class *welcome = (Class *)other;
    PointClass *add = malloc(good->__size__);
    PointClass *add2 = malloc(welcome->__size__);

    if(!add || !add2)
        raise("out of memory");
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x += add2->x;
    add->y += add2->y;
    free(add2);
    return (add);
}

static Object *Point_sub(const Object *this, const Object *other)
{
    Class *good = (Class *)this;
    Class *welcome = (Class *)other;
    PointClass *add = malloc(good->__size__);
    PointClass *add2 = malloc(welcome->__size__);

    if(!add || !add2)
        raise("out of memory");
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x -= add2->x;
    add->y -= add2->y;
    free(add2);
    return (add);
}

static char const *Point_string(Object *this)
{
   Class *point = (Class *)this;
   char *nb1 = malloc(sizeof(int));
   char *nb2 = malloc(sizeof(int));
   int size = 9;
   char *str;

   PointClass *tt = (PointClass *)point;
   if (!nb1 || !nb2)
    raise("out of memory");
   nb1 = itoa(tt->x, nb1);
   nb2 = itoa(tt->y, nb2);
   size = size + strlen(nb1) + strlen(nb2) + strlen(point->__name__);
   if (!(str = malloc(sizeof(char) * size)))
        raise("out of memory");
   snprintf(str, size, "<%s (%s, %s)>",point->__name__, nb1, nb2);
   free(nb1);
   free(nb2);
   return(str);
}

static PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_string,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

Class   *Point = (Class *)&_description;
