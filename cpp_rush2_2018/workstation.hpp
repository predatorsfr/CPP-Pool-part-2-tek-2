/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** woekstation.hpp
*/

#ifndef _WORKSTATION_HPP__
#define _WORKSTATION_HPP__

#include "Object.hpp"

class workstation : public Object{
    public:
        Wrap(std::string name);
        void isTaken() const;
        void openMe();
        void closeMe();
        bool wrapMeThat(Object *);
    protected:
        int _type;
};

#endif
