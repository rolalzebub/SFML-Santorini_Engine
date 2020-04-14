#pragma once
#include "Game/Buttons/PlayButton.h"
#include "Managers/GameManager.h"
#include "Managers/UIManager.h"
void PlayButton::OnClick()
{
	std::cout << "Clicked";
	Game.StopLevel();
	UI_Manager.ClearUIObjects();
	Game.StartPlayLevel();
}
