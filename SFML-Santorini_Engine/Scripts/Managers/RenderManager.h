#pragma once
#include "Manager.h"
#include "SFML/Graphics.hpp"
class Sprite;

#define Renderer RenderManager::Instance()
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
	
	void AddSprite(Sprite* sp) { m_sprites.push_back(sp); };
	void SetWindow(sf::RenderWindow* window) { m_window = window; }

};

