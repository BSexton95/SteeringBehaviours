#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void SeekComponent::update(float deltaTime)
{
	MathLibrary::Vector2 direction;
	direction = getTarget()->getTransform()->getWorldPosition() - m_object->getTransform()->getWorldPosition();
	direction = direction.normalize() * getMaxSpeed();
	MathLibrary::Vector2 steeringForce = direction - getVelocity();
	getVelocity() = getVelocity() + (steeringForce * deltaTime);
	m_object->getTransform()->getWorldPosition() = m_object->getTransform()->getWorldPosition() + (getVelocity() * deltaTime);
}
