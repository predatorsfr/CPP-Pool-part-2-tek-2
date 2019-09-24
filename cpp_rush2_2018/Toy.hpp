/*
** EPITECH PROJECT, 2019
** Toy.hpp
** File description:
** kevin
*/

#ifndef _TOY_HPP__
#define _TOY_HPP__

#include "Object.hpp"

class Toy : public Object {
    public:
        Toy(std::string);
        ~Toy();
        void isTaken() const;
        void openMe();
        void closeMe();
        bool wrapMeThat(Object *);
    protected:
       std::string  _name;
};

#endif
