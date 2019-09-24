/*
** EPITECH PROJECT, 2019
** gift.cpp
** File description:
** kevin
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper(std::string name)
:Wrap(name)
{
}

void GiftPaper::isTaken() const
{
    std::cout << "whistles while working";
}

void GiftPaper::openMe()
{
    _type = 0;
}

void GiftPaper::closeMe()
{
    _type = 1;
}

bool GiftPaper::wrapMeThat(Object *gift)
{
    if (_gift == NULL) {
        _gift = gift;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return true;
    }
    return false;
}
