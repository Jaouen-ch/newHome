#include "gameLoop.h"

#include "counterComponent.h"
#include "counterModifierComponent.h"
#include "textComponent.h"

gameLoop::gameLoop(sf::RenderWindow& window)
{
    objects.reserve(10);

    objects.push_back(gameObject({10.0f, 10.0f}, {30.0f, 30.0f}));
    objects[0].addComponent(new rendererComponent(&objects[0], assetsHandler::texturesIndices::defaultTexture));
    objects[0].addComponent(new textComponent(&objects[0], assetsHandler::fontsIndices::fingerPaint, "0", {50.0f, 10.0f}, 20));
    objects[0].addComponent(new counterComponent(&objects[0]));

    objects.push_back(gameObject({0.0f, 400.0f}, {100.0f, 100.0f}));
    objects[1].addComponent(new rendererComponent(&objects[1], assetsHandler::texturesIndices::defaultTexture));
    objects[1].addComponent(new clickableComponent(&objects[1], &window));
    objects[1].addComponent(new counterModifierComponent(&objects[1], &objects[0]));
}

void gameLoop::eventsHandler(sf::RenderWindow& window, const std::optional<sf::Event>& event)
{
    if (event->is<sf::Event::Closed>())
    {
        window.close();
    }
}

void gameLoop::update()
{
    lastTime = now;
    now = clock.getElapsedTime();
    deltaTime = now.asSeconds() - lastTime.asSeconds();

    for (auto& object : objects)
    {
        object.update(deltaTime);
    }
}

void gameLoop::draw(sf::RenderWindow& window)
{
    for (auto& object : objects)
    {
        object.draw(window);
    }
}