#pragma once
#include "Core/utility_headers.h"
#include "gameTile.h"
#include "Core/Level.h"

#define MAX_PLAYERS 4
#define GRID_ROWS 5
#define GRID_COLS 5

enum class gamestate {
    waiting_for_turn,
    place,
    selecting_builder,
    moving_builder,
    building_piece,
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

    bool firstBuilderPlaced = false;
    gameTile tiles[5][5];
    std::vector<P_Builder*> builders;
    gamestate current_State;

    P_Builder* currently_selected_builder;

    unsigned short turn = 0;
    void place();
    void selectBuilder();
    void movePhase();
    void buildPhase();
    
    void ShowAvailableMoveSpacesForBuilder(P_Builder* builder);
public:
    void update();
    void setup();

    void Start() override;
    void Update() override;
    void Stop() override;

};