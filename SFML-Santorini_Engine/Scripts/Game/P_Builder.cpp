#include "P_Builder.h"
#include "Managers/RenderManager.h"
void P_Builder::Start()
{
    builderCircle.setRadius(10);
    builderCircle.setScale(1, 1);


    //builderSprite = makeUPtr<Sprite>(this);
    //builderSprite->LoadTexture(sprite_path);
    //Renderer.AddSprite(builderSprite.get());
    Renderer.AddDrawable(&builderCircle);
    builderCircle.setPosition(this->getPosition());
}

void P_Builder::Update()
{
    builderCircle.setPosition(this->getPosition());
}

void P_Builder::move(unsigned short i, unsigned short j)
{
    setPosition(getPosition() + sf::Vector2f(i, j));
}

void P_Builder::UnHighlight()
{
    if (builderCircle.getFillColor() != default_color) {
        builderCircle.setFillColor(default_color);
    }
}

void P_Builder::HighlightGreen()
{
    if (builderCircle.getFillColor() != sf::Color::Green) {
        builderCircle.setFillColor(sf::Color::Green);
    }
}

void P_Builder::HighlightRed()
{
    if (builderCircle.getFillColor() != sf::Color::Red) {
        builderCircle.setFillColor(sf::Color::Red);
    }
}

void P_Builder::SetStandingLevel(int level)
{
    standingLevel = level;
}

int P_Builder::GetStandingLevel()
{
    return standingLevel;
}
