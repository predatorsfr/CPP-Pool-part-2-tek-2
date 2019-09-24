/*
** EPITECH PROJECT, 2019
** Teddy.hpp
** File description:
** kevin
*/

#include "Teddy.hpp"
#include "Toy.hpp"
#include "Box.hpp"
#include "Wrap.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"

Object **MyUnitTests()
{
    Object **array = new Object*[3];
    LittlePony *lp = new LittlePony("happy pony");
    Teddy *ours = new Teddy("cuddles");
    array[0] = lp;
    array[1] = ours;
    array[2] = NULL;
    return array;
}

Object *MyUnitTests(Object **array)
{
    array[1]->openMe();
    array[1]->wrapMeThat(array[0]);
    array[1]->closeMe();
    array[2]->wrapMeThat(array[1]);
    array[2]->closeMe();
    return array[2];
}

int main()
{
/*
//    Test1;
    Object **array;
    array = MyUnitTests();
    array[0]->isTaken();
    array[1]->isTaken();
    return (0);
*/
    Object **array = new Object*[4];
//    GiftPaper *gift = new Object();
    Teddy *ours = new Teddy("cuddles");
    Box *box = new Box("boite");
    GiftPaper *paper = new GiftPaper("papier");
    array[0] = ours;
    array[1] = box;
    array[2] = paper;
    array[3] = NULL;
    array[3] = MyUnitTests(array);
    array[3]->printname();
    array[3]->getObject()->printname();
    array[3]->getObject()->getObject()->printname();
}
