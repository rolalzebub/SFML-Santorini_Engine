#include "MainMenu.h"
#include "Managers/UIManager.h"
void MainMenu::Start()
{
	playButton.setText("Play");
	bool result = playButton.LoadFont("Data/Fonts/MontereyFLF.ttf");
	playButton.SetFontColour(sf::Color::Black);
	playButton.setSize(sf::Vector2f(100, 60));
	playButton.SetFillColour(sf::Color::Green);

	playButton.setPosition(100, 100);

	UI_Manager.AddUIObject(&playButton);
	m_gameObjects.push_back(&playButton);
}

void MainMenu::Update()
{
	
}

void MainMenu::Stop()
{
	UI_Manager.ClearUIObjects();
}
