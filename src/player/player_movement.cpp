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

void player_movement_handling(shared_ptr<OBJ> player_obj)
{
    sf::Vector2f pos = player_obj->get_position();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player_obj->set_position(pos.x + 0.1, pos.y);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        player_obj->set_position(pos.x - 0.1, pos.y);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player_obj->set_position(pos.x, pos.y + 0.1);
}
