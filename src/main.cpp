/*
** EPITECH PROJECT, 2024
** TEK2
** File description:
** main
*/

#include <iostream>
#include <cmath>
#include "include.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
    Player player("assets/player.png");
    player.setPosition(100, 100);
    player.setScale(sf::Vector2f(0.5f,0.5f));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Blue);
        player.draw(window);
        window.display();
    }
    return 0;
}
