#include "GameLevel.h"


void GameLevel::setup()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tiles[i][j].x = i;
            tiles[i][j].y = j;
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
    builders.push_back(builder(1, 1, 0));
    builders.push_back(builder(3, 3, 0));
    builders.push_back(builder(3, 1, 1));
    builders.push_back(builder(1, 3, 1));
}


void GameLevel::update()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // TODO
    }
}

