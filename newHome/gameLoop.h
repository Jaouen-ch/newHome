#pragma once

#include "entity.h"
#include "utils.h"

class gameLoop
{
private:
    sf::Clock clock;
    sf::Time now = clock.getElapsedTime();
    sf::Time lastTime;
    float deltaTime = 0.0f;

    std::vector<gameObject*> objects = {};

public:
    gameLoop() = default;
    ~gameLoop() = default;

    void eventsHandler(sf::RenderWindow& window, const std::optional<sf::Event>& event);
    void update();
    void draw(sf::RenderWindow& window);
};