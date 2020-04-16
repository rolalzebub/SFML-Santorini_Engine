#pragma once
#include "Core/Level.h"
#include "Game/Buttons/PlayButton.h"
#include "Game/Buttons/QuitButton.h"
class MainMenu :
	public Level
{
private:
	PlayButton playButton;
	QuitButton quitButton;

public:
	void Start() override;
	void Update() override;
	void Stop() override;
};

