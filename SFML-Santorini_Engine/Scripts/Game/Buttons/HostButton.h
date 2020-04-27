#pragma once
#include "Core/Button.h"
class HostButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

