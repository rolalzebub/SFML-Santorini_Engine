#include "Sprite.h"
#include "GameObject.h"

Sprite::Sprite(GameObject* parent) : Component(parent)
{
	m_parentTransform = &m_parent->GetTransform()->GetTransformable();
}

void Sprite::OnUpdate()
{
	m_spriteTexture->setPosition(m_parentTransform->getPosition());
	m_spriteTexture->setRotation(m_parentTransform->getRotation());
	m_spriteTexture->setScale(m_parentTransform->getScale());
}

void Sprite::SetTexture(const sf::Texture& texture)
{
	m_spriteTexture = makeUPtr<sf::Sprite>(texture);
}

sf::Sprite* Sprite::GetSprite()
{
	return m_spriteTexture.get();
}
