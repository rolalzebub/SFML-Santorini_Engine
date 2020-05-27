#pragma once
#include "Core/GameObject.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include "Components/NetworkSyncedObject.h"
class gameTile :
	public GameObject
{
private:
    int tileBaseID = -1;
    int tile_lv2_ID = -1;
    int tile_lv3_ID = -1;

    sf::RectangleShape tileBase;
    sf::RectangleShape tile_lv2;
    sf::RectangleShape tile_lv3;
    sf::CircleShape tile_dome;
    sf::Color baseColour;

    sf::Vector2i tileID = sf::Vector2i(-1, -1);

public:

    gameTile();

    void build();
    unsigned short level = 0;

    void Start() override;
    void Update() override;
    void Stop() override;
    void OnCollisionEnter() override {};
    void OnCollisionStay() override {};
    void OnCollisionExit() override {};

    sf::Vector2f GetSize();

    void HighlightGreen();
    void HighlightRed();
    void UnHighlight();

    void SetTileID(sf::Vector2i ID);
    sf::Vector2i GetTileID();
};

