#pragma once
#include "Core/Manager.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics/RenderWindow.hpp"

#define Input InputManager::Instance()


class InputManager :
	public Manager
{
	static InputManager* instance;

	sf::RenderWindow* m_InputWindow;

	InputManager() {};

public:
	static InputManager& Instance();
	void Start() override;
	void Stop() override;

	void SetInputWindow(sf::RenderWindow* new_window) { m_InputWindow = new_window; }

	bool IsMouseLeftPressed();
	bool IsMouseRightPressed();

	sf::Vector2i GetMousePosition();
	
};

