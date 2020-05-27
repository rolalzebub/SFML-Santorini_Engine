#include "GameServer.h"
#include "Managers/NetworkManager.h"
#include "Managers/GameManager.h"
#include "GameClient.h"
void GameServer::NextTurn()
{
	turnID++;
	currentTurn_firstBuilderPlaced = false;

	if (turnID >= players.size()) {
		if (!placePhaseOver) {
			placePhaseOver = true;
			currentTurn_firstBuilderPlaced = true;
			currentTurn_Phase = TurnPhase::Moving;

			localBuilders = ((GameLevel*)Game.GetCurrentLevel())->GetBuilders();

		}
		turnID = 0;
	}
	SendTurnStart(turnID);
}
void GameServer::WinConditionReached(int playerID)
{

	GameMessage winMsg, lossMsg;

	winMsg.msgType = MsgType::Victory;

	lossMsg.msgType = MsgType::Defeat;

	for (int i = 0; i < players.size(); i++) {
		sf::Packet packet;

		if (i == playerID) {
			winMsg.FillPacketWithMessage(packet);
			players[i].connector->send(packet);
		}

		else {
			lossMsg.FillPacketWithMessage(packet);
			players[i].connector->send(packet);
		}
	}

}
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

			PlayerInfo newPlayer;
			newPlayer.connector = newClient;
			newPlayer.PlayerID = players.size();

			players.push_back(newPlayer);

			packet << sf::String("Connected to server") << newPlayer.PlayerID;
			newClient->send(packet);

		}
	});
	tcpListenerThread.detach();
}

void GameServer::StartGame()
{
	sf::Packet packet;
	packet << (int) MsgType::GameStart;

	for (auto& c : clientSockets) {
		
		c->send(packet);
		
	}
	gameActive = true;

	StartGameCommandEchoService();
	turnID = 0;
	SendTurnStart(turnID);

}

void GameServer::StartGameCommandEchoService()
{
	std::thread commandListener([&] {
		for (auto& s : clientSockets) {
			clientselector.add(*s);
		}

		while (gameActive) {
			
			clientselector.wait();
			for (auto& s : players) {
				if (clientselector.isReady(*s.connector)) {
					sf::Packet packet;
					s.connector->receive(packet);

					GameMessage newMsg;
					

					newMsg.UnpackMessage(packet);


					std::cout << "client sent: " << (int)newMsg.msgType << std::endl;

					//if (ValidateMessage(newMsg)) {

						for (auto& s : clientSockets) {
							s->send(packet);
						}

						switch (newMsg.msgType) {
						case MsgType::PlaceBuilder:
							if (currentTurn_firstBuilderPlaced) {
								NextTurn();
							}
							else currentTurn_firstBuilderPlaced = true;
							break;

						case MsgType::MoveBuilder:
							currentTurn_Phase = TurnPhase::Building;

							for (auto& b : localBuilders) {
								if (b->GetStandingLevel() == 2) {
									WinConditionReached(b->GetOwnerID());
								}
							}

							break;

						case MsgType::BuildOnTile:
							currentTurn_Phase = TurnPhase::Moving;
							NextTurn();
							break;
						}
						
					//}
				}
			}
		}
	});
	commandListener.detach();
}

int GameServer::ClientCount()
{
	return clientSockets.size();
}

void GameServer::SendTurnStart(int playerID)
{
	GameMessage msg;

	msg.msgType = MsgType::TurnStart;

	sf::Packet packet;

	msg.FillPacketWithMessage(packet);

	clientSockets[playerID]->send(packet);
}

bool GameServer::ValidateMessage(GameMessage message)
{
	bool result = false;

	if (message.msgType == MsgType::GameStart ||
		message.msgType == MsgType::TurnStart ||
		message.msgType == MsgType::Quit) {

		result = true;

		return result;
	}

	switch (message.msgType) {

	case MsgType::PlaceBuilder:
		if (message.sendingPlayerID == turnID)
		{
			if (placePhaseOver) {
				result = false;
				break;
			}

			result = true;
		}
		break;

	case MsgType::BuildOnTile:
		result = true;
		break;

	case MsgType::MoveBuilder:
		result = true;

		break;

	}


	return result;
}
