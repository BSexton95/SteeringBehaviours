#pragma once
#include "Actor.h"
#include "Component.h"
#include "Vector2.h"

class SeekComponent :
	public Component
{
public:
	SeekComponent(const char* name = "Seek Component") : Component::Component(name) {}
	~SeekComponent() {};

	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
	float getMaxSpeed() { return m_maxSpeed; }
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }
	MathLibrary::Vector2 getSteeringForce() { return m_steeringForce; }
	Actor* getTarget() { return m_target; }
	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_steeringForce;
	float m_maxSpeed;
	Actor* m_target;
	Actor* m_object;
};

