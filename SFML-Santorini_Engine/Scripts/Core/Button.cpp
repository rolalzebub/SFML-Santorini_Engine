#include "Button.h"
#include "Managers/RenderManager.h"
#include "Managers/UIManager.h"

Button::Button() {
	button_Text.setFont(button_TextFont);
	button_Text.setCharacterSize(30);

	AddDrawable(&button_Outline);
	AddDrawable(&button_Text);
}


void Button::Update()
{
	button_Outline.setPosition(getPosition());
	button_Text.setPosition(getPosition());
}

void Button::Stop()
{
}

