/*
** EPITECH PROJECT, 2019
** Toy.cpp
** File description:
** kevin
*/

#include "Teddy.hpp"
#include "Toy.hpp"
#include "LittlePony.hpp"


Object::Object(std::string name)
{
    _gift = NULL;
    _name = name;
}

void Object::printname() const
{
    std::cout << _name << std::endl;
}

Object *Object::getObject()
{
    return _gift;
}

void Object::isTaken() const
{
}

void Object::openMe()
{
}

void Object::closeMe()
{
}

bool Object::wrapMeThat(Object *)
{
    return false;
}

Toy::Toy(std::string name)
:Object(name)
{
}

Toy::~Toy()
{
}

Teddy::Teddy(const std::string name)
:Toy(name)
{
    _name = name;
}

LittlePony::LittlePony(const std::string name)
:Toy(name)
{
    _name = name;
}

void Toy::isTaken() const
{
}

void Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
}

void LittlePony::isTaken() const
{
    std::cout << "yo man" << std::endl;
}

void Toy::openMe()
{
}

void Toy::closeMe()
{
}

bool Toy::wrapMeThat(Object *)
{
    return false;
}

void Teddy::openMe()
{
}

void Teddy::closeMe()
{
}

bool Teddy::wrapMeThat(Object *)
{
    return false;
}

void LittlePony::openMe()
{
}

void LittlePony::closeMe()
{
}

bool LittlePony::wrapMeThat(Object *)
{
    return false;
}
