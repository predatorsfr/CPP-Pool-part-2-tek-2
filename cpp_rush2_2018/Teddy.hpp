/*
** EPITECH PROJECT, 2019
** Teddy.hpp
** File description:
** kevin
*/

#ifndef _TEDDY_HPP__
#define _TEDDY_HPP__

#include "Toy.hpp"

class Teddy : public Toy {
    public:
        Teddy(const std::string);
        void isTaken() const;
        void openMe();
        void closeMe();
        bool wrapMeThat(Object *);
};

#endif
