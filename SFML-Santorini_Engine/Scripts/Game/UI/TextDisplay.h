#pragma once
#include "Core/UIObject.h"
class TextDisplay :
	public UIObject
{

	sf::Font m_textFont;
	uPtr<sf::Text> m_text;


public:
	TextDisplay();
	~TextDisplay() = default;
	void Start() override;
	void Update() override;
	void SetText(const std::string& text);
	void LoadFont(const std::string& path);
	std::string GetText();
};

