/*
** EPITECH PROJECT, 2019
** GiftPaper.hpp
** File description:
** kevin
*/

#ifndef _GIFTPAPER_HPP__
#define _GIFTPAPER_HPP__

#include "Wrap.hpp"

class GiftPaper : public Wrap{
    public:
        GiftPaper(std::string name);
        void isTaken() const;
        void openMe();
        void closeMe();
        bool wrapMeThat(Object *);
};

#endif
