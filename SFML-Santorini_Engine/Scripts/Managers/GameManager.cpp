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
	level.Start();
}

void GameManager::Update()
{
	level.Update();
}

void GameManager::FixedUpdate()
{
	level.FixedUpdate();
}

void GameManager::Stop()
{
	level.Stop();
}
