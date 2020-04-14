#pragma once
#include "SFML/Graphics.hpp"
#include "Core/UIObject.h"

class Button :
	public UIObject
{
	sf::Font button_TextFont;
	sf::Text button_Text;
	sf::RectangleShape button_Outline;
	sf::Color button_FillColour;
	
	int Rid_buttonRect;		//Renderer id for button outline
	int Rid_text;			//Renderer id for button text

public:
	void Start() override;
	void Update() override;
	virtual void OnClick() = 0;
	void Stop() override;


	void SetFillColour(sf::Color color) { button_FillColour = color; }
	void setSize(sf::Vector2f size) { button_Outline.setSize(size); }
	void setText(sf::Text text) { button_Text = text; }
	void setText(const std::string& text) { button_Text.setString(text); }

	sf::Vector2f GetExtents() { return button_Outline.getSize(); }
	bool LoadFont(const std::string& path) { return button_TextFont.loadFromFile(path); }
	void SetFontColour(sf::Color color) { button_Text.setFillColor(color); button_Text.setOutlineColor(color); }
	Button();
};

