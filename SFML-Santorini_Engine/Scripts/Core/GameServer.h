#pragma once
#include <vector>
#include "SFML/Network.hpp"
#include "GameMessage.h"
#include "Game/P_Builder.h"
#ifndef m_port
#define m_port 5000
#endif

struct PlayerInfo {
	sf::String name = "";
	int PlayerID = -1;
	sf::TcpSocket* connector;
};

//phases of a player's turn once place phase has finished
enum TurnPhase {
	Moving,
	Building
};

//only need messages for place move and build think about it
class NetworkManager;
class GameClient;
class GameServer
{
	GameClient* localClient;

	sf::SocketSelector clientselector;

	std::vector<sf::TcpSocket*> clientSockets;

	std::vector<PlayerInfo> players;

	int turnID = -1;

	TurnPhase currentTurn_Phase;

	bool placePhaseOver = false;
	bool currentTurn_firstBuilderPlaced = false;

	bool gameActive = false;
	
	std::vector<P_Builder*> localBuilders;

	void NextTurn();

	void WinConditionReached(int playerID);
public:

	void StartListeningServer();

	void StartGame();

	void StartGameCommandEchoService();

	int ClientCount();

	void SendTurnStart(int playerID);

	bool ValidateMessage(GameMessage message);

};

