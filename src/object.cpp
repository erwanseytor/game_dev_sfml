#include "include.h"
#include <iostream>
using namespace std;

Object::Object(const std::string& filepath) {
    if (!texture.loadFromFile(filepath)) {
        // Handle error
    }
    sprite.setTexture(texture);
}

void Object::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Object::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Vector2f Object::getPosition() const {
    return sprite.getPosition();
}

void Object::setScale(const sf::Vector2f& scale) {
    sprite.setScale(scale);
}
