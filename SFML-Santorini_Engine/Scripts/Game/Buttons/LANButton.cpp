#include "LANButton.h"
#include "Managers/GameManager.h"
#include "Game/Levels/MainMenu.h"
void LANButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("LAN");
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(100, 60));
	SetFillColour(sf::Color::Green);
}

void LANButton::OnClick()
{
	((MainMenu*)Game.GetCurrentLevel())->SetOnlineSession(false);
	((MainMenu*)Game.GetCurrentLevel())->ChangePage(menuPage::Hosting_Waiting);
}
