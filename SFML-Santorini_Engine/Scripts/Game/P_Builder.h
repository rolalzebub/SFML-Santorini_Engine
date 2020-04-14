#pragma once
#include "Core/GameObject.h"
#include "Components/Sprite.h"

#include <SFML/Graphics/CircleShape.hpp>

class P_Builder :
	public GameObject
{
private:
	uPtr<Sprite> builderSprite;
	sf::CircleShape builderCircle;
	const std::string sprite_path = "Data/builder_M.png";
	short owner_player_levelID = -1;

public:
	P_Builder() :GameObject() {};

	void Start() override;
	void Update() override;
	void move(unsigned short i, unsigned short j);

	void PlaceSelf(sf::Vector2f position);

	int GetOwnerID() { return (int) owner_player_levelID; }
	void SetOwnerID(int index) { owner_player_levelID = (short) index; }
	void HighlightGreen();
	void HighlightRed();
};

