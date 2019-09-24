/*
** EPITECH PROJECT, 2019
** Wrap.hpp
** File description:
** kevin
*/

#ifndef _WRAP_HPP__
#define _WRAP_HPP__

#include "Object.hpp"

class Wrap : public Object{
    public:
        Wrap(std::string name);
        void isTaken() const;
        void openMe();
        void closeMe();
        bool wrapMeThat(Object *);
//        void printname();
/*        Object *getObject() const{
            return _gift
        };
        */
    protected:
//        Object *_gift;
        int _type;
//        std::string _name;
};

#endif
