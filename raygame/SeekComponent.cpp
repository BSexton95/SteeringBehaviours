#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "moveComponent.h"
#include "Agent.h"

MathLibrary::Vector2 SeekComponent::calculateForce()
{
	if (!getTarget())
		return { 0, 0 };
	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition() 
		- getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return seekForce;
}

void SeekComponent::update(float deltaTime)
{
	//Create a vector 2 called desired velocity
	MathLibrary::Vector2 desiredVelocity;

	//Set desired velocity to be the difference between the targets world posotin 
	//and the owners world position multiplied by a float calls seek force.
	desiredVelocity = (m_target->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()) * m_seekForce;

	//Collect 
	m_steeringForce = desiredVelocity - getVelocity();

	//setVelocity(getVelocity() + (m_steeringForce * deltaTime));
	/*setVelocity(m_velocity + (m_steeringForce * deltaTime));
	getOwner()->getTransform()->setLocalPosition(getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime);
	getOwner()->getTransform()->setForward(getVelocity().normalize());*/
}
