#pragma once
#include "Core/Manager.h"
#include "SFML/Network.hpp"
#include "SFML/Network/IpAddress.hpp"

#define NetworkingManager NetworkManager::Instance()

enum class NetworkMode {
	Server,
	Client
};

class NetworkManager :
	public Manager
{
private:
	static NetworkManager* instance;

	NetworkMode m_mode = NetworkMode::Client;

	int m_port = 5000;
	
	sf::TcpListener m_listener;

	sf::IpAddress m_publicAddress = sf::IpAddress::None;

	float addressLookupTimeout = 3.0f;

public:
	static NetworkManager& Instance();

	void Start() override;
	void Stop() override;

	void StartAsServer();
	void StartAsClient();

	void StartAcceptingConnections();
	void StopAcceptingConnections();
	bool SendConnectionRequest(const std::string& ipAddress);
	bool SendConnectionRequest(sf::IpAddress ipAddress);

	sf::IpAddress GetPublicIPAddress();
	sf::IpAddress GetLocalIPAddress();
};

