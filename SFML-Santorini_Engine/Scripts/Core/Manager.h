#pragma once
#include "utility_headers.h"
class Manager
{

public:
	virtual void Start() = 0;
	virtual void Update() {};
	virtual void FixedUpdate() {};
	virtual void Stop() = 0;

};

