#include "RenderManager.h"
#include "Sprite.h"

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
