#pragma once

#include "utils.h"

class gameObject
{
public:
    gameObject() = default;
    virtual ~gameObject() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};
