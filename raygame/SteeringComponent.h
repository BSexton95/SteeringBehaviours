#pragma once
#include "SteeringComponent.h"
#include "Actor.h"
#include <Vector2.h>
class Agent;


class SteeringComponent :
	public Component
{
public:
	SteeringComponent() { m_target = nullptr; m_steeringForce = 0; }
	SteeringComponent(Actor* actor, float steeringForce) { m_target = actor; m_steeringForce = steeringForce; }
	
	virtual MathLibrary::Vector2 calculateForce() = 0;
	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }
	float getSteeringForce() { return m_steeringForce; }
	void setSteeringForce(float steeringForce) { m_steeringForce = steeringForce; }

	Agent* getAgent() { return (Agent*)getOwner(); }
private:
	float m_steeringForce;
	Actor* m_target = nullptr;
};

