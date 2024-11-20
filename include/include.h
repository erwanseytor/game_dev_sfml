/*
** EPITECH PROJECT, 2024
** TEK2
** File description:
** include
*/

#ifndef INCLUDED_INCLUDE_H
    #define INCLUDED_INCLUDE_H
    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Window.hpp>

class Object {
public:
    Object(const std::string& filepath);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    void setScale(const sf::Vector2f& scale);
    sf::Vector2f getPosition() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

class Player {
public:
    Player(const std::string& filepath);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    void setScale(const sf::Vector2f& scale);
    sf::Vector2f getPosition() const;

private:
    Object playerObject;
};

#endif
