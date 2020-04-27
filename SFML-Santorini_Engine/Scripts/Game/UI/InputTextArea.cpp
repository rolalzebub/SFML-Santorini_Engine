#include "InputTextArea.h"
#include "Managers/UIManager.h"
#include "Managers/InputManager.h"
#include "Core/Engine.h"
void InputTextArea::Start()
{
	AddDrawable(&m_areaText);
	UI_Manager.AddUIObject(this);
}

void InputTextArea::Update()
{
	for (int i = 0; i <= 26; i++) {
		if (Input.isKeyPressed((sf::Keyboard::Key) i)) {
			sf::Event e;
			while (GetEngine.GetRenderWindow()->pollEvent(e))
			{
				if (e.type == sf::Event::EventType::TextEntered)
				{
					m_areaText.setString(m_areaText.getString() + e.text.unicode);
				}
			}
		}
	}

	if (Input.isKeyPressed(sf::Keyboard::Key::Backspace)) {
		m_areaText.setString(m_areaText.getString().substring(0, m_areaText.getString().getSize() - 1));
	}
}
