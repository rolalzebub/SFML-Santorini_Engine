#include "ConnectButton.h"
#include "Managers/GameManager.h"
#include "Game/Levels/MainMenu.h"

void ConnectButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Connect");
	button_Text.setCharacterSize(16);
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(70, 30));
	SetFillColour(sf::Color::Green);
}

void ConnectButton::OnClick()
{
	auto level = (MainMenu*)Game.GetCurrentLevel();
	level->ChangePage(menuPage::Client_Connecting);
}
