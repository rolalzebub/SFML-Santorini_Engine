#include "UIManager.h"
#include "Managers/InputManager.h"
#include "Managers/RenderManager.h"

UIManager* UIManager::instance{ nullptr };

UIManager& UIManager::Instance()
{
	if (instance == nullptr)
		instance = new UIManager;

	return *instance;
}

void UIManager::Start()
{
	for (auto& obj : UI_Objects) {
		obj->Start();
		for (auto& dr : obj->GetDrawables()) {
			Renderer.AddDrawable(dr);
		}
	}
}

void UIManager::Update()
{

	if (Input.IsMouseLeftReleased()) {
		for (auto& obj : UI_Objects) {
			mousePos = Input.GetMousePosition();

			sf::Vector2f obj_extents (100, 100);
			sf::Vector2f obj_position = obj->getPosition();
			if (mousePos.x >= obj_position.x &&
				mousePos.x <= obj_position.x + obj_extents.x) {
				if (mousePos.y >= obj_position.y &&
					mousePos.y <= obj_position.y + obj_extents.y) {
					obj->OnClick();
				}
			}
		}
	}

	for (auto& obj : UI_Objects) {
		obj->Update();
	}
}

void UIManager::Stop()
{
	for (auto& obj : UI_Objects) {
		obj->Stop();
	}
}

void UIManager::AddUIObject(UIObject* obj)
{
	UI_Objects.push_back(obj);
	
}

void UIManager::ClearUIObjects()
{
	UI_Objects.clear();
	Renderer.ClearUI();
}
