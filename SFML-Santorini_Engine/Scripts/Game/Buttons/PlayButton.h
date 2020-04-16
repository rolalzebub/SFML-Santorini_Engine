#pragma once
#include "Core/Button.h"
class PlayButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

