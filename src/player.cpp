#include "include.h"
#include <iostream>
using namespace std;

Player::Player(const std::string& filepath) : playerObject(filepath) {
    // Additional initialization if needed
}

void Player::draw(sf::RenderWindow& window) {
    playerObject.draw(window);
}

void Player::setPosition(float x, float y) {
    playerObject.setPosition(x, y);
}

sf::Vector2f Player::getPosition() const {
    return playerObject.getPosition();
}

void Player::setScale(const sf::Vector2f& scale) {
    playerObject.setScale(scale);
}
