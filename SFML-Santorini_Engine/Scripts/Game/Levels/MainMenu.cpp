#include "MainMenu.h"
#include "Managers/UIManager.h"
void MainMenu::Start()
{
	
	playButton.setPosition(100, 100);
	quitButton.setPosition(100, 300);

	UI_Manager.AddUIObject(&playButton);
	UI_Manager.AddUIObject(&quitButton);
}

void MainMenu::Update()
{
	
}

void MainMenu::Stop()
{
	UI_Manager.ClearUIObjects();
}
