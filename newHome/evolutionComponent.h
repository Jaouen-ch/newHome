#pragma once

#include "gameObject.h"
#include "assetsHandler.h"

class evolutionComponent : public component
{
private:
    gameObject* resource;
    std::vector<int> stoneNeeded = {10, 30, 80, 150};
    std::vector<assetsHandler::texturesIndices> textures = {assetsHandler::texturesIndices::planet6,
        assetsHandler::texturesIndices::planet4, assetsHandler::texturesIndices::planet1,
        assetsHandler::texturesIndices::planet2
    };
    int index = 0;

public:
    evolutionComponent(gameObject* _owner, gameObject* _resource);
    ~evolutionComponent() override = default;

    void evolution();
};