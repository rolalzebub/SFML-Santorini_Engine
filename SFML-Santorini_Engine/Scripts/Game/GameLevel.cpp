#include "GameLevel.h"
#include "Managers/InputManager.h"
#include <Game/P_Builder.h>

void GameLevel::setup()
{
    for (int i = 0; i < GRID_COLS; i++) {
        for (int j = 0; j < GRID_ROWS; j++) {
            tiles[i][j].setPosition(sf::Vector2f(i * tiles[i][j].GetSize().x, j * tiles[i][j].GetSize().y));
            tiles[i][j].level = 0;

            AddGameObject(&tiles[i][j]);
        }
    }

    for (int n = 0; n < MAX_PLAYERS; n++) {
        if (n == m_numPlayers)
            break;
    }

    turn = 0;
    current_State = gamestate::place;
}

void GameLevel::Start()
{
    setup();
    for (auto& go : m_gameObjects) {
        go->Start();
    }
}

void GameLevel::Update()
{
    for (auto& go : m_gameObjects) {
        go->Update();
    }
    switch (current_State) {
        case gamestate::place:
            place();
            break;
        case gamestate::selecting_builder:
            selectBuilder();
            break;
        case gamestate::moving_builder:
            movePhase();
            break;
        case gamestate::building_piece:
            buildPhase();
            break;
    }
}

void GameLevel::Stop()
{
    for (auto& go : m_gameObjects) {
        go->Stop();
    }
}

// Place the builders at the beginning of the game
void GameLevel::place()
{
    sf::Vector2i mouse_pos = Input.GetMousePosition();

    if (Input.IsMouseLeftReleased()) {

        for (int i = 0; i < GRID_COLS; i++) {
            for (int j = 0; j < GRID_ROWS; j++) {

                sf::Vector2f currentTilePos = tiles[i][j].getPosition();

                if (mouse_pos.x >= currentTilePos.x && mouse_pos.x <= currentTilePos.x + tiles[i][j].GetSize().x) {
                    if (mouse_pos.y >= currentTilePos.y && mouse_pos.y <= currentTilePos.y + tiles[i][j].GetSize().y) {
                        std::cout << "Placed builder at " << currentTilePos.x << " " << currentTilePos.y << std::endl;

                        //Create new P_Builder on the tile
                        auto new_builder = new P_Builder();
                        new_builder->setPosition(tiles[i][j].getPosition());
                        
                        builders.push_back(new_builder);
                        AddGameObject(new_builder);

                        new_builder->Start();

                        //Assign ownership to player whose turn it is
                        new_builder->SetOwnerID(turn);

                        //If player is done placing all builders, progress to next turn
                        if (firstBuilderPlaced == false) {
                            firstBuilderPlaced = true;
                        }
                        else{
                            firstBuilderPlaced = false;
                            turn++;
                            if (turn >= m_numPlayers) {
                                turn = 0;
                                current_State = gamestate::selecting_builder;
                            }
                        }
                    }
                }
            }
        }

    }
}

void GameLevel::selectBuilder()
{
    for (auto& b : builders) {
        if (b->GetOwnerID() == turn) {
            b->HighlightGreen();
        }
    }


    if (Input.IsMouseLeftReleased()) {

        sf::Vector2i mouse_pos = Input.GetMousePosition();
        
        for (int i = 0; i < GRID_COLS; i++) {
            for (int j = 0; j < GRID_ROWS; j++) {

                sf::Vector2f currentTilePos = tiles[i][j].getPosition();

                if (mouse_pos.x >= currentTilePos.x && mouse_pos.x <= currentTilePos.x + tiles[i][j].GetSize().x) {
                    if (mouse_pos.y >= currentTilePos.y && mouse_pos.y <= currentTilePos.y + tiles[i][j].GetSize().y) {

                        for (auto& b : builders) {
                            if (currentTilePos == b->getPosition()) {
                                b->HighlightRed();
                                ShowAvailableMoveSpacesForBuilder(b);
                                current_State = gamestate::moving_builder;
                                currently_selected_builder = b;
                            }
                        }

                    }
                }
            }
        }
    }
}

void GameLevel::buildPhase()
{
}

void GameLevel::movePhase()
{
}

void GameLevel::ShowAvailableMoveSpacesForBuilder(P_Builder* builder)
{
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if ((i == 0 && j == 0) == false) {

                sf::Vector2f positionToCompare = builder->getPosition();
                positionToCompare.x += j * tiles[0][0].GetSize().x;
                positionToCompare.y += i * tiles[0][0].GetSize().y;

                for (int i = 0; i < GRID_COLS; i++) {
                    for (int j = 0; j < GRID_ROWS; j++) {
                        if (tiles[i][j].getPosition() == positionToCompare) {
                            tiles[i][j].HighlightGreen();
                        }
                    }
                }
            }
        }
    }
}


void GameLevel::update()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            tiles[i][j].Update();
        }
    }
}

