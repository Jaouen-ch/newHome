#pragma once

#include "utils.h"
#include "assetsHandler.h"

class sprite
{
public:
    sf::Vector2f position;
    sf::Vector2f size;

    sf::Texture texture;
    sf::Sprite sfmlSprite;

    sprite(sf::Vector2f _position, sf::Vector2f _size, assetsHandler::texturesIndices index);
    ~sprite() = default;

    void draw(sf::RenderWindow& window);
};