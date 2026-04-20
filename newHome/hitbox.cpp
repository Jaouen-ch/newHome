#include "hitbox.h"

hitbox::hitbox(sf::Vector2f _position, sf::Vector2f _size)
    : position(_position), size(_size)
{
}

bool hitbox::collision(hitbox oppositeHitbox)
{
    return false;
}

bool hitbox::click(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (sf::Mouse::getPosition(window).x > position.x && sf::Mouse::getPosition(window).x < position.x + size.x && sf::Mouse::getPosition(window).y > position.y && sf::Mouse::getPosition(window).y < position.y + size.y)
        {
            return true;
        }
    }
    return false;
}