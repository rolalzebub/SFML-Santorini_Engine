#pragma once
#include "GameObject.h"
#include "Sprite.h"
class P_Builder :
	public GameObject
{
private:
	uPtr<Sprite> builderSprite;
	const std::string sprite_path = "Data/builder_M.png";
	unsigned short player = 0;

public:
	P_Builder() :GameObject() {};

	void Start() override;
	//void draw(sf::RenderWindow& window);
	void move(unsigned short i, unsigned short j);
};

