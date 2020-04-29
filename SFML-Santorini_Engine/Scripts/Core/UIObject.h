#pragma once
#include "Core/GameObject.h"
#include "SFML/Graphics.hpp"
class UIObject: public GameObject
{
protected:

	std::vector<sf::Drawable*> m_drawables;
	sf::Vector2f m_size;

	void AddDrawable(sf::Drawable* obj) { m_drawables.push_back(obj); }

	bool m_isDrawable = true;
	bool canReceiveText = false;
	sf::Event* textReceivedEvent;

	void SetTextReceivable(bool rec) { canReceiveText = rec; }

public:
	virtual void Start() override {};
	virtual void OnClick() {};
	virtual void Update() override {};
	virtual void Stop() override {};
	virtual void ReceiveText(sf::Event& e) {};

	bool CanReceiveText() { return canReceiveText; }

	sf::Vector2f GetSize() { return m_size; }
	void SetSize(sf::Vector2f size) { m_size = size; }

	bool isDrawable() { return m_isDrawable; }
	void isDrawable(bool draw) { m_isDrawable = draw; }

	std::vector<sf::Drawable*> GetDrawables() { return m_drawables; }
};

