#include "GameLevel.h"
#include "Managers/InputManager.h"
#include <Game/P_Builder.h>

void GameLevel::setup()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
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
        case gamestate::play:
            
            playRound();
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

    if (Input.IsMouseLeftPressed()) {

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                sf::Vector2f currentTilePos = tiles[i][j].getPosition();

                if (mouse_pos.x >= currentTilePos.x && mouse_pos.x <= currentTilePos.x + tiles[i][j].GetSize().x) {
                    if (mouse_pos.y >= currentTilePos.y && mouse_pos.y <= currentTilePos.y + tiles[i][j].GetSize().y) {
                        std::cout << "Placed builder at " << currentTilePos.x << " " << currentTilePos.y << std::endl;
                    }
                }
            }
        }

    }
}

void GameLevel::selectBuilder()
{
}

void GameLevel::playRound()
{
}


void GameLevel::update()
{
    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    //    // TODO
    //}

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            tiles[i][j].Update();
        }
    }
}

