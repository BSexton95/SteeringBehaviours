#pragma once
#include "Actor.h"
#include "Component.h"
#include <Vector2.h>

class SeekComponent :
	public Component
{
public:
	/// <summary>
	/// Constructor for the seek component
	/// </summary>
	/// <param name="target">The actor to seek</param>
	/// <param name="name"></param>
	SeekComponent(Actor* target) { m_target = target; }
	SeekComponent(MathLibrary::Vector2 randPoint) { m_randPoint = randPoint; };
	/// <summary>
	/// Deconsructor for the seek component
	/// </summary>
	~SeekComponent() {};


	/// <returns>The actors velocity</returns>
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	/// <summary>
	/// Sets the acotrs veleocity
	/// </summary>
	/// <param name="velocity">The desired veleocity for the actor</param>
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }


	/// <returns>The steering force calculated</returns>
	MathLibrary::Vector2 getSteeringForce() { return m_steeringForce; }

	/// <returns>The actor to seek</returns>
	Actor* getTarget() { return m_target; }

	/// <summary>
	/// 
	/// </summary>
	/// <param name="deltaTime"></param>
	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_steeringForce;
	float m_seekForce = 3;
	Actor* m_target;
	MathLibrary::Vector2 m_randPoint;
};

