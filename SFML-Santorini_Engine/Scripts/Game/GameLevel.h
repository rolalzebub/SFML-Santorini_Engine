#pragma once
#include "Core/utility_headers.h"
#include "gameTile.h"
#include "P_Builder.h"
class GameLevel
{
	class GameManager;
private:
    GameManager* g = nullptr;

    //2-4 players
    int m_numPlayers = 2;
    
    
    gameTile tiles[5][5];
    std::vector<P_Builder> builders;

    unsigned short turn = 0;
    void place();
    void selectBuilder();

public:
    /*world(sf::RenderWindow& w, GameManager* g);
    ~world();*/
    void update();
    void setup();

    std::vector<GameObject*> GetActiveGameObjects();

};