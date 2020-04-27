#pragma once
#include "Core/UIObject.h"
#include "SFML/Graphics/Text.hpp"
class InputTextArea :
	public UIObject
{
	sf::Text m_areaText;
	
public:
	void Start() override;
	void Update() override;
};

