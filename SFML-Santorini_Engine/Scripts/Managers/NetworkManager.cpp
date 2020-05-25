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
	localClient->ConnectToLocalhost();
}

void NetworkManager::StartAsClient()
{
	m_mode = NetworkMode::Client;
}

void NetworkManager::StartGame()
{
	((MainMenu*) Game.GetCurrentLevel())->Stop();

	m_server->StartGame();

	SendPacket(PacketType::GameStart);

	Game.StartPlayLevel();
}

void NetworkManager::OnClientConnectionSuccess()
{

	std::cout << "Client connected";

	localClient->StartCommandListener();
	//((MainMenu*)Game.GetCurrentLevel())->ChangePage(menuPage::Client_InLobby);

	//std::thread clientListenerThread([&] {
		/*sf::Packet packet;
		sf::Socket::Status status = connectionToHostSocket->receive(packet);
		
		int packetType;
		packet >> packetType;

		PacketType ptype = (PacketType)packetType;

		if (ptype == PacketType::GameStart) {
			Game.StartPlayLevel();
		}*/

	//}); clientListenerThread.detach();

}

void NetworkManager::StartAcceptingConnections()
{
	if (m_mode != NetworkMode::Server) {
		m_mode = NetworkMode::Server;
	}

	sf::TcpListener m_listener;

	std::vector<sf::TcpSocket*> new_clients;




}

void NetworkManager::StopAcceptingConnections()
{

	//current_thread->join();
}

void NetworkManager::SendConnectionRequest(const std::string& ipAddress)
{
	m_mode = NetworkMode::Client;
	
	localClient->SendConnectionRequest(ipAddress);

}

void NetworkManager::StopAllConnections()
{
	for (auto& obj : clientSockets) {
		obj->disconnect();
	}
	if(connectionToHostSocket != nullptr)
		connectionToHostSocket->disconnect();
}

void NetworkManager::SendPacket(PacketType pType, sf::Vector2f pos, int ID)
{

	sf::Packet packet;

	packet << (int) pType;
	//Access violation here on the socket, but why?!
	//std::thread sendPacketThread([&] {
		if (m_mode == NetworkMode::Server) {
			for (auto& c : clientSockets) {
				sf::Socket::Status status = c->send(packet);
				std::cout << status;
			}
		}
		else sf::Socket::Status status = connectionToHostSocket->send(packet);
	//});
	//sendPacketThread.detach();

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


