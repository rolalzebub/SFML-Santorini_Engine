#include "GameObject.h"

GameObject::GameObject()
{
	m_transform = makeUPtr<sf::Transformable>();
}

GameObject::GameObject(GameObject* parent)
{
	m_parent = parent;
	m_transform = makeUPtr<sf::Transformable>();
}

GameObject::~GameObject()
{
}

void GameObject::AddComponent(Component* comp) {
	comp->SetParent(this);
	m_components.push_back(comp);
}

sf::Transformable* GameObject::GetTransform()
{
	return m_transform.get();
}


