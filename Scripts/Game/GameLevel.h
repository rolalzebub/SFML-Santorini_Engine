#pragma once
#include "utility_headers.h"
#include "gameTile.h"
class GameLevel
{
	class GameManager;
    class P_Builder;
private:
    GameManager* g;

    //2-4 players
    int m_numPlayers = 2;
    
    
    gameTile tiles[5][5];
    std::vector<P_Builder> builders;

    unsigned short turn;
    void place();
    void selectBuilder();

public:
    /*world(sf::RenderWindow& w, GameManager* g);
    ~world();*/
    void update();
    void setup();

    //std::vector<sf::Drawable*> GetActiveObjects();

};