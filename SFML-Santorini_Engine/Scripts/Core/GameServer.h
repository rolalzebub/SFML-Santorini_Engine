#pragma once
#include <vector>
#include "SFML/Network.hpp"

#ifndef m_port
#define m_port 5000
#endif

class NetworkManager;

class GameServer
{
	sf::SocketSelector clientselector;

	std::vector<sf::TcpSocket*> clientSockets;


public:

	void StartListeningServer();

	void StartGame();

	int ClientCount();
};

