#pragma once

#include "rendererObject.h"
#include "colliderObject.h"

class entity : public rendererObject, public colliderObject
{
public:
    entity(sprite _objectSprite, hitbox _objectHitbox);
    virtual ~entity() override = default;
};