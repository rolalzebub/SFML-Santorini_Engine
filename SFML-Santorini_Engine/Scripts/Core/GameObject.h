#pragma once
#include "Core/utility_headers.h"
#include "Core/Component.h"
#include "SFML/Graphics/Transformable.hpp"
class GameObject: public sf::Transformable
{
protected:

	GameObject* m_parent = nullptr;
	/*std::vector<Component*> m_components;*/
	std::vector<GameObject*> m_children;
	

public:
	GameObject();
	GameObject(GameObject* parent);
	~GameObject();

	virtual void Start() {};
	virtual void Update() {};
	virtual void FixedUpdate() {};
	virtual void Stop() {};

	virtual void OnCollisionEnter() {};
	virtual void OnCollisionStay() {};
	virtual void OnCollisionExit() {};
	
	inline void SetParent(GameObject* newParent) { m_parent = newParent; }
	inline GameObject* GetParent() { return m_parent; }

	inline void AddChild(GameObject* child) { m_children.push_back(child); }
	/*void AddComponent(Component* comp);*/


};

