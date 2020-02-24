#include "Sprite.h"
#include "GameObject.h"
#include "Transform.h"
#include "RenderManager.h"
Sprite::Sprite(GameObject* parent) : Component(parent)
{
	m_parentTransform = m_parent->GetTransform();
}

void Sprite::OnStart()
{
	Renderer.AddSprite(this);
}

void Sprite::OnUpdate()
{
	m_spriteTexture->setPosition(m_parentTransform->getPosition());
	m_spriteTexture->setRotation(m_parentTransform->getRotation());
	m_spriteTexture->setScale(m_parentTransform->getScale());
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
