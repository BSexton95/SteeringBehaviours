#include "Agent.h"
#include "SeekComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"

void Agent::start()
{
	//Base Actor start
	Actor::start();
	//Adds the seek component
	m_seekComponent = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent()));
	m_seekComponent->setVelocity({ 50, 50 });
	m_sprite = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));

}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);
	
	
	MathLibrary::Vector2 position = getTransform()->getWorldPosition();
	MathLibrary::Vector2 velocity = getTransform()->getForward() + (m_seekComponent->getSteeringForce() * deltaTime);
	position = position + (velocity * deltaTime);
	MathLibrary::Vector2 heading = velocity.normalize();
	
	
}

void Agent::draw()
{
	Actor::draw();
}
