#pragma once
#include "Core/Manager.h"
#include "SFML/Graphics.hpp"

class Sprite;

#define Renderer RenderManager::Instance()
class RenderManager :
	public Manager
{
private:
	static RenderManager* instance;
	
	sf::RenderWindow* m_window = nullptr;
	std::vector<Sprite*> m_sprites;
	std::vector<sf::Drawable*> m_drawables;

	void Render(sf::Drawable* object, const sf::Vector2f& position);

	
public:
	static RenderManager& Instance();
	void Start() override;
	void Update() override;
	void FixedUpdate() override {};
	void Stop() override;
	
	int AddSprite(Sprite* sp);
	int AddDrawable(sf::Drawable* dr);
	
	void SetWindow(sf::RenderWindow* window) { m_window = window; }

	void DeleteSprite(int index);
	void DeleteDrawable(int index);

	void ClearUI();
};

