#include "Button.h"
#include "Managers/RenderManager.h"
#include "Managers/UIManager.h"

Button::Button() {
	Rid_buttonRect = -1;
	Rid_text = -1;
}

void Button::Start()
{
	button_Text.setFont(button_TextFont);
	button_Text.setCharacterSize(30);
	Rid_buttonRect = Renderer.AddDrawable(&button_Outline);
	Rid_text = Renderer.AddDrawable(&button_Text);
}

void Button::Update()
{
	button_Outline.setPosition(getPosition());
	button_Text.setPosition(getPosition());
}

void Button::Stop()
{
	Renderer.DeleteDrawable(Rid_text);
	Renderer.DeleteDrawable(Rid_buttonRect);
}

