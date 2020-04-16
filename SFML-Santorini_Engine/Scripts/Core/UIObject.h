#pragma once
#include "Core/GameObject.h"
#include "SFML/Graphics.hpp"
class UIObject: public GameObject
{
protected:

	std::vector<sf::Drawable*> m_drawables;
	sf::Vector2f m_size;

	void AddDrawable(sf::Drawable* obj) { m_drawables.push_back(obj); }

public:
	virtual void Start() override {};
	virtual void OnClick() {};
	virtual void Update() override {};
	virtual void Stop() override {};

	sf::Vector2f GetSize() { return m_size; }
	void SetSize(sf::Vector2f size) { m_size = size; }

	std::vector<sf::Drawable*> GetDrawables() { return m_drawables; }
};

