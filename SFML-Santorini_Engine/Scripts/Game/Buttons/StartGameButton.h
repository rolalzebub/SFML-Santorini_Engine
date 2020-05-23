#pragma once
#include "Core/Button.h"
class StartGameButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

