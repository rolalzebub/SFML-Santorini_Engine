#include "GameClient.h"
#include <thread>
#include "Core/GameServer.h"
#include "Managers/GameManager.h"
#include "Managers/NetworkManager.h"

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

		//std::this_thread::sleep_for(1s);

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
			cxnSocket->setBlocking(true);
			cxnSocket->receive(packet);


			GameMessage message;
			message.UnpackMessage(packet);

			std::cout << std::endl << "Server sent: " << (int) message.msgType;

			switch (message.msgType) {
			case MsgType::GameStart:
				Game.StartPlayLevel();
				break;

			case MsgType::TurnStart:
				myTurn = true;
				((GameLevel*)Game.GetCurrentLevel())->ReceiveMessage(message);
				break;
			default:
				std::cout << "Forwarding message to level" << std::endl;
				((GameLevel*)Game.GetCurrentLevel())->ReceiveMessage(message);
				break;
			}
		}
	});

	serverListenerThread.detach();

}

void GameClient::SendGameMessageToServer(GameMessage msg)
{
	sf::Packet packet;
	msg.FillPacketWithMessage(packet);

	if (msg.msgType == MsgType::PlaceBuilder) {
		if (firstBuilderPlaced == false) {
			firstBuilderPlaced = true;
		}
		else placePhaseFinished = true;
	}


	//std::thread([&] {
		sf::Socket::Status status = cxnSocket->send(packet);
	//}).detach();
}

bool GameClient::isTurn()
{
	return myTurn;
}

void GameClient::EndTurn()
{
	myTurn = false;
}

bool GameClient::PlacePhaseDone()
{
	return placePhaseFinished;
}
