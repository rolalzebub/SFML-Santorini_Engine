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

enum class PacketType {
	GameStart,			//nothing else needed
	TurnStart,			//Nothing else needed along with this
	Place,				//position of tile needed
	Move,				//position of new tile, and builder ID needed 
	Build,				//tile index in x,y format needed
	Quit				//nothing else needed
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

	void StartAcceptingConnections();
	void StopAcceptingConnections();
	void SendConnectionRequest(const std::string& ipAddress);

	void StopAllConnections();

	void SendPacket(PacketType pType, sf::Vector2f pos = sf::Vector2f(0, 0), int ID = -1);

	sf::IpAddress GetPublicIPAddress();
	sf::IpAddress GetLocalIPAddress();
	int GetClientCount();
};

