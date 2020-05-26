#include "GameLevel.h"
#include "Managers/InputManager.h"
#include <Game/P_Builder.h>
#include "Managers/NetworkManager.h"
void GameLevel::setup()
{
    for (int i = 0; i < GRID_COLS; i++) {
        for (int j = 0; j < GRID_ROWS; j++) {
            tiles[i][j].setPosition(sf::Vector2f(i * tiles[i][j].GetSize().x, j * tiles[i][j].GetSize().y));
            tiles[i][j].level = 0;

            AddGameObject(&tiles[i][j]);

            tiles[i][j].SetTileID(sf::Vector2i(i, j));

        }
    }

    current_State = gamestate::place;
}

void GameLevel::Start()
{
    setup();
    for (auto& go : m_gameObjects) {
        go->Start();
    }
    localClient = NetworkingManager.GetLocalClient();
}

void GameLevel::Update()
{

    ProcessMessages();

    for (auto& go : m_gameObjects) {
        go->Update();
    }

    if (localClient->isTurn()) {
        if (Input.IsMouseRightReleased()) {
            
            UnhighlightAll();
            
            return;
        }

        gameTile* clickedTile = CheckIfClickedTile();

        if (clickedTile != nullptr) {
            ProcessInput(*clickedTile);
        }
    }
}

void GameLevel::Stop()
{
    for (auto& go : m_gameObjects) {
        go->Stop();
    }
}

gameTile* GameLevel::CheckIfClickedTile()
{
    gameTile* clickedTile = nullptr;

    sf::Vector2i mouse_pos = Input.GetMousePosition();

    if (Input.IsMouseLeftReleased()) {

        for (int i = 0; i < GRID_COLS; i++) {
            for (int j = 0; j < GRID_ROWS; j++) {

                sf::Vector2f currentTilePos = tiles[i][j].getPosition();

                if (mouse_pos.x >= currentTilePos.x && mouse_pos.x <= currentTilePos.x + tiles[i][j].GetSize().x) {
                    if (mouse_pos.y >= currentTilePos.y && mouse_pos.y <= currentTilePos.y + tiles[i][j].GetSize().y) {

                        return &tiles[i][j];

                    }
                }
            }
        }
    }

    return nullptr;
}


void GameLevel::ReceiveMessage(GameMessage msg)
{
    messageQueue.push(msg);
}

int GameLevel::GetTurnID()
{
    return turn;
}

void GameLevel::ProcessInput(gameTile& clickedTile)
{

    GameMessage message;
    message.sendingPlayerID = turn;

    switch (current_State)
    {
    case gamestate::waiting_for_turn:
        break;

    case gamestate::place:

        message.msgType = MsgType::PlaceBuilder;

        message.tileID = clickedTile.GetTileID();

        localClient->SendGameMessageToServer(message);

        break;

    case gamestate::selecting_builder:

        for (auto& b : builders) {
            if (b->getPosition() == clickedTile.getPosition()) {
                
                if (currently_selected_builder != nullptr) {
                    UnhighlightAll();
                }
                
                b->HighlightRed();
                currently_selected_builder = b;
                ShowAvailableMoveSpacesForBuilder(b);

                current_State = gamestate::moving_builder;

                break;
            }
        }

        break;
        
    case gamestate::moving_builder:

        for (int i = 0; i < currentlyNavigableTiles.size(); i++) {
            if (clickedTile.GetTileID() == currentlyNavigableTiles[i]->GetTileID()) {

                message.msgType = MsgType::MoveBuilder;

                message.builderID = currently_selected_builder->GetLevelID();

                message.tileID = clickedTile.GetTileID();

                message.sendingPlayerID = turn;

                message.builderNewPos = clickedTile.getPosition();

                localClient->SendGameMessageToServer(message);
                    
                break;

            }
        }

        break;

    case gamestate::building_piece:

        message.msgType = MsgType::BuildOnTile;

        message.tileID = clickedTile.GetTileID();

        localClient->SendGameMessageToServer(message);

        localClient->EndTurn();

        break;

    case gamestate::victory:
        break;

    case gamestate::defeat:
        break;

    case gamestate::terminate:
        break;
    }

}

void GameLevel::UnhighlightAll()
{
    for (int i = 0; i < GRID_COLS; i++) {
        for (int j = 0; j < GRID_ROWS; j++) {
            tiles[i][j].UnHighlight();
        }
    }

    for (auto& b : builders) {
        if (b->GetOwnerID() == turn) {
            b->HighlightGreen();
        }
        else b->UnHighlight();
    }

    currently_selected_builder = nullptr;
    currentlyNavigableTiles.clear();

    if (current_State == gamestate::moving_builder)
        current_State = gamestate::selecting_builder;
}

void GameLevel::ShowAvailableMoveSpacesForBuilder(P_Builder* builder)
{
    currently_selected_builder = builder;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if ((i == 0 && j == 0) == false) {

                sf::Vector2f positionToCompare = builder->getPosition();
                positionToCompare.x += j * tiles[0][0].GetSize().x;
                positionToCompare.y += i * tiles[0][0].GetSize().y;

                for (int i = 0; i < GRID_COLS; i++) {
                    for (int j = 0; j < GRID_ROWS; j++) {
                        if (tiles[i][j].getPosition() == positionToCompare) {
                            bool skipTile = false;
                            for (auto& b : builders) {
                                if (skipTile == true)
                                    break;

                                if (b->getPosition() == positionToCompare)
                                    skipTile = true;
                            }
                            if (skipTile == false) {
                                tiles[i][j].HighlightGreen();
                                currentlyNavigableTiles.push_back(&tiles[i][j]);
                            }
                        }
                    }
                }
            }
        }
    }
}

void GameLevel::ProcessMessages()
{
    while (!messageQueue.empty()) {
        GameMessage msg = messageQueue.front();
        switch (msg.msgType) {
        
        case MsgType::TurnStart:
            std::cout << "Starting turn" << std::endl;
            if (localClient->PlacePhaseDone()) {
                current_State = gamestate::selecting_builder;
            }
            else current_State = gamestate::place;
            break;

        case MsgType::MoveBuilder:

            builders[msg.builderID]->setPosition(msg.builderNewPos);

            UnhighlightAll();

            break;

        case MsgType::BuildOnTile:
            
            tiles[msg.tileID.x][msg.tileID.y].build();
            
            break;

        case MsgType::PlaceBuilder:

            //Create new P_Builder on the tile
            auto new_builder = new P_Builder();
            new_builder->setPosition(tiles[msg.tileID.x][msg.tileID.y].getPosition());

            builders.push_back(new_builder);
            AddGameObject(new_builder);

            new_builder->Start();

            //Assign ownership to player whose turn it is
            new_builder->SetOwnerID(turn);

            new_builder->SetLevelID(builders.size() - 1);

            break;

        }
        messageQueue.pop();
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

