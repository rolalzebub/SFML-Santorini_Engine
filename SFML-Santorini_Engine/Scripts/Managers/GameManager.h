#pragma once
#include "Core/Manager.h"
#include "Game/GameLevel.h"

#define Game GameManager::Instance()

class GameManager :
	public Manager
{
    

private:
    static GameManager* instance;

    GameLevel level;

    GameManager() {};

public:
    static GameManager& Instance();
    void Start() override;
    void Update() override;
    void FixedUpdate() override;
    void Stop() override;
};

