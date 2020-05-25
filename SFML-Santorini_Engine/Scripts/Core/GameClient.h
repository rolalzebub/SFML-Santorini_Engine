#pragma once
#include <SFML/Network.hpp>
#include "Core/utility_headers.h"

#ifndef clientPort
#define clientPort m_port+1
#endif

class GameClient
{
	sf::String clientName;

	sf::TcpListener clientListener;

	uPtr<sf::TcpSocket> cxnSocket;
	int sessionPlayerID = -1;
	bool ready;
	
	bool localHostMode = false;
	
	bool keepListenerActive = true;

	bool myTurn = false;

public:
	void OnStart();
	void OnUpdate();
	void OnStop();

	void RunListenerThread();
	void ConnectToLocalhost();
	void SendConnectionRequest(const std::string& ip);

	void StartCommandListener();
};

