#pragma once
#include <SFML/System.hpp>
class GameObject;
class Manager;
class Component
{
protected:
	GameObject* m_parent;
public:
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void Stop() = 0;

	void SetParent(GameObject* newParent) {
		m_parent = newParent;
	}
	GameObject* GetParent() { return m_parent; }

	Component(GameObject* parent) { m_parent = parent; }
	~Component() = default;
};

