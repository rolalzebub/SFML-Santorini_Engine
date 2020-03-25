#pragma once
#include "Core/utility_headers.h"
#include "gameTile.h"
#include "Core/Level.h"

#define MAX_PLAYERS 4

enum class gamestate {
    place,
    play,
    victory,
    defeat,
    terminate
};

class GameManager;
class P_Builder;

class GameLevel: public Level
{

private:
    GameManager* g = nullptr;

    //2-4 players
    int m_numPlayers = 2;

    
    
    
    gameTile tiles[5][5];
    std::vector<P_Builder*> builders;
    gamestate current_State;

    unsigned short turn = 0;
    void place();
    void selectBuilder();
    void playRound();
public:
    /*world(sf::RenderWindow& w, GameManager* g);
    ~world();*/
    void update();
    void setup();

    void Start() override;
    void Update() override;
    void Stop() override;

};