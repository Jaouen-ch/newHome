#pragma once

#include "utils.h"
#include "sprite.h"
#include "hitbox.h"

class camera
{
private:
    sf::View view;

public:
    camera();
    ~camera() = default;

    void centerViewOnSprite(sprite selectedSprite);
    void centerViewOnHitbox(hitbox selectedHitbox);
    void centerViewOnPosition(sf::Vector2f position);
    void setCamera(sf::RenderWindow* window);
};

