#pragma once
#include "GameObject.h"

void GameObject::AddComponent(Component* comp) {
	comp->SetParent(this);
	m_components.push_back(comp);
}


