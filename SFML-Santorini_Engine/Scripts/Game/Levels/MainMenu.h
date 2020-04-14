#pragma once
#include "Core/Level.h"
#include "Game/Buttons/PlayButton.h"
class MainMenu :
	public Level
{
private:
	PlayButton playButton;

public:
	void Start() override;
	void Update() override;
	void Stop() override;
};

