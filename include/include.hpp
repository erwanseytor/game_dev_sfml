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
    #define RECTSIZE_Y 95
    #define RECTSIZE_X RECTSIZE_Y

class OBJ {
    private:
        std::string filepath;
        std::string type;
        sf::Sprite sprite;
        sf::Texture texture;

    public:
        //constructeur//
        OBJ(const std::string& path, const std::string& type) : filepath(path), type(type) {}
        void viewdetails() const {
            std::cout << type << std::endl;
            std::cout << filepath <<std::endl;
        }
        void set_sprite(){
            if (!texture.loadFromFile(filepath))
                std::cout << "Texture cannot be loaded\n";
            sprite.setTexture(texture);
        }
        void draw_sprite(sf::RenderWindow& window) {
            window.draw(sprite);
        }
        void set_position(float x, float y) {
            sprite.setPosition(sf::Vector2f(x,y));
        }
        void set_rect(int a, int b, int x, int y) {
            sprite.setTextureRect(sf::IntRect(a,b,x,y));
        }
        void set_scale(float x, float y) {
            sprite.setScale(sf::Vector2f(x,y));
        }
        sf::Vector2f get_position() {
            return sprite.getPosition();
        }
};

class OBJ_FACTORY {
    public:
        static std::shared_ptr<OBJ> create_obj(const std::string& path, const std::string & type) {
            return std::make_shared<OBJ>(path, type);
        }
};

void player_movement_handling(std::shared_ptr<OBJ> player_obj);

#endif
