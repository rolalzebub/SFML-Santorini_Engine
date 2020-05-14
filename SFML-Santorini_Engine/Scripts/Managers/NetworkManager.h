#pragma once
#include "Core/Manager.h"
#include "SFML/Network.hpp"
#include "SFML/Network/IpAddress.hpp"
#include <thread>
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
	
	bool* runListenerThread;

	NetworkMode m_mode = NetworkMode::Client;

	int m_port = 5000;
	
	std::thread* current_thread;

	sf::IpAddress m_publicAddress;

	float addressLookupTimeout = 3.0f;

	sf::TcpSocket connectionHostSocket;

	std::vector<sf::TcpSocket*> clientSockets;

	std::vector<NetworkSyncedObject*> networkedObjects;

	NetworkSyncedObject* clientSyncedObject;

public:
	static NetworkManager& Instance();

	void Start() override;
	void Stop() override;

	void StartAsServer();
	void StartAsClient();

	void StartAcceptingConnections();
	void StopAcceptingConnections();
	void SendConnectionRequest(const std::string& ipAddress);

	void StopAllConnections();

	void AcceptClient(sf::TcpSocket* newClient);
	sf::IpAddress GetPublicIPAddress();
	sf::IpAddress GetLocalIPAddress();
	int GetClientCount();
};

