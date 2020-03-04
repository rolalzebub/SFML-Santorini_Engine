#pragma once
#include "Core/Manager.h"
#include "Game/GameLevel.h"

#define Game GameManager::Instance()

class GameManager :
	public Manager
{
    enum class gamestate {
        place,
        play,
        victory,
        defeat,
        terminate
    };

private:
    static GameManager* instance;

    GameLevel level;

    std::vector<GameObject*> activeObjects;

    GameManager() {};

public:
    static GameManager& Instance();
    void Start() override;
    void Update() override;
    void FixedUpdate() override;
    void Stop() override;
};

