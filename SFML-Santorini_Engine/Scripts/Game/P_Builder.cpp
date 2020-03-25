#include "P_Builder.h"
#include "Managers/RenderManager.h"
void P_Builder::Start()
{
    builderCircle.setRadius(1);
    builderCircle.setScale(10, 10);


    builderSprite = makeUPtr<Sprite>(this);
    builderSprite->LoadTexture(sprite_path);
    Renderer.AddSprite(builderSprite.get());
    Renderer.AddDrawable(&builderCircle);
}

void P_Builder::move(unsigned short i, unsigned short j)
{
    setPosition(getPosition() + sf::Vector2f(i, j));
}

void P_Builder::PlaceSelf(sf::Vector2f position)
{
}
