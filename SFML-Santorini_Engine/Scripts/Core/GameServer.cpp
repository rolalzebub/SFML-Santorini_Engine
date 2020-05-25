#include "GameServer.h"
#include "Managers/NetworkManager.h"


void GameServer::StartListeningServer()
{
	std::thread tcpListenerThread([&]() {
		sf::TcpListener listener;

		while (clientSockets.size() < 2) {
			std::cout << "Waiting for client" << std::endl;
			sf::TcpSocket* newClient = new sf::TcpSocket();
			sf::Packet packet;

			listener.listen(m_port);
			sf::Socket::Status status = listener.accept(*newClient);

			while (status == newClient->Disconnected ||
				status == newClient->Error) {
				status = listener.accept(*newClient);
			}

			std::cout << " New client: " << newClient->getRemoteAddress() << std::endl;

			clientSockets.push_back(newClient);

			packet << sf::String("Connected to server");
			newClient->send(packet);

		}
	});
	tcpListenerThread.detach();
}

void GameServer::StartGame()
{
	sf::Packet packet;
	packet << (int) PacketType::GameStart;

	for (auto& c : clientSockets) {
		
		c->send(packet);
		
	}

}

int GameServer::ClientCount()
{
	return clientSockets.size();
}
