#pragma once
#include "utility_headers.h"
#include "Manager.h"
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>



enum class ManagerMode {
	AllUpdates,
	FixedUpdateOnly
};
#define GetEngine Engine::Instance()
class Engine
{
private:
	static Engine* instance;
	std::shared_ptr<sf::RenderWindow> m_window;


	sf::Clock engineClock;
	sf::Time fixedUpdateInterval;
	sf::Time frameDeltaTime;
	sf::Time elapsedTime;
	sf::Time timeSinceLastFixedUpdate;

	//For Managers who are to be called every frame as well as fixed update, apart from start and stop
	std::vector<Manager*> managers_toUpdate;
	//For Managers who are to be called on fixed update only, apart from start and stop
	std::vector<Manager*> managers_toFixedUpdateOnly;
public:
	static Engine& Instance();

	void Start();

	void Update();

	void Stop();

	void AddManager(Manager* manager, ManagerMode mode);
	
};