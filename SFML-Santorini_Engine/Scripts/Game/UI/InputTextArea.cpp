#include "InputTextArea.h"
#include "Managers/InputManager.h"
#include "Core/Engine.h"
void InputTextArea::UpdateText()
{
	if(textReceivedEvent->text.unicode != '\b')
		m_areaText->setString(m_areaText->getString() + textReceivedEvent->text.unicode);
	else {
		m_areaText->setString(m_areaText->getString().substring(0, m_areaText->getString().getSize() - 1));
	}
}
void InputTextArea::Start()
{
	textFont.loadFromFile("Data/Fonts/MontereyFLF.ttf");
	SetTextReceivable(true);
	m_areaText = makeUPtr<sf::Text>();
	m_areaText->setFont(textFont);
	m_areaText->setString("");
	AddDrawable(m_areaText.get());
}

void InputTextArea::Update()
{
	m_areaText->setPosition(getPosition());

}

void InputTextArea::ReceiveText(sf::Event& e)
{
	textReceivedEvent = &e;
	UpdateText();
}

std::string InputTextArea::GetString()
{
	return m_areaText->getString();
}
