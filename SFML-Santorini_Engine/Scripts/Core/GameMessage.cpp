#include "GameMessage.h"
#include "Managers/NetworkManager.h"

void GameMessage::FillPacketWithMessage(sf::Packet& packet)
{
	packet << (int) msgType;
	packet << sendingPlayerID;
	packet << builderID;
	packet << builderNewPos.x << builderNewPos.y;
	packet << tileID.x << tileID.y;

}

void GameMessage::UnpackMessage(sf::Packet& packet)
{
	int type;
	packet >> type;
	msgType = (MsgType) type;

	packet >> sendingPlayerID;
	packet >> builderID;
	packet >> builderNewPos.x >> builderNewPos.y;
	packet >> tileID.x >> tileID.y;

}
