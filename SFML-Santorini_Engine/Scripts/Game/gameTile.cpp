#include "gameTile.h"
#include "Managers/RenderManager.h"

gameTile::gameTile()
{
    tileSprite = new Sprite(this);

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

    tile_dome.setFillColor(sf::Color::Blue);
    tile_dome.setRadius(10);
    tile_dome.setOrigin(tile_dome.getOrigin() + sf::Vector2f(tile_dome.getRadius(), tile_dome.getRadius()));

    tileSprite->AddSFDrawableToSprite(&tileBase);
}

void gameTile::build()
{
    switch (level) {
    case 0:
        level++;
        tileBase.setFillColor(sf::Color::Yellow);
       // tileSprite->ClearDrawables();
        //tileSprite->AddSFDrawableToSprite(&tile_lv2);
        break;

    case 1:
        level++;
        //tileSprite->ClearDrawables();
        //tileSprite->AddSFDrawableToSprite(&tile_lv3);
        tileBase.setFillColor(sf::Color::Red);
        break;

    case 2:
        level++;
        //tileSprite->AddSFDrawableToSprite(&tile_dome);
        tileBase.setFillColor(sf::Color::Black);
        break;
    }
}

void gameTile::Start()
{
    

    tileBase.setPosition(getPosition());
    tile_lv2.setPosition(getPosition());
    tile_lv3.setPosition(getPosition());
    tile_dome.setPosition(getPosition() + (tileBase.getSize() / 2.f));
    Renderer.AddSprite(tileSprite);

    
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
    tileBase.setFillColor(sf::Color::Green);
    tile_lv2.setFillColor(sf::Color::Green);
    tile_lv3.setFillColor(sf::Color::Green);
}

void gameTile::HighlightRed()
{
    tileBase.setFillColor(sf::Color::Red);
    tile_lv2.setFillColor(sf::Color::Red);
    tile_lv3.setFillColor(sf::Color::Red);
}

void gameTile::UnHighlight()
{
  
    tileBase.setFillColor(baseColour);
    tile_lv2.setFillColor(baseColour);
    tile_lv3.setFillColor(baseColour);
     
}

void gameTile::SetTileID(sf::Vector2i ID)
{
    tileID = ID;
}

sf::Vector2i gameTile::GetTileID()
{
    return tileID;
}

int gameTile::GetTileHeight()
{
    return level;
}
