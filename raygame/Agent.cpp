#include "Agent.h"
#include "SeekComponent.h"
#include "SpriteComponent.h"
#include "moveComponent.h"

void Agent::start()
{
	Actor::start();
	m_seekComponent = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent()));
	m_seekComponent->setMaxSpeed(10);
	m_seekComponent->setVelocity({ 10, 10 });
	m_moveComponent = dynamic_cast<moveComponent*>(addComponent(new moveComponent()));
	m_sprite = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));

}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);

	m_seekComponent->getVelocity() = m_seekComponent->getVelocity() + (m_seekComponent->getSteeringForce() * deltaTime);
}

void Agent::draw()
{
	Actor::draw();
}
