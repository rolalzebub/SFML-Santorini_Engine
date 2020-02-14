#pragma once
#include "utility_headers.h"
#include <SFML/Graphics/Transformable.hpp>
#include "Component.h"


class Transform :
	public Component
{
	uPtr<sf::Transformable> transform;

public:
	void OnStart() override;
	void OnUpdate() override;
	void Stop() override;

	sf::Transformable& GetTransformable();

	Transform(GameObject* parent): Component(parent) { }
	~Transform() = default;
};

