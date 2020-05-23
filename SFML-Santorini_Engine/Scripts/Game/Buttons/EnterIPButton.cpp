#include "EnterIPButton.h"
#include "Managers/GameManager.h"
#include "Game/Levels/MainMenu.h"

void EnterIPButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Next");
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(100, 60));
	SetFillColour(sf::Color::Green);
}

void EnterIPButton::OnClick()
{
	((MainMenu*)Game.GetCurrentLevel())->ChangePage(menuPage::Client_EnteringHostIP);
}
