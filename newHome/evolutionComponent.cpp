#include "evolutionComponent.h"

#include "counterComponent.h"
#include "rendererComponent.h"
#include "textComponent.h"

evolutionComponent::evolutionComponent(gameObject* _owner, gameObject* _resource)
    : component(_owner)
    , resource(_resource)
{
}

void evolutionComponent::evolution()
{
    auto counterComp = resource->getComponent<counterComponent>();
    auto rendererComp = owner->getComponent<rendererComponent>();
    auto textComp = owner->getComponent<textComponent>();
    if (counterComp != nullptr)
    {
        if (counterComp->getCount() >= stoneNeeded[index])
        {
            counterComp->setCount(counterComp->getCount() - stoneNeeded[index]);
            if (rendererComp != nullptr)
            {
                rendererComp->setTexture(textures[index]);
            }
            if (textComp != nullptr)
            {
                if (index < 3)
                {
                    textComp->setText(std::to_string(stoneNeeded[index + 1]));
                }
                else
                {
                    textComp->setPosition({400.0f, 300.0f});
                    textComp->setText("Our new home !");
                }
            }
            if (index < 3)
            {
                index++;
            }
        }
    }
}