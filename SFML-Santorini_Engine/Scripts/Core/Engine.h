#pragma once
#include "utility_headers.h"
#include "Manager.h"
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#define DEFAULT_HEIGHT 600
#define DEFAULT_WIDTH 800


#define GetEngine Engine::Instance()
class Engine
{
private:
	static Engine* instance;
	sf::RenderWindow m_window;


	sf::Clock engineClock;
	sf::Time fixedUpdateInterval;
	sf::Time frameDeltaTime;
	sf::Time elapsedTime;
	sf::Time timeSinceLastFixedUpdate;

public:
	static Engine& Instance();

	void Start();

	void Update();

	void Stop();

	
};