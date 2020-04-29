#pragma once
#include "Core/Level.h"

//Menu buttons
#include "Game/Buttons/PlayButton.h"
#include "Game/Buttons/QuitButton.h"
#include "Game/Buttons/HostButton.h"
#include "Game/Buttons/ClientButton.h"
#include "Game/Buttons/CancelButton.h"
#include "Game/Buttons/ConnectButton.h"
#include "Game/Buttons/BackButton.h"
#include "Game/Buttons/LANButton.h"
#include "Game/Buttons/NetButton.h"


//Menu UI elements
#include "Game/UI/InputTextArea.h"
#include "Game/UI/TextDisplay.h"

#include <stack>

enum class menuPage {
	MainPage,
	SessionTypeSelect,
	SessionNetworkTypeSelect,
	Hosting_Waiting,
	Hosting_InLobby,
	Client_EnteringHostIP,
	Client_Connecting,
	Client_InLobby
};

class MainMenu :
	public Level
{
private:
	bool isOnlineSession = false;
	menuPage currentPage = menuPage::MainPage;
	std::stack<menuPage> pageHistory;

	PlayButton playButton;
	QuitButton quitButton;

	HostButton hostButton;
	ClientButton clientButton;

	CancelButton cancelButton;

	ConnectButton connectButton;

	BackButton backButton;

	LANButton lanPlayButton;
	NetButton netPlayButton;

	InputTextArea ClientTypingHostIP;


	TextDisplay hostIPDisplayMessage;
	TextDisplay hostIPDisplay;

	std::vector<UIObject*> currentUIObjects;


public:
	void Start() override;
	void Update() override;
	void Stop() override;

	void SetOnlineSession(bool type);
	void ChangePage(menuPage page);
	void GoPreviousPage();
};

