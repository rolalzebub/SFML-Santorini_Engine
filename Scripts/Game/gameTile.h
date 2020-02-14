#pragma once
#include "GameObject.h"
class gameTile :
	public GameObject
{
public:
    bool build();
    unsigned short level = 0;
};

