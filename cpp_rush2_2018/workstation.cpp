/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** workstation.cpp
*/

#include "workstation.hpp"

Wrap::Wrap(std::string name)
:Object(name)
{
    _type = 0;
}

void Wrap::isTaken() const
{
    std::cout << "whistles while working";
}

void Wrap::openMe()
{
    _type = 0;
}

void Wrap::closeMe()
{
    _type = 1;
}

bool Wrap::wrapMeThat(Object *)
{
    return false;
}
