#include "P_Builder.h"

void P_Builder::Start()
{
    builderSprite = makeUPtr<Sprite>(this);
    builderSprite->LoadTexture(sprite_path);
    AddComponent(builderSprite.get());

}

void P_Builder::move(unsigned short i, unsigned short j)
{
    m_transform->setPosition(m_transform->getPosition() + sf::Vector2f(i, j));
}
