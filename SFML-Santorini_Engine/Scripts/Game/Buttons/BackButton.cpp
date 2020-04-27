#include "BackButton.h"
#include "Managers/GameManager.h"
#include "Game/Levels/MainMenu.h"
void BackButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Back");
	button_Text.setCharacterSize(16);
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(70, 30));
	SetFillColour(sf::Color::Green);
}

void BackButton::OnClick()
{
	auto level = (MainMenu*)Game.GetCurrentLevel();
	level->GoPreviousPage();
}
