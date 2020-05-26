#include "NetworkManager.h"
#include "Game/Levels/MainMenu.h"
#include "GameManager.h"
NetworkManager* NetworkManager::instance{ nullptr };

NetworkManager& NetworkManager::Instance()
{
	if (instance == nullptr)
		instance = new NetworkManager;

	return *instance;
}

void NetworkManager::Start()
{
	localClient = Game.GetLocalClient();

	m_publicAddress = sf::IpAddress::getPublicAddress();
}

void NetworkManager::Stop()
{
}

void NetworkManager::StartAsServer()
{
	m_mode = NetworkMode::Server;

	m_server = new GameServer();
	m_server->StartListeningServer();

	localClient = new GameClient();
	localClient->ConnectToLocalhost();
}

void NetworkManager::StartAsClient()
{
	m_mode = NetworkMode::Client;
	localClient = new GameClient();
}

void NetworkManager::StartGame()
{
	((MainMenu*) Game.GetCurrentLevel())->Stop();

	m_server->StartGame();

}

void NetworkManager::OnClientConnectionSuccess()
{

	std::cout << "Client connected";

	localClient->StartCommandListener();

}

void NetworkManager::StopAllConnections()
{
	for (auto& obj : clientSockets) {
		obj->disconnect();
	}
	if(connectionToHostSocket != nullptr)
		connectionToHostSocket->disconnect();
}


sf::IpAddress NetworkManager::GetPublicIPAddress()
{
	if (m_publicAddress == sf::IpAddress::Any) {
		m_publicAddress = sf::IpAddress::getPublicAddress();
	}
	return m_publicAddress;
}

sf::IpAddress NetworkManager::GetLocalIPAddress()
{
	return sf::IpAddress::getLocalAddress();
}

int NetworkManager::GetClientCount()
{
	return m_server->ClientCount();
}

GameClient* NetworkManager::GetLocalClient()
{
	return localClient;
}


