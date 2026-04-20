#include "rendererObject.h"

rendererObject::rendererObject(sprite _objectSprite)
    : objectSprite(_objectSprite)
{
}

void rendererObject::update(float deltaTime)
{
}

void rendererObject::draw(sf::RenderWindow& window)
{
    objectSprite.draw(window);
}