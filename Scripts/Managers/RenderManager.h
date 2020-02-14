#pragma once
#include "Manager.h"
#include "SFML/Graphics.hpp"
#define Renderer RenderManager::Instance()
class Sprite;
class RenderManager :
	public Manager
{
private:
	static RenderManager* instance;
	
	sf::RenderWindow* m_window;
	std::vector<Sprite*> m_sprites;

	void Render(sf::Drawable* object, const sf::Vector2f& position);

	RenderManager() { m_window = nullptr; };

public:
	static RenderManager& Instance();
	void Start() override;
	void Update() override;
	void FixedUpdate() override {};
	void Stop() override;

};

