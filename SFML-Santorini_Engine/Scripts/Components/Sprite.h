#pragma once
#include "Core/Component.h"
#include "Core/utility_headers.h"
#include <SFML/Graphics/Sprite.hpp>

class Transform;
class Sprite :
	public Component
{
private:
	//Sprite class is useless if one is not using at least either a texture or a collection of drawables

	//Texture, optional
	uPtr<sf::Sprite> m_spriteTexture;
	int spriteIndex = -1;


	//Drawables, also optional
	std::vector<uPtr<sf::Drawable*>> drawables;

	bool hasDrawables = false;
	bool hasTexture = false;

	//Whether or not the renderer should consider the sprite active/enabled
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

	//Whether or not there is a collection of drawables to be rendered
	bool HasPrimitiveDrawables();
	//Add a drawable to the sprite drawables collection
	void AddSFDrawableToSprite(sf::Drawable* dr);
	std::vector<sf::Drawable*> GetPrimitiveDrawables();

	void ClearDrawables();
	bool HasTexture();
	
	sf::Sprite* GetSprite();
};

