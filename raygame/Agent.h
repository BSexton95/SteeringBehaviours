#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <Vector2.h>
class SteeringComponent;
class moveComponent;

class Agent :
	public Actor
{
public:
	/// <summary>
	/// Constructor for an agent
	/// </summary>
	/// <param name="x">x position</param>
	/// <param name="y">y posoition</param>
	/// <param name="name">Agent name</param>
	/// <param name="target">The actor the agent is seeking or fleeing from</param>
	Agent(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }

	/// <summary>
	/// Deconstructor for an agent
	/// </summary>
	~Agent() {};

	/// <summary>
	/// Seek component and sprite comonent are intialized in the start function
	/// </summary>
	void start() override;

	/// <summary>
	/// Calls the actors start
	/// </summary>
	/// <param name="deltaTime"></param>
	void update(float deltaTime) override;

	void onAddComponent(Component* component) override;
	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float maxForce) { m_maxForce = maxForce; }
	moveComponent* getMoveComponent() { return m_moveComponent; }

	
private:
	DynamicArray<SteeringComponent*> m_steeringComponents;//Remember to change to dynamic array
	float m_maxForce;
	moveComponent* m_moveComponent;
	Actor* m_target;
	MathLibrary::Vector2 m_force;
};

