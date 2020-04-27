#pragma once
#include "Core/Level.h"
#include "Game/Buttons/PlayButton.h"
#include "Game/Buttons/QuitButton.h"
#include "Game/Buttons/HostButton.h"
#include "Game/Buttons/ClientButton.h"
#include "Game/Buttons/CancelButton.h"
#include "Game/UI/InputTextArea.h"
#include "Game/Buttons/ConnectButton.h"
#include "Game/Buttons/BackButton.h"

enum class menuPage {
	MainPage,
	SessionTypeSelect,
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
	menuPage currentPage = menuPage::MainPage;
	menuPage previousPage = currentPage;

	PlayButton playButton;
	QuitButton quitButton;

	HostButton hostButton;
	ClientButton clientButton;

	CancelButton cancelButton;

	ConnectButton connectButton;

	BackButton backButton;

	InputTextArea ClientTypingHostIP;

	std::vector<UIObject*> currentUIObjects;

public:
	void Start() override;
	void Update() override;
	void Stop() override;

	void ChangePage(menuPage page);
	void GoPreviousPage();
};

