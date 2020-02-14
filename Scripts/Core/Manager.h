#pragma once
#include "utility_headers.h"
class Manager
{

public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Stop() = 0;

};

