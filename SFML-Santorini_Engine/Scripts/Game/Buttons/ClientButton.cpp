#include "ClientButton.h"

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
}
