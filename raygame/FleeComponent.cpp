#include "FleeComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void FleeComponent::update(float deltaTime)
{
	MathLibrary::Vector2 desiredVelocity;

	desiredVelocity = (getOwner()->getTransform()->getWorldPosition() - m_target->getTransform()->getWorldPosition()) * m_fleeForce;

	m_steeringForce = desiredVelocity - getVelocity();

	setVelocity(m_velocity + (m_steeringForce * deltaTime));
	/*getOwner()->getTransform()->setLocalPosition(getOwner()->getTransform()->getLocalPosition() + (getVelocity() * deltaTime));
	getOwner()->getTransform()->setForward(getVelocity().normalize());*/
}
