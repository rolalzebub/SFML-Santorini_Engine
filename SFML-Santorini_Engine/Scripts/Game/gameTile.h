#pragma once
#include "Core/GameObject.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
class gameTile :
	public GameObject
{
private:
    sf::RectangleShape tileBase;

public:
    bool build();
    unsigned short level = 0;

    void Start() override;
    void Update() override;
    void Stop() override;
    void OnCollisionEnter() override {};
    void OnCollisionStay() override {};
    void OnCollisionExit() override {};
};

