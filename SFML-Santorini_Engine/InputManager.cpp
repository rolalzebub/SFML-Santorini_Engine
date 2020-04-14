#include "Scripts\Managers\InputManager.h"
#include "SFML/Window/Event.hpp"
InputManager* InputManager::instance{ nullptr };

InputManager& InputManager::Instance()
{
	if (instance == nullptr)
		instance = new InputManager;

	return *instance;
}

void InputManager::Start()
{
}

void InputManager::Stop()
{
}

void InputManager::Update()
{
	if (mouseLeft_LastState == true) {
		if (!IsMouseLeftPressed()) {
			mouseLeft_Released = true;
			mouseLeft_LastState = false;
		}
		else mouseLeft_Released = false;
	}
	else mouseLeft_Released = false;

	if (mouseRight_LastState == true) {
		if (!IsMouseRightPressed()) {
			mouseRight_Released = true;
			mouseRight_LastState = false;
		}
		else mouseRight_Released = false;
	}
	else mouseRight_Released = false;

	mouseLeft_LastState = IsMouseLeftPressed();
	mouseRight_LastState = IsMouseRightPressed();
}

bool InputManager::IsMouseLeftPressed()
{

	return (sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

bool InputManager::IsMouseRightPressed()
{
	return (sf::Mouse::isButtonPressed(sf::Mouse::Right));
}

bool InputManager::IsMouseLeftReleased()
{
	return mouseLeft_Released;
}

bool InputManager::IsMouseRightReleased()
{
	return mouseRight_Released;
}

sf::Vector2i InputManager::GetMousePosition()
{
	return sf::Mouse::getPosition(*m_InputWindow);
}
