#include "GameClient.h"
#include <thread>
#include "Core/GameServer.h"
#include "Managers/GameManager.h"
#include "Managers/NetworkManager.h"
void GameClient::RunListenerThread()
{
	std::thread listenerThread([&]() {
		sf::Packet packet;

		cxnSocket->receive(packet);

		PacketType pType;
		int type;
		packet >> type;

		pType = (PacketType) type;


		switch (pType) {
		case PacketType::GameStart:
			Game.StartPlayLevel();
			break;
		}

	});
}

void GameClient::ConnectToLocalhost()
{ 
	localHostMode = true;

	using namespace std::literals::chrono_literals;

	std::thread TcpConnectThread([&]() {

		std::this_thread::sleep_for(1s);

		sf::IpAddress ipAddress(sf::IpAddress::LocalHost);
		cxnSocket = makeUPtr<sf::TcpSocket>();
		sf::Packet packet;

		packet.clear();
		cxnSocket->setBlocking(true);

		sf::Socket::Status status = cxnSocket->connect(ipAddress, m_port);

		
		cxnSocket->receive(packet);
		sf::String serverResponse;
		packet >> serverResponse;
		std::cout << serverResponse.toAnsiString() << std::endl;


		std::cout << "Receive status: " << status << std::endl;

		if (status == cxnSocket->Done) {
			NetworkingManager.OnClientConnectionSuccess();
		}

	});
	TcpConnectThread.detach();
}

void GameClient::SendConnectionRequest(const std::string& ip)
{
	using namespace std::literals::chrono_literals;

	std::thread TcpConnectThread([&]() {

		std::this_thread::sleep_for(1s);

		sf::IpAddress ipAddress(ip);
		cxnSocket = makeUPtr<sf::TcpSocket>();
		sf::Packet packet;

		packet.clear();
		cxnSocket->setBlocking(true);

		sf::Socket::Status status = cxnSocket->connect(ip, m_port);


		cxnSocket->receive(packet);
		sf::String serverResponse;
		packet >> serverResponse;
		std::cout << serverResponse.toAnsiString() << std::endl;


		std::cout << "Receive status: " << status << std::endl;

		if (status == cxnSocket->Done) {
			NetworkingManager.OnClientConnectionSuccess();
		}

	});
	TcpConnectThread.detach();
}
