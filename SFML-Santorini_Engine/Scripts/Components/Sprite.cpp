#include "Sprite.h"
#include "Core/GameObject.h"
#include "Managers/RenderManager.h"
Sprite::Sprite(GameObject* parent) : Component(parent)
{
}

void Sprite::OnStart()
{
	Renderer.AddSprite(this);
}

void Sprite::OnUpdate()
{

}

void Sprite::Stop()
{
}

void Sprite::LoadTexture(const std::string& path)
{
	sf::Texture new_tex;
	new_tex.loadFromFile(path);


	m_spriteTexture->setTexture(sf::Texture(new_tex));
}

void Sprite::SetTexture(const sf::Texture& texture)
{
	m_spriteTexture = makeUPtr<sf::Sprite>(texture);
}

sf::Sprite* Sprite::GetSprite()
{
	return m_spriteTexture.get();
}
