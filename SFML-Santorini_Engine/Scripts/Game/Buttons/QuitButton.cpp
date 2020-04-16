#include "QuitButton.h"
#include "Managers/GameManager.h"

void QuitButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Quit");
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(100, 60));
	SetFillColour(sf::Color::Green);
}

void QuitButton::OnClick()
{
	Game.QuitGame();
}
