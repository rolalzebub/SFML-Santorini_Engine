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
	
}

void RenderManager::Update()
{
	for (auto& dr : m_drawables) {
		m_window->draw(*dr);
	}
	for (auto& sp : m_sprites) {
		sp->OnUpdate();
		m_window->draw(*sp->GetSprite());
	}
}

void RenderManager::Stop()
{
}

void RenderManager::AddDrawable(sf::Drawable* dr)
{
	m_drawables.push_back(dr);
}
