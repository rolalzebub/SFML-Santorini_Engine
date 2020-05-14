#include "Core/Engine.h"
#include "Managers/RenderManager.h"
#include "Managers/GameManager.h"
#include "Managers/InputManager.h"
#include "Managers/UIManager.h"
#include "Managers/NetworkManager.h"

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

	m_window.setFramerateLimit(60);

	m_window.setKeyRepeatEnabled(false);

	
	Game.Start();
	UI_Manager.Start();
	Renderer.Start();
	Renderer.SetWindow(&m_window);
	Input.Start();
	Input.SetInputWindow(&m_window);
	NetworkingManager.Start();
}

void Engine::Update()
{	
	frameDeltaTime = engineClock.getElapsedTime() - elapsedTime;
	timeSinceLastFixedUpdate += frameDeltaTime;

	sf::Event e;
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(e))
		{
			if (e.type == sf::Event::EventType::Closed)
				m_window.close();
			else if (e.type == sf::Event::EventType::TextEntered)
				UI_Manager.PassTextEvent(e);
		}
		m_window.clear();

		Input.Update();
		Game.Update();
		UI_Manager.Update();
		Renderer.Update();
		NetworkingManager.Update();
		if (timeSinceLastFixedUpdate >= fixedUpdateInterval) {

			timeSinceLastFixedUpdate = sf::Time::Zero;

			Game.FixedUpdate();
			Renderer.FixedUpdate();
			Renderer.UpdateUI();
		}

		m_window.display();
	}
	elapsedTime += engineClock.getElapsedTime() - (elapsedTime + frameDeltaTime);
}

void Engine::Stop()
{
	
}

void Engine::CloseWindow()
{
	m_window.close();
}

sf::Time Engine::GetDeltaTime()
{
	return frameDeltaTime;
}

sf::Time Engine::GetFixedUpdateTime()
{
	return fixedUpdateInterval;
}

sf::RenderWindow* Engine::GetRenderWindow()
{
	return &m_window;
}
