#pragma once
#include "Halib/Graphic.h"
#include "Halib/Math.h"

/// @brief A character that is part of your party
class PartyCharacter
{
	static const int ACCELERATION = 12; //Pixels per second²
	static const int MAX_SPEED = 3; //per dimension
	const float DEACCELERATION = 0.85f; 

	Halib::Sprite sprite;
	
	Halib::Vec2 velocity;
	Halib::Vec2 position;

	void UpdatePosition(float deltaTime);
	void UpdateSprite();

public:
	PartyCharacter(Halib::Sprite sprite, Halib::VecI2 position);

	void Update(float deltaTime);
	void Draw(float deltaTime);
	Halib::Sprite& GetSprite();
};