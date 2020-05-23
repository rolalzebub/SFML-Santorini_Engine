#include "Game/Buttons/StartGameButton.h"
#include "Managers/NetworkManager.h"
void StartGameButton::Start()
{
	LoadFont("Data/Fonts/MontereyFLF.ttf");
	setText("Start Game");
	button_Text.setCharacterSize(16);
	SetFontColour(sf::Color::Black);
	setSize(sf::Vector2f(90, 30));
	SetFillColour(sf::Color::Green);
}

void StartGameButton::OnClick()
{
	NetworkingManager.StartGame();
}
