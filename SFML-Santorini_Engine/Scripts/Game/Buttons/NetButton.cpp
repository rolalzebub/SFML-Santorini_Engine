#include "Game/Buttons/NetButton.h"
#include "Managers/GameManager.h"
#include "Game/Levels/MainMenu.h"

void NetButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Internet");
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(100, 60));
	SetFillColour(sf::Color::Green);
}

void NetButton::OnClick()
{
	((MainMenu*)Game.GetCurrentLevel())->SetOnlineSession(true);
	((MainMenu*)Game.GetCurrentLevel())->ChangePage(menuPage::Hosting_Waiting);
}
