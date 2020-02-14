#pragma once
#include "utility_headers.h"
#include "Transform.h"
class GameObject
{
protected:

	GameObject* m_parent = nullptr;
	std::vector<Component*> m_components;
	std::vector<GameObject*> m_children;
	
	Transform* m_transform;

public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Stop() = 0;

	virtual void OnCollisionEnter() = 0;
	virtual void OnCollisionStay() = 0;
	virtual void OnCollisionExit() = 0;
	
	inline void SetParent(GameObject* newParent) { m_parent = newParent; }
	inline GameObject* GetParent() { return m_parent; }

	inline void AddChild(GameObject* child) { m_children.push_back(child); }
	void AddComponent(Component* comp);

	Transform* GetTransform();

};

