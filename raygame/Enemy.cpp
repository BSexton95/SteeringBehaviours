#include "Enemy.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "SpriteComponent.h"
#include "AggressiveDecision.h"
#include "SeekDecision.h"
#include "IdleDecision.h"
#include "WanderDecision.h"
#include "InRangeDecision.h"
#include "DecisionComponent.h"
#include "Decision.h"

Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Agent(x, y, name, maxForce, maxSpeed)
{
	m_target = target;
}

void Enemy::start()
{
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	AggressiveDecision* aggressive = new AggressiveDecision(idle, wander);
	InRangeDecision* inRange = new InRangeDecision(aggressive, seek);

	addComponent(new DecisionComponent(inRange));

	//Add sprite component
	addComponent(new SpriteComponent("Images/enemy.png"));
	getTransform()->setScale({ 50, 50 });

	//Initialize and add wander component
	WanderComponent* wanderComponent = new WanderComponent(100, 20, 200);
	addComponent(wanderComponent);

	//Initialize and add seek component
	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(50);
	seekComponent->setTarget(m_target);
	setMaxForce(500);
	addComponent(seekComponent);
}

bool Enemy::getTargetInRange()
{
	float distance = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	MathLibrary::Vector2 direction = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized();

	return distance <= 100 && acos(MathLibrary::Vector2::dotProduct(direction, getTransform()->getForward())) < 1;
}
