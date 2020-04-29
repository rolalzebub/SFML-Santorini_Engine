#pragma once
#include "Core/Button.h"
class LANButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

