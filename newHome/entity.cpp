#include "entity.h"

entity::entity(sprite _objectSprite, hitbox _objectHitbox)
    : rendererObject(_objectSprite)
    , colliderObject(_objectHitbox)
{
}
