#include "gameTile.h"
#include "Managers/RenderManager.h"

gameTile::gameTile()
{
    
    tileBase.setOutlineThickness(5);
    sf::Color cOutline;
    cOutline = sf::Color(0xf2f0e6ff);

    baseColour = sf::Color(0x769D66ff);
    tileBase.setSize(sf::Vector2f(110, 110));

    tileBase.setFillColor(baseColour);

}

bool gameTile::build()
{

    return false;
}

void gameTile::Start()
{
    

    tileBase.setPosition(getPosition());

    Renderer.AddDrawable(&tileBase);
}

void gameTile::Update()
{
}

void gameTile::Stop()
{
}

sf::Vector2f gameTile::GetSize()
{
    return tileBase.getSize();
}

void gameTile::HighlightGreen()
{
    if (tileBase.getFillColor() != sf::Color::Green) {
        tileBase.setFillColor(sf::Color::Green);
    }
}

void gameTile::HighlightRed()
{
    if (tileBase.getFillColor() != sf::Color::Red) {
        tileBase.setFillColor(sf::Color::Red);
    }
}

void gameTile::UnHighlight()
{
    tileBase.setFillColor(baseColour);
}

void gameTile::SetTileID(sf::Vector2i ID)
{
    tileID = ID;
}

sf::Vector2i gameTile::GetTileID()
{
    return tileID;
}
