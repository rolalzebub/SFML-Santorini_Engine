#include "GameManager.h"
GameManager* GameManager::instance{ nullptr };
GameManager& GameManager::Instance()
{
	if (instance == nullptr)
		instance = new GameManager;

	return *instance;
}

void GameManager::Start()
{
	level.setup();
}

void GameManager::Update()
{
	for (auto ob : activeObjects) {
		ob->Update();
	}
}

void GameManager::FixedUpdate()
{
	activeObjects = level.GetActiveGameObjects();
}

void GameManager::Stop()
{
}
