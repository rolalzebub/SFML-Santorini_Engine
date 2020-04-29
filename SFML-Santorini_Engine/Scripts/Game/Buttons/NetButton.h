#pragma once
#include "Core/Button.h"
class NetButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

