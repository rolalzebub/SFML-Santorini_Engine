#pragma once
#include "Core/GameObject.h"
class UIObject: public GameObject
{
	sf::Vector2f m_size;


public:
	virtual void Start() override {};
	virtual void OnClick() {};
	virtual void Update() override {};
	virtual void Stop() override {};

	sf::Vector2f GetSize() { return m_size; }
	void SetSize(sf::Vector2f size) { m_size = size; }
};

