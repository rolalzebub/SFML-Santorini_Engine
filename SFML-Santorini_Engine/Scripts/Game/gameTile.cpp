#include "gameTile.h"
#include "Managers/RenderManager.h"

gameTile::gameTile()
{
    

    baseColour = sf::Color(0x769D66ff);

    tileBase.setOutlineThickness(5);
    tileBase.setSize(sf::Vector2f(110, 110));
    tileBase.setFillColor(baseColour);
    tileBase.setOrigin(tileBase.getOrigin() - sf::Vector2f(2.5,2.5));

    tile_lv2.setOutlineThickness(10);
    tile_lv2.setFillColor(baseColour);
    tile_lv2.setOrigin(tile_lv2.getOrigin() - sf::Vector2f(5, 5));
    tile_lv2.setSize(sf::Vector2f(110, 110));

    tile_lv3.setOutlineThickness(20);
    tile_lv3.setFillColor(baseColour);
    tile_lv3.setOrigin(tile_lv2.getOrigin() - sf::Vector2f(10, 10));
    tile_lv3.setSize(sf::Vector2f(110, 110));
}

void gameTile::build()
{
    switch (level) {
    case 0:
        break;
    }
}

void gameTile::Start()
{
    

    tileBase.setPosition(getPosition());
    tile_lv2.setPosition(getPosition());
    tile_lv3.setPosition(getPosition());

     Renderer.AddDrawable(&tile_lv3);
    Renderer.AddDrawable(&tile_lv2);
    tileBaseID = Renderer.AddDrawable(&tileBase);

    
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
