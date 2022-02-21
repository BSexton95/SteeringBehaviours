#pragma once
#include "Actor.h"
class SeekComponent;
class SpriteComponent;
class moveComponent;

class Agent :
	public Actor
{
public:
	Agent(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }

	~Agent() {};

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	
private:
	moveComponent* m_moveComponent;
	SeekComponent* m_seekComponent;
	SpriteComponent* m_sprite;
	Actor* m_target;
};

