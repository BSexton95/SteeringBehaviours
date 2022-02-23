#pragma once
#include "Component.h"
#include <Vector2.h>

class FleeComponent :
	public Component
{
public:
	FleeComponent(Actor* target) { m_target = target; }

	~FleeComponent() {};

	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

	MathLibrary::Vector2 getSteeringForce() { return m_steeringForce; }

	Actor* getTarget() { return m_target; }

	void update(float deltaTime) override;
private:
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_steeringForce;
	float m_fleeForce = 5;
	Actor* m_target;
};

