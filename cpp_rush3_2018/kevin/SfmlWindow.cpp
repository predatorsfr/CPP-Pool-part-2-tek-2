/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** SfmlWindow.cpp
*/

#include "SfmlWindow.hpp"



void SfmlWindow::printUser(sf::RenderWindow &window, sf::Font &font)
{
    std::string usr1 = "username : ";
    usr1 += modules.getUserName();
    sf::Text usr(usr1,font, 11);
    usr.setPosition(5.f,10.f);
    window.draw(usr);
}

void SfmlWindow::printHost(sf::RenderWindow &window, sf::Font &font)
{
    std::string hst1 = "hostname : ";
    hst1 += modules.getHostName();
    sf::Text hst(hst1,font, 11);
    hst.setPosition(5.f,30.f);
    window.draw(hst);
}

void SfmlWindow::printRelease(sf::RenderWindow &window, sf::Font &font)
{
    std::string ker1 = "kernel v. : ";
    ker1 += modules.getKernelV();
//    std::cout << ker1 << '\n';
    sf::Text ker(ker1,font, 11);
    ker.setPosition(5.f,70.f);
    window.draw(ker);
}

void SfmlWindow::printSys(sf::RenderWindow &window, sf::Font &font)
{
    std::string sys1 = "system : ";
    sys1 += modules.getSysName();
    sf::Text sys(sys1,font, 11);
    sys.setPosition(5.f,50.f);
    window.draw(sys);
}

void SfmlWindow::printTimeDaye(sf::RenderWindow &window, sf::Font &font)
{
    std::string dt1 = "date/time : ";
    dt1 += modules.getTimeDate();
    sf::Text dt(dt1,font, 11);
    dt.setPosition(5.f,90.f);
    window.draw(dt);
}

SfmlWindow::SfmlWindow()
{
    int i = 120;
    sf::RenderWindow window(sf::VideoMode(200, i), "MyGKrellm");

    sf::RectangleShape rectangle(sf::Vector2f(20.f, 20.f));
    rectangle.setFillColor(sf::Color(100, 250, 50));
    rectangle.setPosition(180.f, 0.f);

    sf::RectangleShape rectangle2(sf::Vector2f(20.f, 20.f));
    rectangle2.setFillColor(sf::Color(100, 250, 50));
    rectangle2.setPosition(0.f, 0.f);

    sf::RectangleShape rectangle3(sf::Vector2f(200.f, 100.f));
    rectangle3.setFillColor(sf::Color(sf::Color::Black));
    rectangle3.setPosition(0.f, 10.f);

    sf::RectangleShape rectangle6(sf::Vector2f(200.f, 100.f));
    rectangle6.setFillColor(sf::Color(sf::Color::Black));
    rectangle6.setPosition(0.f, 120.f);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        exit(84);
    }

    sf::Text add("add modules",font, 11);
    sf::Text sup("sup modules",font, 11);

    sup.setPosition(60.f, -2.f);
    add.setPosition(60.f, -2.f);

    window.setFramerateLimit(60);
    printf("1\n");
    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();

            if (event.type == sf::Event::MouseButtonPressed && localPosition.x <= 20 && localPosition.y <= 10 && window.getSize().y == 110) {
                if (event.mouseButton.button == sf::Mouse::Left)
                window.setSize(sf::Vector2u(200, i -= 100));
            }

            if (event.type == sf::Event::MouseButtonPressed && localPosition.x >= 180 && localPosition.y <= 10) {
                if (event.mouseButton.button == sf::Mouse::Left)
                window.setSize(sf::Vector2u(200, i += 110));
            }
            if (event.type == sf::Event::MouseButtonPressed && localPosition.x <= 20 && localPosition.y <= 10 && window.getSize().y >= 110) {
                if (event.mouseButton.button == sf::Mouse::Left)
                window.setSize(sf::Vector2u(200, i -= 110));
            }

            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

//        std::string dt1 = "date/time : ";
//        dt1 += Modules.getTimeDate();
//        sf::Text dt(dt1,font, 11);
//        dt.setPosition(5.f,90.f);

        window.clear(sf::Color(128,128,128));

        window.draw(rectangle);
        window.draw(rectangle2);

        window.draw(rectangle3);
        window.draw(rectangle6);


        if (localPosition.x >= 180 && localPosition.x <= 200 && localPosition.y >= 0 &&localPosition.y <= 10)
        window.draw(add);
        if (localPosition.x >= 0 && localPosition.x <= 20 && localPosition.y >= 0 &&localPosition.y <= 20)
        window.draw(sup);

        this->printUser(window, font);
        this->printHost(window, font);
        this->printRelease(window, font);
        this->printSys(window, font);
        this->printTimeDaye(window, font);

        window.display();
    }
}
