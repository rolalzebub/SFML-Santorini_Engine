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

	//std::thread TcpConnectThread([&]() {

		std::this_thread::sleep_for(1s);

		sf::IpAddress ipAddress(ip);
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

	//});
	//TcpConnectThread.detach();
}

void GameClient::StartCommandListener()
{
	std::thread serverListenerThread([&]() {
		sf::Packet packet;
		
		while (keepListenerActive) {
			cxnSocket->receive(packet);

			int msgType = -1;
			packet >> msgType; 
			PacketType pType = PacketType::Quit;
			if (msgType > -1) {
				pType = (PacketType)msgType;
			}

			std::cout << std::endl << "Server sent: " << msgType;

			switch (pType) {
			case PacketType::GameStart:
				Game.StartPlayLevel();
				break;
			}
		}
	});

	serverListenerThread.detach();

}
