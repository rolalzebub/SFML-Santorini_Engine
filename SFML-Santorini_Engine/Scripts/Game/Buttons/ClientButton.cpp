#include "ClientButton.h"
#include "Managers/GameManager.h"
#include "Game/Levels/MainMenu.h"

void ClientButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Client");
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(100, 60));
	SetFillColour(sf::Color::Green);
}

void ClientButton::OnClick()
{
	auto level = (MainMenu*)Game.GetCurrentLevel();
	level->ChangePage(menuPage::Client_EnteringName);
}
