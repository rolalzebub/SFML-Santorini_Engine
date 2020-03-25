#include "Scripts\Managers\InputManager.h"

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

bool InputManager::IsMouseLeftPressed()
{
	return (sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

bool InputManager::IsMouseRightPressed()
{
	return (sf::Mouse::isButtonPressed(sf::Mouse::Right));
}

sf::Vector2i InputManager::GetMousePosition()
{
	return sf::Mouse::getPosition(*m_InputWindow);
}
