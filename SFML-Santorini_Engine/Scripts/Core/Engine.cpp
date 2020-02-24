#include "Core/Engine.h"
#include "Managers/RenderManager.h"


Engine* Engine::instance{ nullptr };

Engine& Engine::Instance()
{
	if (instance == nullptr)
		instance = new Engine;

	return *instance;
}

void Engine::Start()
{
	engineClock.restart();

	//Create window and assign it to the renderer
	//sf::RenderWindow new_window;

	for (auto& m : managers_toUpdate) {
		m->Start();
	}

	for (auto& m : managers_toFixedUpdateOnly) {
		m->Start();
	}

}

void Engine::Update()
{	
	frameDeltaTime = engineClock.getElapsedTime() - elapsedTime;
	timeSinceLastFixedUpdate += frameDeltaTime;

	for (auto& m : managers_toUpdate) {
		m->Update();
	}

	if (timeSinceLastFixedUpdate >= fixedUpdateInterval) {
		for (auto& m : managers_toUpdate) {
			m->FixedUpdate();
		}
		for (auto& m : managers_toFixedUpdateOnly) {
			m->Update();
			m->FixedUpdate();
		}
		timeSinceLastFixedUpdate = sf::Time::Zero;
	}

	elapsedTime += engineClock.getElapsedTime() - (elapsedTime + frameDeltaTime);
}

void Engine::Stop()
{
	for (auto& m : managers_toUpdate) {
		m->Stop();
	}
	for (auto& m : managers_toFixedUpdateOnly) {
		m->Stop();
	}
}

void Engine::AddManager(Manager* manager, ManagerMode mode)
{
	if (mode == ManagerMode::AllUpdates)
		managers_toUpdate.push_back(manager);

	else managers_toFixedUpdateOnly.push_back(manager);
}
