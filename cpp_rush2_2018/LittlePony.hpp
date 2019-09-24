/*
** EPITECH PROJECT, 2019
** LittlePony.hpp
** File description:
** kevin
*/

#ifndef _LITTLEPONY_HPP__
#define _LITTLEPONY_HPP__

#include "Toy.hpp"

class LittlePony : public Toy {
    public:
        LittlePony(const std::string);
        void isTaken() const;
        void openMe();
        void closeMe();
        bool wrapMeThat(Object *);
};

#endif
