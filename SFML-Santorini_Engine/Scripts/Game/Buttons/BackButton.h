#pragma once
#include "Core/Button.h"
class BackButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

