#pragma once
#include "GameObject.h"
class gameTile :
	public GameObject
{
public:
    bool build();
    unsigned short level = 0;

    void Start() override {};
    void Update() override {};
    void Stop() override {};
    void OnCollisionEnter() override {};
    void OnCollisionStay() override {};
    void OnCollisionExit() override {};
};

