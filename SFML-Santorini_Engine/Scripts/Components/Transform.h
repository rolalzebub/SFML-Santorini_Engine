#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include "Component.h"

class Transform :
	public Component
{
	uPtr<sf::Transformable> transform;

public:
	void OnStart() override {};
	void OnUpdate() override {};
	void Stop() override {};

	sf::Vector2f getPosition() { return transform->getPosition(); }
	void setPosition(sf::Vector2f new_pos) { transform->setPosition(new_pos); }

	float getRotation() { return transform->getRotation(); }
	void setRotation(float angle) { return transform->setRotation(angle); }

	sf::Vector2f getScale() { return transform->getScale(); }
	void setScale(sf::Vector2f new_scale) { transform->setScale(new_scale); }

	Transform(GameObject* parent) : Component(parent) { transform = makeUPtr<sf::Transformable>(); }
	~Transform() = default;
};

