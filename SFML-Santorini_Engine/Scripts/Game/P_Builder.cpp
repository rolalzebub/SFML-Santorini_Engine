#include "P_Builder.h"
#include "Managers/RenderManager.h"
void P_Builder::Start()
{
    builderSprite = makeUPtr<Sprite>(this);
    builderSprite->LoadTexture(sprite_path);
    Renderer.AddSprite(builderSprite.get());
}

void P_Builder::move(unsigned short i, unsigned short j)
{
    setPosition(getPosition() + sf::Vector2f(i, j));
}
