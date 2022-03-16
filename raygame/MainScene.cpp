#include "MainScene.h"
#include "SpriteComponent.h"
#include "moveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Enemy.h"

void MainScene::start()
{
	//Initialize player
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });
	addActor(player);

	//Initialize enemy
	Enemy* enemy = new Enemy(200, 200, "Enemy", 100, 50, player);
	addActor(enemy);
}
