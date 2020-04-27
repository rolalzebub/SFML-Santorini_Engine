#pragma once
#include "Core/Manager.h"
#include "Game/GameLevel.h"
#include "Game/Levels/MainMenu.h"

#define Game GameManager::Instance()

enum class GameState {
    MainMenu,
    Hosting_Waiting_For_Players,
    FindingHost,
    Hosting_InGame,
    Client_InGame,
    GameFinsihed
};

class GameManager :
    public Manager
{


private:
    static GameManager* instance;
    MainMenu mainMenu;
    GameLevel level;

    Level* currentLevel;

    GameManager() { currentLevel = nullptr; };

public:
    static GameManager& Instance();
    void Start() override;
    void Update() override;
    void FixedUpdate() override;
    void Stop() override;

    void GoToMainMenu();
    void StartPlayLevel();
    void StopLevel();
    void QuitGame();
    Level* GetCurrentLevel();
};

