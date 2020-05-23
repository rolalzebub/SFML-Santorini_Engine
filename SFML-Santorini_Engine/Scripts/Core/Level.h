#pragma once
#include "GameObject.h"
#include "Core/GameClient.h"
class Level
{
protected:
	std::vector<GameObject*> m_gameObjects;

	GameClient* localClient;

public:
	virtual void Start() {
		for (auto& go : m_gameObjects) {
			go->Start();
		}
	}
	virtual void Update() {
		for (auto& go : m_gameObjects) {
			go->Update();
		}
	}
	virtual void FixedUpdate() {
		for (auto& go : m_gameObjects) {
			go->FixedUpdate();
		}
	}
	virtual void Stop() {
		for (auto& go : m_gameObjects) {
			go->Stop();
		}
	}

	void AddGameObject(GameObject* go) {
		m_gameObjects.push_back(go);
	}
};

