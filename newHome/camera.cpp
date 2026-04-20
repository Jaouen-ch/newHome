#include "camera.h"

camera::camera()
{
    view = sf::View(sf::FloatRect({ 0, 0 }, { WINDOW_WIDTH, WINDOW_HEIGHT }));
}

void camera::centerViewOnSprite(sprite selectedSprite)
{
    view.setCenter({selectedSprite.position.x + selectedSprite.size.x / 2, selectedSprite.position.y + selectedSprite.size.y / 2 });
}

void camera::centerViewOnHitbox(hitbox selectedHitbox)
{
    view.setCenter({selectedHitbox.position.x + selectedHitbox.size.x / 2, selectedHitbox.position.y + selectedHitbox.size.y / 2 });
}

void camera::centerViewOnPosition(sf::Vector2f position)
{
    view.setCenter(position);
}

void camera::setCamera(sf::RenderWindow* window)
{
    window->setView(view);
}