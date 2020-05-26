#pragma once
#include "Core/Manager.h"
#include "SFML/Network.hpp"
#include "SFML/Network/IpAddress.hpp"
#include <thread>
#include "Core/GameServer.h"
#include "Core/GameClient.h"
#define NetworkingManager NetworkManager::Instance()
#define MAX_CLIENTS 3
enum class NetworkMode {
	Server,
	Client
};

enum class NetworkingStatus {
	Idle,
	Sending,
	Receiving,
	Disconnected
};


class NetworkSyncedObject;

class NetworkManager :
	public Manager
{
private:
	static NetworkManager* instance;

	NetworkMode m_mode = NetworkMode::Client;

	GameServer* m_server;
	GameClient* localClient;

	sf::IpAddress m_publicAddress;

	float addressLookupTimeout = 3.0f;

	sf::TcpSocket* connectionToHostSocket;

	std::vector<sf::TcpSocket*> clientSockets;

public:
	static NetworkManager& Instance();

	void Start() override;
	void Stop() override;

	void StartAsServer();
	void StartAsClient();

	void StartGame();

	void OnClientConnectionSuccess();

	void StopAllConnections();


	sf::IpAddress GetPublicIPAddress();
	sf::IpAddress GetLocalIPAddress();
	int GetClientCount();

	GameClient* GetLocalClient();
};

