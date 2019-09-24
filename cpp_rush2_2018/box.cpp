/*
** EPITECH PROJECT, 2019
** box.cpp
** File description:
** kevin
*/

#include "Box.hpp"

Box::Box(std::string name)
:Wrap(name)
{
}

void Box::isTaken() const
{
    std::cout << "whistles while working";
}

void Box::openMe()
{
    _type = 0;
}

void Box::closeMe()
{
    _type = 1;
}

bool Box::wrapMeThat(Object *gift)
{
    if (_type == 0 && _gift == NULL) {
        _gift = gift;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return true;
    }
    return false;
}
