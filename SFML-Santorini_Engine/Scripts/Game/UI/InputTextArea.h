#pragma once
#include "Core/UIObject.h"
#include "SFML/Graphics/Text.hpp"
class InputTextArea :
	public UIObject
{
	sf::Font textFont;
	uPtr<sf::Text> m_areaText;
	
	sf::Time elapsedTimeSinceInput = sf::Time::Zero;

	sf::Time textInputDelay = sf::seconds(0.3);

	void UpdateText();
public:
	void Start() override;
	void Update() override;
	void ReceiveText(sf::Event& e) override;

	std::string GetString();
};

