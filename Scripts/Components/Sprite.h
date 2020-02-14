#pragma once
#include "Component.h"
#include "utility_headers.h"
#include <SFML/Graphics.hpp>
class Sprite :
	public Component
{
private:

	uPtr<sf::Sprite> m_spriteTexture;
	int spriteIndex = -1;
	const sf::Transformable* m_parentTransform;

public:
	Sprite(GameObject* parent);
	~Sprite() = default;

	void OnStart() override;
	void OnUpdate() override;
	void Stop();

	void LoadTexture(const std::string& path);
	void SetTexture(const sf::Texture& texture);

	sf::Sprite* GetSprite();
};

