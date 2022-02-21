#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void SeekComponent::update(float deltaTime)
{
	MathLibrary::Vector2 direction;

	direction = getOwner()->getTransform()->getWorldPosition() - m_target->getTransform()->getWorldPosition();
	direction.normalize();

	MathLibrary::Vector2 desiredVelocity = direction * m_seekForce;

	m_steeringForce = desiredVelocity - getVelocity();

	getVelocity() = getVelocity() + (m_steeringForce * deltaTime);
	getOwner()->getTransform()->getWorldPosition() = getOwner()->getTransform()->getWorldPosition() + (getVelocity() * deltaTime);
}
