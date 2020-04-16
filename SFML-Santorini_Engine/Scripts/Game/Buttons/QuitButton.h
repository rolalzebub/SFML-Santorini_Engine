#pragma once
#include "Core/Button.h"
class QuitButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

