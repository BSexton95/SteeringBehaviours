#include "Agent.h"
#include "SeekComponent.h"
#include "moveComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "moveComponent.h"

void Agent::start()
{
	//Base Actor start
	Actor::start();
	

	//Base Actor start
	Actor::start();

	//Adds the seek component
	m_seekComponent = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent(m_target)));
	m_seekComponent->setVelocity({ 50, 50 });

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
