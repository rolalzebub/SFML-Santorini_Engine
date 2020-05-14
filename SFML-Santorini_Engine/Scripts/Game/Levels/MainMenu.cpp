#include "MainMenu.h"
#include "Managers/UIManager.h"
#include "Managers/NetworkManager.h"


void MainMenu::Start()
{
	
	playButton.setPosition(150, 100);
	quitButton.setPosition(150, 300);

	hostButton.setPosition(250, 100);
	hostButton.isDrawable(false);

	backButton.setPosition(50, 50);
	backButton.isDrawable(false);

	clientButton.setPosition(250, 300);
	clientButton.isDrawable(false);

	hostIPDisplay.setPosition(256, 200);
	hostIPDisplay.isDrawable(false);

	lanPlayButton.setPosition(356, 200);
	lanPlayButton.isDrawable(false);

	netPlayButton.setPosition(356, 300);
	netPlayButton.isDrawable(false);

	hostIPDisplayMessage.setPosition(256, 150);
	hostIPDisplayMessage.isDrawable(false);
	hostIPDisplayMessage.SetText("Server Address:");

	clientCount.setPosition(256, 250);
	clientCount.SetText("0");
	clientCount.isDrawable(false);

	maxPlayers.setPosition(280, 250);
	maxPlayers.SetText("/3 (1 required to start)");
	maxPlayers.isDrawable(false);

	connectButton.setPosition(400, 250);
	connectButton.isDrawable(false);


	UI_Manager.AddUIObject(&playButton);
	UI_Manager.AddUIObject(&quitButton);
	UI_Manager.AddUIObject(&hostButton);
	UI_Manager.AddUIObject(&backButton);
	UI_Manager.AddUIObject(&clientButton);
	UI_Manager.AddUIObject(&hostIPDisplay);
	UI_Manager.AddUIObject(&hostIPDisplayMessage);
	UI_Manager.AddUIObject(&lanPlayButton);
	UI_Manager.AddUIObject(&netPlayButton);
	UI_Manager.AddUIObject(&clientCount);
	UI_Manager.AddUIObject(&maxPlayers);
	UI_Manager.AddUIObject(&connectButton);

	ClientTypingHostIP.isDrawable(false);
	UI_Manager.AddUIObject(&ClientTypingHostIP);

	currentUIObjects.push_back(&playButton);
	currentUIObjects.push_back(&quitButton);
}

void MainMenu::Update()
{
	if(currentPage == menuPage::Hosting_Waiting)
		clientCount.SetText(std::to_string(NetworkingManager.GetClientCount()));
}

void MainMenu::Stop()
{
	UI_Manager.ClearUIObjects();
}

void MainMenu::SetOnlineSession(bool type)
{
	isOnlineSession = type;
}

void MainMenu::ChangePage(menuPage page)
{
	if (page == currentPage)
		return;

	for (auto& ob : currentUIObjects) {
		ob->isDrawable(false);
	}
	currentUIObjects.clear();

	if (pageHistory.size() > 0) {
		if (page == pageHistory.top()) {
			pageHistory.pop();
		}
		else pageHistory.push(currentPage);
	}
	else {
		pageHistory.push(currentPage);
	}

	if ((currentPage == menuPage::Client_Connecting ||
		currentPage == menuPage::Hosting_Waiting) &&
		(page != menuPage::Client_InLobby ||
			page!= menuPage::Hosting_InLobby))
	{
		NetworkingManager.StopAllConnections();
	}

	switch (page) {
	case menuPage::MainPage:
		
		playButton.isDrawable(true);
		quitButton.isDrawable(true);
		currentUIObjects.push_back(&playButton);
		currentUIObjects.push_back(&quitButton);
		break;

	case menuPage::SessionTypeSelect:
		
		hostButton.isDrawable(true);
		clientButton.isDrawable(true);
		backButton.isDrawable(true);
		currentUIObjects.push_back(&clientButton);
		currentUIObjects.push_back(&backButton);
		currentUIObjects.push_back(&hostButton);
		break;

	case menuPage::SessionNetworkTypeSelect:
		
		lanPlayButton.isDrawable(true);
		netPlayButton.isDrawable(true);
		backButton.isDrawable(true);

		currentUIObjects.push_back(&lanPlayButton);
		currentUIObjects.push_back(&netPlayButton);
		currentUIObjects.push_back(&backButton);
		break;
	case menuPage::Hosting_Waiting:
		
		if (isOnlineSession) {
			hostIPDisplay.SetText(NetworkingManager.GetPublicIPAddress().toString());
		}
		else hostIPDisplay.SetText(NetworkingManager.GetLocalIPAddress().toString());

		clientCount.isDrawable(true);
		maxPlayers.isDrawable(true);

		hostIPDisplay.isDrawable(true);
		hostIPDisplayMessage.isDrawable(true);
		backButton.isDrawable(true);
		currentUIObjects.push_back(&backButton);
		currentUIObjects.push_back(&hostIPDisplay);
		currentUIObjects.push_back(&hostIPDisplayMessage);
		currentUIObjects.push_back(&clientCount);
		currentUIObjects.push_back(&maxPlayers);

		NetworkingManager.StartAsServer();
		
		break;

	case menuPage::Hosting_InLobby:
		break;

	case menuPage::Client_EnteringHostIP:

		ClientTypingHostIP.isDrawable(true);
		backButton.isDrawable(true);
		connectButton.isDrawable(true);
		currentUIObjects.push_back(&connectButton);
		currentUIObjects.push_back(&ClientTypingHostIP);
		currentUIObjects.push_back(&backButton);
		break;

	case menuPage::Client_Connecting:

		backButton.isDrawable(true);

		currentUIObjects.push_back(&backButton);


		NetworkingManager.StartAsClient();
		NetworkingManager.SendConnectionRequest(ClientTypingHostIP.GetString());

		break;

	case menuPage::Client_InLobby:	
		break;
	}
	
	currentPage = page;
}

void MainMenu::GoPreviousPage()
{
	ChangePage(pageHistory.top());
}

