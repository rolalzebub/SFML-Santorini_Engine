#include "GameLevel.h"
#include "Managers/InputManager.h"
#include <Game/P_Builder.h>
#include "Managers/NetworkManager.h"
void GameLevel::setup()
{
    for (int i = 0; i < GRID_COLS; i++) {
        for (int j = 0; j < GRID_ROWS; j++) {
            tiles[i][j].setPosition(sf::Vector2f(i * tiles[i][j].GetSize().x, j * tiles[i][j].GetSize().y));
            

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
    current_State = gamestate::waiting_for_turn;
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

        if (firstBuilderPlaced) {
            current_State = gamestate::waiting_for_turn;
        }
        else firstBuilderPlaced = true;

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

                message.sendingPlayerID = localClient->GetID();

                message.builderNewPos = clickedTile.getPosition();

                localClient->SendGameMessageToServer(message);
                    
                current_State = gamestate::building_piece;

                break;

            }
        }

        break;

    case gamestate::building_piece:

        message.msgType = MsgType::BuildOnTile;

        message.tileID = clickedTile.GetTileID();

        localClient->SendGameMessageToServer(message);

        localClient->EndTurn();

        current_State = gamestate::waiting_for_turn;
        
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

void GameLevel::WinConditionReached(int playerID)
{
    GameMessage newMsg;

    newMsg.builderID = playerID;

    localClient->SendGameMessageToServer(newMsg);
}

std::vector<P_Builder*> GameLevel::GetBuilders()
{
    return builders;
}

void GameLevel::ShowAvailableMoveSpacesForBuilder(P_Builder* builder)
{
    currently_selected_builder = builder;

    for (int i = 0; i < GRID_COLS; i++) {
        for (int j = 0; j < GRID_ROWS; j++) {

            //check if its not the tile youre standing on
            if (builder->getPosition() != tiles[i][j].getPosition())
            {
                sf::Vector2f difference = builder->getPosition() - tiles[i][j].getPosition();

                if (((difference.x > tiles[i][j].GetSize().x ||
                    difference.y > tiles[i][j].GetSize().y) == false) &&
                    ((-difference.x > tiles[i][j].GetSize().x ||
                        -difference.y > tiles[i][j].GetSize().y) == false))
                {
                    
                    if (builder->GetStandingLevel() <= tiles[i][j].GetTileHeight() + 1 &&
                        builder->GetStandingLevel() >= tiles[i][j].GetTileHeight() - 1)
                    {
                        bool builderOnTile = false;

                        for (auto& b : builders) {
                            if (b->getPosition() == tiles[i][j].getPosition()) {
                                builderOnTile = true;
                                break;
                            }
                        }

                        if (!builderOnTile) {
                            currentlyNavigableTiles.push_back(&tiles[i][j]);
                            tiles[i][j].HighlightGreen();
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

            for (auto& b : builders) {
                if (b->GetOwnerID() == localClient->GetID()) {
                    b->HighlightGreen();
                }
            }

            break;

        case MsgType::MoveBuilder:

            builders[msg.builderID]->setPosition(msg.builderNewPos);

            builders[msg.builderID]->SetStandingLevel(tiles[msg.tileID.x][msg.tileID.y].GetTileHeight());

            UnhighlightAll();

            if (builders[msg.builderID]->GetStandingLevel() == 2) {
                WinConditionReached(msg.sendingPlayerID);
            }

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
            new_builder->SetOwnerID(msg.sendingPlayerID);

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

