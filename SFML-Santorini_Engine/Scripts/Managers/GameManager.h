#pragma once
#include "Core/Manager.h"
#include "Game/GameLevel.h"
#include "Game/Levels/MainMenu.h"

#define Game GameManager::Instance()

class GameServer;

enum class GameState {
    MainMenu,
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

    GameServer* localServer = nullptr;
    GameClient localClient;

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

    GameClient* GetLocalClient();

};

