#include "GameLevel.h"
#include "P_Builder.h"

void GameLevel::setup()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tiles[i][j].GetTransform()->setPosition(sf::Vector2f(i, j));
            tiles[i][j].level = 0;
        }
    }
    place();
    turn = 0;
}

// Place the builders at the beginning of the game
void GameLevel::place()
{
    // TODO: let the players choose
    /*builders.push_back(P_Builder(1, 1, 0));
    builders.push_back(P_Builder(3, 3, 0));
    builders.push_back(P_Builder(3, 1, 1));
    builders.push_back(P_Builder(1, 3, 1));*/
}

void GameLevel::selectBuilder()
{
}


void GameLevel::update()
{
    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    //    // TODO
    //}
}
