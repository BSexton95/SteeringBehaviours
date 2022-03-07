#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"

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
