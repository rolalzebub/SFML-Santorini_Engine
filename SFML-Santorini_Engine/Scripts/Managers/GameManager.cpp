#include "GameManager.h"
#include "Core/Engine.h"
GameManager* GameManager::instance{ nullptr };
GameManager& GameManager::Instance()
{
	if (instance == nullptr)
		instance = new GameManager;

	return *instance;
}

void GameManager::Start()
{
	currentLevel = &mainMenu;
	currentLevel->Start();
}

void GameManager::Update()
{
	currentLevel->Update();
}

void GameManager::FixedUpdate()
{
	currentLevel->FixedUpdate();
}

void GameManager::Stop()
{
	currentLevel->Stop();
}

void GameManager::GoToMainMenu()
{
	currentLevel = &mainMenu;
}

void GameManager::StartPlayLevel()
{
	currentLevel = &level;
	currentLevel->Start();
}

void GameManager::StopLevel()
{
	currentLevel->Stop();
}

void GameManager::QuitGame()
{
	GetEngine.CloseWindow();
}

Level* GameManager::GetCurrentLevel()
{
	return currentLevel;
}

GameClient* GameManager::GetLocalClient()
{
	return &localClient;
}
