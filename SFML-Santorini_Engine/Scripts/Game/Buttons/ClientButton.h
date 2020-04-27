#pragma once
#include "Core/Button.h"
class ClientButton :
	public Button
{
public:
	void Start() override;
	void OnClick() override;
};

