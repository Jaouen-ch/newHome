#pragma once

#include "gameObject.h"
#include "sprite.h"

class rendererObject : public gameObject
{
private:
    sprite objectSprite;

public:
    rendererObject(sprite _objectSprite);
    virtual ~rendererObject() override = default;

    virtual void update(float deltaTime) override;
    virtual void draw(sf::RenderWindow& window) override;
};
