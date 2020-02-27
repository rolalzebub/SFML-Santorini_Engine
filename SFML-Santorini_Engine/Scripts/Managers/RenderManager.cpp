#include "RenderManager.h"
#include "Components/Sprite.h"

RenderManager* RenderManager::instance{ nullptr };
void RenderManager::Render(sf::Drawable* object, const sf::Vector2f& position)
{
}

RenderManager& RenderManager::Instance()
{
	if (instance == nullptr)
		instance = new RenderManager;

	return *instance;
}

void RenderManager::Start()
{
	//Create window and assign it to the renderer
	m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), "SANTORINI");
}

void RenderManager::Update()
{
	for (auto& sp : m_sprites) {
		m_window->draw(*sp->GetSprite());
	}
}

void RenderManager::Stop()
{
}
