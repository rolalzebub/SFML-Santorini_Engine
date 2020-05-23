#pragma once
#include "Core/Button.h"
class EnterIPButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

