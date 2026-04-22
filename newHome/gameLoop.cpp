#include "gameLoop.h"

#include "counterComponent.h"
#include "counterModifierComponent.h"
#include "evolutionComponent.h"
#include "textComponent.h"

gameLoop::gameLoop(sf::RenderWindow& window)
{
    objects.reserve(10);

    objects.push_back(gameObject({0.0f, 0.0f}, {WINDOW_WIDTH, WINDOW_HEIGHT}));
    objects[0].addComponent(new rendererComponent(&objects[0], assetsHandler::texturesIndices::space));

    objects.push_back(gameObject({10.0f, 10.0f}, {50.0f, 50.0f}));
    objects[1].addComponent(new rendererComponent(&objects[1], assetsHandler::texturesIndices::stone));
    objects[1].addComponent(new textComponent(&objects[1], assetsHandler::fontsIndices::space, "0", {70.0f, 10.0f}, 30));
    objects[1].addComponent(new counterComponent(&objects[1]));

    objects.push_back(gameObject({80.0f, 450.0f}, {130.0f, 130.0f}));
    objects[2].addComponent(new rendererComponent(&objects[2], assetsHandler::texturesIndices::baren));
    objects[2].addComponent(new clickableComponent(&objects[2], &window));
    objects[2].addComponent(new counterModifierComponent(&objects[2], &objects[1]));

    objects.push_back(gameObject({750.0f, 100.0f}, {130.0f, 130.0f}));
    objects[3].addComponent(new rendererComponent(&objects[3], assetsHandler::texturesIndices::ice));
    objects[3].addComponent(new clickableComponent(&objects[3], &window));
    objects[3].addComponent(new counterModifierComponent(&objects[3], &objects[1]));

    objects.push_back(gameObject({1050.0f, 550.0f}, {130.0f, 130.0f}));
    objects[4].addComponent(new rendererComponent(&objects[4], assetsHandler::texturesIndices::lava));
    objects[4].addComponent(new clickableComponent(&objects[4], &window));
    objects[4].addComponent(new counterModifierComponent(&objects[4], &objects[1]));

    objects.push_back(gameObject({450.0f, 350.0f}, {250.0f, 250.0f}));
    objects[5].addComponent(new rendererComponent(&objects[5], assetsHandler::texturesIndices::planet3));
    objects[5].addComponent(new clickableComponent(&objects[5], &window));
    objects[5].addComponent(new evolutionComponent(&objects[5], &objects[1]));
    objects[5].addComponent(new textComponent(&objects[5], assetsHandler::fontsIndices::space, "10", {550.0f, 300.0f}, 30));

    objects.push_back(gameObject({750.0f, 650.0f}, {100.0f, 100.0f}));
    objects[6].addComponent(new rendererComponent(&objects[6], assetsHandler::texturesIndices::planet5));
    objects[6].addComponent(new clickableComponent(&objects[6], &window));
    objects[6].addComponent(new counterModifierComponent(&objects[6], &objects[1]));

    objects.push_back(gameObject({300.0f, 70.0f}, {100.0f, 100.0f}));
    objects[7].addComponent(new rendererComponent(&objects[7], assetsHandler::texturesIndices::blackHole));
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