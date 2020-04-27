#pragma once
#include "Core/Component.h"
#include "Core/utility_headers.h"
#include <SFML/Graphics/Sprite.hpp>

class Transform;
class Sprite :
	public Component
{
private:

	uPtr<sf::Sprite> m_spriteTexture;
	int spriteIndex = -1;

	bool m_isDrawable = true;

public:
	Sprite(GameObject* parent);
	~Sprite() = default;

	void OnStart() override;
	void OnUpdate() override;
	void Stop();

	void LoadTexture(const std::string& path);
	void SetTexture(const sf::Texture& texture);

	bool isDrawable();
	void isDrawable(bool draw);

	sf::Sprite* GetSprite();
};

