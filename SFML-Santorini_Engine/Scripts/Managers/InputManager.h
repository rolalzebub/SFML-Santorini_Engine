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
private:
	static InputManager* instance;

	sf::RenderWindow* m_InputWindow;

	bool mouseLeft_LastState;
	bool mouseRight_LastState;

	bool mouseLeft_Released;
	bool mouseRight_Released;

	InputManager() {};

public:
	static InputManager& Instance();
	void Start() override;
	void Stop() override;
	void Update() override;

	void SetInputWindow(sf::RenderWindow* new_window) { m_InputWindow = new_window; }

	bool IsMouseLeftPressed();
	bool IsMouseRightPressed();

	bool IsMouseLeftReleased();
	bool IsMouseRightReleased();

	sf::Vector2i GetMousePosition();

	bool isKeyPressed(sf::Keyboard::Key key);

	
};

