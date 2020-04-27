#pragma once
#include "Core/Button.h"
class ConnectButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

