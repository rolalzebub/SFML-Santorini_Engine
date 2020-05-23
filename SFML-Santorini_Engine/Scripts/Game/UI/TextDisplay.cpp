#include "Game/UI/TextDisplay.h"

TextDisplay::TextDisplay()
{
	m_text = makeUPtr<sf::Text>();
}

void TextDisplay::Start()
{

	m_textFont.loadFromFile("Data/Fonts/MontereyFLF.ttf");
	m_text->setFont(m_textFont);
	AddDrawable(m_text.get());
}

void TextDisplay::Update()
{
	m_text->setPosition(getPosition());
}

void TextDisplay::SetText(const std::string& text)
{
	m_text->setString(text);
}

void TextDisplay::LoadFont(const std::string& path)
{
	m_textFont.loadFromFile(path);
	m_text->setFont(m_textFont);
}

std::string TextDisplay::GetText()
{
	return m_text->getString();
}
