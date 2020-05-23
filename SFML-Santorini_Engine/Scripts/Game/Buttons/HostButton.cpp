#include "Scripts\Game\Buttons\HostButton.h"
#include "Managers/GameManager.h"
#include "Game/Levels/MainMenu.h"

void HostButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Host");
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(100, 60));
	SetFillColour(sf::Color::Green);
}

void HostButton::OnClick()
{
	((MainMenu*)Game.GetCurrentLevel())->ChangePage(menuPage::SessionNetworkTypeSelect);
}
