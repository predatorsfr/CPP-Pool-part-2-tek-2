/*
** EPITECH PROJECT, 2019
** SfmlWindow.hpp
** File description:
** kevin
*/

#ifndef _SFMLWINDOW_HPP__
#define _SFMLWINDOW_HPP__

#include <SFML/Graphics.hpp>
#include "Modules.hpp"

class SfmlWindow {
    public:
        SfmlWindow();
        void printUser(sf::RenderWindow &window, sf::Font &font) ;
        void printHost(sf::RenderWindow &window, sf::Font &font) ;
        void printRelease(sf::RenderWindow &window, sf::Font &font) ;
        void printSys(sf::RenderWindow &window, sf::Font &font) ;
        void printTimeDaye(sf::RenderWindow &window, sf::Font &font) ;
    private:
        Modules modules;
};

#endif
