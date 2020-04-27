#include "MainMenu.h"
#include "Managers/UIManager.h"
void MainMenu::Start()
{
	
	playButton.setPosition(150, 100);
	quitButton.setPosition(150, 300);

	hostButton.setPosition(150, 100);
	hostButton.isDrawable(false);

	backButton.setPosition(50, 50);
	backButton.isDrawable(false);

	clientButton.setPosition(150, 300);
	clientButton.isDrawable(false);

	UI_Manager.AddUIObject(&playButton);
	UI_Manager.AddUIObject(&quitButton);
	UI_Manager.AddUIObject(&hostButton);
	UI_Manager.AddUIObject(&backButton);
	UI_Manager.AddUIObject(&clientButton);

	currentUIObjects.push_back(&playButton);
	currentUIObjects.push_back(&quitButton);
}

void MainMenu::Update()
{
	
}

void MainMenu::Stop()
{
	UI_Manager.ClearUIObjects();
}

void MainMenu::ChangePage(menuPage page)
{
	switch (page) {
	case menuPage::MainPage:
		for (auto& ob : currentUIObjects) {
			ob->isDrawable(false);
		}
		currentUIObjects.clear();
		playButton.isDrawable(true);
		quitButton.isDrawable(true);
		currentUIObjects.push_back(&playButton);
		currentUIObjects.push_back(&quitButton);
		break;

	case menuPage::SessionTypeSelect:
		for (auto& ob : currentUIObjects) {
			ob->isDrawable(false);
		}
		currentUIObjects.clear();
		hostButton.isDrawable(true);
		clientButton.isDrawable(true);
		backButton.isDrawable(true);
		currentUIObjects.push_back(&clientButton);
		currentUIObjects.push_back(&backButton);
		currentUIObjects.push_back(&hostButton);
		break;

	case menuPage::Hosting_Waiting:
		for (auto& ob : currentUIObjects) {
			ob->isDrawable(false);
		}
		
		break;

	case menuPage::Hosting_InLobby:
		break;

	case menuPage::Client_EnteringHostIP:
		break;

	case menuPage::Client_Connecting:
		break;

	case menuPage::Client_InLobby:	
		break;
	}
	previousPage = currentPage;
	currentPage = page;
}

void MainMenu::GoPreviousPage()
{
	ChangePage(previousPage);
}
