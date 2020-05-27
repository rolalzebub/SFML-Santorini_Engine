#pragma once
#include "Core/utility_headers.h"
#include "gameTile.h"
#include "Core/Level.h"
#include <queue>
#include "Core/GameMessage.h"
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

    int m_numPlayers = 2;

    bool firstBuilderPlaced = false;
    gameTile tiles[5][5];
    std::vector<P_Builder*> builders;
    gamestate current_State;

    P_Builder* currently_selected_builder;

    unsigned short turn = 0;

    //only need messages for place move and build think about it
    std::queue<GameMessage> messageQueue;

    std::vector<gameTile*> currentlyNavigableTiles;

    void ShowAvailableMoveSpacesForBuilder(P_Builder* builder);

    void ProcessMessages();
public:
    void update();
    void setup();
    //void placePhase();
    //void selectBuilder();
    //void movePhase();
    //void buildPhase();

    void Start() override;
    void Update() override;
    void Stop() override;

    gameTile* CheckIfClickedTile();

    void ReceiveMessage(GameMessage msg);

    int GetTurnID();
    void ProcessInput(gameTile& clickedTile);

    void UnhighlightAll();

    void WinConditionReached(int playerID);
    std::vector<P_Builder*> GetBuilders();
};