/*
** EPITECH PROJECT, 2019
** Object.hpp
** File description:
** kevin
*/

#ifndef _OBJECT_HPP__
#define _OBJECT_HPP__

#include <string>
#include <iostream>

class Object {
    public:
        Object(std::string name);
        virtual void isTaken() const;
        virtual void openMe();
        virtual void closeMe();
        void printname() const;
        Object *getObject();
        virtual bool wrapMeThat(Object *);
    protected:
        std::string _name;
        Object *_gift;

};

#endif
