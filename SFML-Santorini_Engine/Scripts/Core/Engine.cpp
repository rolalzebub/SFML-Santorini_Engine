#include "Core/Engine.h"
#include "Managers/RenderManager.h"
#include "Managers/GameManager.h"


Engine* Engine::instance{ nullptr };

Engine& Engine::Instance()
{
	if (instance == nullptr)
		instance = new Engine;

	return *instance;
}

void Engine::Start()
{
	m_window.create(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), "Santorini");
	engineClock.restart();

	Renderer.Start();
	Game.Start();
	Renderer.SetWindow(&m_window);
}

void Engine::Update()
{	
	frameDeltaTime = engineClock.getElapsedTime() - elapsedTime;
	timeSinceLastFixedUpdate += frameDeltaTime;

	sf::Event e;
	while (m_window.isOpen())
	{
		m_window.pollEvent(e);
		
		m_window.clear();
		
		Game.Update();
		Renderer.Update();
		if (timeSinceLastFixedUpdate >= fixedUpdateInterval) {
			
			timeSinceLastFixedUpdate = sf::Time::Zero;

			Game.FixedUpdate();
			Renderer.FixedUpdate();
		}

		if (e.type == sf::Event::EventType::Closed)
			m_window.close();

		m_window.display();
	}
	elapsedTime += engineClock.getElapsedTime() - (elapsedTime + frameDeltaTime);
}

void Engine::Stop()
{
	
}
