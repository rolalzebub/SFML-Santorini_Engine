#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(GameObject* parent)
{
	m_parent = parent;
}

GameObject::~GameObject()
{
}
//
//void GameObject::AddComponent(Component* comp) {
//	comp->SetParent(this);
//	m_components.push_back(comp);
//}



