#pragma once
#include "Manager.h"
#include "GameLevel.h"
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
    GameLevel level;

public:
    void Start() override;
    void Update() override;
    void FixedUpdate() override;
    void Stop() override;
};

