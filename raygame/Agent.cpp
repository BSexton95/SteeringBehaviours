#include "Agent.h"
#include "SeekComponent.h"
#include "moveComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "FleeComponent.h"
#include "WonderComponent.h"

void Agent::start()
{
	//Base Actor start
	Actor::start();
	

	//Base Actor start
	Actor::start();

	m_moveComponent = dynamic_cast<moveComponent*>(addComponent(new moveComponent()));
	m_moveComponent->setMaxSpeed(50);
	m_moveComponent->setVelocity({ 50, 50 });
	//Adds the seek component
	//m_seekComponent = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent(m_target)));
	//m_seekComponent->setVelocity({ 50, 50 });
	m_wonderComponent = dynamic_cast<WonderComponent*>(addComponent(new WonderComponent()));
	//m_fleeComponent = dynamic_cast<FleeComponent*>(addComponent(new FleeComponent(m_target)));
	//m_fleeComponent->setVelocity({ 10, 10 });

	//Add sprite component
	m_sprite = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);
	
}

void Agent::draw()
{
	Actor::draw();
}
