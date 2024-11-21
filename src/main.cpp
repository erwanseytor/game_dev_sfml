/*
** EPITECH PROJECT, 2024
** TEK2
** File description:
** main
*/

#include <iostream>
#include <cmath>
#include "include.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
    auto player_obj = OBJ_FACTORY::create_obj("assets/PlayerSheet.png", "player");
    player_obj->viewdetails();
    player_obj->set_sprite();
    player_obj->set_rect(0,0,RECTSIZE_X,RECTSIZE_Y);
    player_obj->set_position(100, 100);
    player_obj->set_scale(3.5,3.5);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player_movement_handling(player_obj);
        window.clear(sf::Color::Blue);
        player_obj->draw_sprite(window);
        window.display();
    }
    return 0;
}
