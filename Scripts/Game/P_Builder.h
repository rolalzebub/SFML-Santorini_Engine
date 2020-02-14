#pragma once
#include "GameObject.h"
class P_Builder :
	public GameObject
{
public:
	unsigned short player;
	//void draw(sf::RenderWindow& window);
	void move(unsigned short i, unsigned short j);
};

