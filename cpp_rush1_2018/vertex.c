/*
** EPITECH PROJECT, 2019
** vertex
** File description:
** kevin
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    return;
}

static Object *Vertex_add(const Object *this, const Object *other)
{
    Class *good = (Class *)this;
    Class *welcome = (Class *)other;
    VertexClass *add = malloc(good->__size__);
    VertexClass *add2 = malloc(welcome->__size__);

    if(!add || !add2)
        raise("out of memory");
    memcpy(add, good, good->__size__);
    memcpy(add2, welcome, welcome->__size__);
    add->x += add2->x;
    add->y += add2->y;
    add->z += add2->z;
    free(add2);
    return (add);
}

static Object *Vertex_sub(const Object *this, const Object *other)
{
    Class *good = (Class *)this;
    Class *welcome = (Class *)other;
    VertexClass *sub = malloc(good->__size__);
    VertexClass *sub2 = malloc(welcome->__size__);

    if (sub == NULL || sub2 == NULL)
        raise("out of memory");
    memcpy(sub, good, good->__size__);
    memcpy(sub2, welcome, welcome->__size__);
    sub->x -= sub2->x;
    sub->y -= sub2->y;
    sub->z -= sub2->z;
    free(sub2);
    return (sub);
}

static char const *Vertex_string(Object *this)
{
    Class *point = (Class *)this;
    char *nb1 = malloc(sizeof(int));
    char *nb2 = malloc(sizeof(int));
    char *nb3 = malloc(sizeof(int));
    int size = 12;
    char *str;

    VertexClass *tt = (VertexClass *)point;
    if (!nb1 || !nb2 || !nb3)
        raise("out of memory");
    nb1 = itoa(tt->x, nb1);
    nb2 = itoa(tt->y, nb2);
    nb3 = itoa(tt->z, nb3);
    size = size + strlen(nb1) + strlen(nb2) + strlen(nb3) + strlen(point->__name__);
    if (!(str = malloc(sizeof(char) * size)))
        raise("out of memory");
    snprintf(str, size, "<%s (%s, %s, %s)>",point->__name__, nb1, nb2, nb3);
    free(nb2);
    free(nb3);
    return(str);
}

static VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_string,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

Class   *Vertex = (Class *)&_description;
