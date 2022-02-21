#include "MainScene.h"
#include "SpriteComponent.h"
#include "moveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	addActor(player);

	Agent* agent = new Agent(50, 50, "Agent", player);
	agent->getTransform()->setScale({ 50, 50 });

	addActor(agent);
}
