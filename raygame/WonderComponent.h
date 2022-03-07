#pragma once
#include "Component.h"
#include "Transform2D.h"
#include <Vector2.h>
class Actor;
class SeekMovement;

class WonderComponent :
	public Component
{
public:
	WonderComponent() {};
	WonderComponent(Actor* target) { m_target = target; }
	MathLibrary::Vector2 calculateForce();
	Actor* getTarget();
	void setTarget(Actor*);
	void start() override;
	void update(float deltaTime) override;
	
	
private:
	Actor* m_target;
	SeekComponent* m_seekComponent;
};

