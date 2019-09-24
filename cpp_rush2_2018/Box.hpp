/*
** EPITECH PROJECT, 2019
** Box.hpp
** File description:
** kevin
*/

#ifndef _BOX_HPP__
#define _BOX_HPP__

#include "Wrap.hpp"

class Box : public Wrap{
    public:
        Box(std::string name);
        void isTaken() const;
        void openMe();
        void closeMe();
        bool wrapMeThat(Object *);
};

#endif
