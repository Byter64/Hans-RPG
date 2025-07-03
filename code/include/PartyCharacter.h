#pragma once
#include "Halib/Graphic.h"
#include "Halib/Math.h"
#include "Halib/Entity.h"

/// @brief A character that is part of your party
class PartyCharacter : public Halib::Entity
{
	static const int ACCELERATION = 12; //Pixels per second²
	static const int MAX_SPEED = 3; //per dimension
	const float DEACCELERATION = 0.85f; 
	
	Halib::Vec2 velocity;

	void UpdatePosition(float deltaTime);
	void UpdateSprite();

public:
	PartyCharacter(Halib::Sprite sprite, Halib::VecI2 position);

	void Update(float deltaTime);
	void Draw(float deltaTime);
	Halib::Sprite& GetSprite();
};