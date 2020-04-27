#pragma once
#include "Game/Buttons/PlayButton.h"
#include "Managers/GameManager.h"
#include "Managers/UIManager.h"
#include "Game/Levels/MainMenu.h"
void PlayButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Play");
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(100, 60));
	SetFillColour(sf::Color::Green);
}
void PlayButton::OnClick()
{
	std::cout << "Clicked";
	auto menu = (MainMenu*) Game.GetCurrentLevel();
	menu->ChangePage(menuPage::SessionTypeSelect);
}
