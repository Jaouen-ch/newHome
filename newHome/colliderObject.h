#pragma once

#include "gameObject.h"
#include "hitbox.h"

class colliderObject : public gameObject
{
private:
    hitbox objectHitbox;

public:
    colliderObject(hitbox _objectHitbox);
    virtual ~colliderObject() override = default;

    virtual void update(float deltaTime) override;
    virtual void draw(sf::RenderWindow& window) override;
};