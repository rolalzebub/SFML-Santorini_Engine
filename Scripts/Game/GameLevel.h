#pragma once
#include "utility_headers.h"
class GameLevel
{
	class GameManager;
private:
    GameManager* g;

    //2-4 players
    int m_numPlayers = 2;
    
    
    //std::array<std::array<tile, 5>, 5> tiles{ {{{tile(), tile(), tile()}}, {{tile(), tile(), tile()}}, {{tile(), tile(), tile()}}} };
    //std::vector<builder> builders;

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