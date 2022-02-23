#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void SeekComponent::update(float deltaTime)
{
	MathLibrary::Vector2 desiredVelocity;
	
	desiredVelocity = (m_target->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()) * m_seekForce;
	m_steeringForce = desiredVelocity - getVelocity();

	setVelocity(m_velocity + (m_steeringForce * deltaTime));
	getOwner()->getTransform()->setLocalPosition(getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime);
	getOwner()->getTransform()->setForward(getVelocity().normalize());
}
