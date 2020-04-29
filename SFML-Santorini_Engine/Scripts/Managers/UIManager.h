#pragma once
#include "Core/Manager.h"
#include "Core/UIObject.h"

#define UI_Manager UIManager::Instance()

class UIManager :
	public Manager
{
private:
	static UIManager* instance;

	std::vector<UIObject*> UI_Objects;
	sf::Vector2i mousePos;

public:
	static UIManager& Instance();
	void Start() override;
	void Update() override;
	void Stop() override;

	void AddUIObject(UIObject* obj);
	void ClearUIObjects();
	void PassTextEvent(sf::Event& e);
};

