#include "MainScene.h"
#include "SpriteComponent.h"
#include "moveComponent.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "StateMachineComponent.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	addActor(player);

	Agent* agent = new Agent(50, 50, "Agent", player);
	agent->getTransform()->setScale({ 50, 50 });

	addActor(agent);
	/*
	Agent* agent2 = new Agent(100, 100, "Agent", player);
	agent2->getTransform()->setScale({ 50, 50 });*/
	

	/*addActor(agent2);*/

	SpriteComponent* spriteComponent = new SpriteComponent("Images/enemy.png");
	agent->addComponent(spriteComponent);

	WanderComponent* wanderComponent = new WanderComponent(100, 20, 200);
	agent->addComponent(wanderComponent);

	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(50);
	seekComponent->setTarget(player);
	agent->setMaxForce(500);
	agent->addComponent(seekComponent);

	agent->addComponent<StateMachineComponent>();
	
}
