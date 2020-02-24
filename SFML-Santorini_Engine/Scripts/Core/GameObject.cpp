#include "GameObject.h"

GameObject::GameObject()
{
	m_transform = makeUPtr<Transform>(this);
	AddComponent(m_transform.get());
}

GameObject::GameObject(GameObject* parent)
{
	m_parent = parent;
	m_transform = makeUPtr<Transform>(this);
	AddComponent(m_transform.get());
}

GameObject::~GameObject()
{
}

void GameObject::AddComponent(Component* comp) {
	comp->SetParent(this);
	m_components.push_back(comp);
}

Transform* GameObject::GetTransform()
{
	return m_transform.get();
}


