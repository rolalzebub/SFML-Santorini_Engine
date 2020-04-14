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
	for (auto* sp : m_sprites) {
		sp->OnUpdate();
		m_window->draw(*sp->GetSprite());
	}
}

void RenderManager::Stop()
{
}

int RenderManager::AddSprite(Sprite* sp)
{
	m_sprites.push_back(sp);
	return m_sprites.size() - 1;
}

int RenderManager::AddDrawable(sf::Drawable* dr)
{
	m_drawables.push_back(dr);
	return m_drawables.size() - 1;
}

void RenderManager::DeleteSprite(int index)
{
	m_sprites.erase(m_sprites.begin() + index);
}

void RenderManager::DeleteDrawable(int index)
{
	m_drawables.erase(m_drawables.begin() + index);
}

void RenderManager::ClearUI() 
{
	m_drawables.clear();
}
