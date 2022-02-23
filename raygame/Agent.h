#pragma once
#include "Actor.h"
#include <Vector2.h>
class SeekComponent;
class SpriteComponent;

class Agent :
	public Actor
{
public:
	/// <summary>
	/// Constructor for an agent
	/// </summary>
	/// <param name="x">x position</param>
	/// <param name="y">y posoition</param>
	/// <param name="name">Agent name</param>
	/// <param name="target">The actor the agent is seeking or fleeing from</param>
	Agent(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }

	/// <summary>
	/// Deconstructor for an agent
	/// </summary>
	~Agent() {};

	/// <summary>
	/// Seek component and sprite comonent are intialized in the start function
	/// </summary>
	void start() override;

	/// <summary>
	/// Calls the actors start
	/// </summary>
	/// <param name="deltaTime"></param>
	void update(float deltaTime) override;

	/// <summary>
	/// Draws the sprite for an agent
	/// </summary>
	void draw() override;
	
private:
	SeekComponent* m_seekComponent;
	SpriteComponent* m_sprite;
	Actor* m_target;
};

