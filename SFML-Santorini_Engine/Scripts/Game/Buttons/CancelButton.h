#pragma once
#include "Core/Button.h"
class CancelButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

