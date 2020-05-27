#pragma once
#include "SFML/System.hpp"
#include "SFML/Network/Packet.hpp"
enum class MsgType {
    //for server-client only
    GameStart,
    TurnStart,

    //for actual game level
    PlaceBuilder,
    MoveBuilder,
    BuildOnTile,
    Victory,
    Defeat,
    Quit
};

class GameMessage
{
public:
        MsgType msgType;

        int sendingPlayerID = -1;

        int builderID = -1;

        sf::Vector2f builderNewPos = sf::Vector2f(-1, -1);

        sf::Vector2i tileID = sf::Vector2i(-1, -1);

        void FillPacketWithMessage(sf::Packet& packet);
        void UnpackMessage(sf::Packet& packet);
};

