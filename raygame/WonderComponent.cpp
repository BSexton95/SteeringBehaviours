#include "WonderComponent.h"
#include "Transform2D.h"
#include <Vector2.h>
#include "Actor.h"
#include <cstdlib>
#include <time.h>
#include "SeekComponent.h"

void WonderComponent::start()
{
	
}

void WonderComponent::update(float deltaTime)
{
	float distance = 5;

	MathLibrary::Vector2 circleDistance = (getOwner()->getTransform()->getForward().normalize() * distance) + m_target->getTransform()->getWorldPosition();

	float randNum = rand() % 100 + 1;
	srand(time(NULL));

	MathLibrary::Vector2 randPos = { (float)cos(randNum), (float)sin(randNum) };
	MathLibrary::Vector2 scaledRandPos = randPos * 8;
	m_seekComponent->m_randPoint = circleDistance + scaledRandPos;
	
	


}
