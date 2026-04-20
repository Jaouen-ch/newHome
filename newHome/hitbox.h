#pragma once

#include "utils.h"

class hitbox
{
public:
    sf::Vector2f position;
    sf::Vector2f size;

    hitbox(sf::Vector2f _position, sf::Vector2f _size);
    ~hitbox() = default;

    bool collision(hitbox oppositeHitbox);
};