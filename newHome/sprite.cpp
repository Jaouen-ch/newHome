#include "sprite.h"

sprite::sprite(sf::Vector2f _position, sf::Vector2f _size, assetsHandler::texturesIndices index)
    : position(_position)
    , size(_size)
    , texture(assetsHandler::getAssets()->getTexture(index))
    , sfmlSprite(sf::Sprite(texture))
{
    sfmlSprite.setPosition(position);
    sfmlSprite.setScale({size.x / texture.getSize().x, size.y / texture.getSize().y});
}

void sprite::draw(sf::RenderWindow& window)
{
    window.draw(sfmlSprite);
}
