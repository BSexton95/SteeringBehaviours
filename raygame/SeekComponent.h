#pragma once
#include "SteeringComponent.h"
class Actor;

class SeekComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

