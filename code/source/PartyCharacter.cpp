#include "PartyCharacter.h"
#include "Halib/System.h"

void PartyCharacter::UpdatePosition(float deltaTime)
{
	Halib::Vec2 dpadInput(0, 0);
	dpadInput.y -= Halib::GetButtonDown(0, Halib::UP);
	dpadInput.y += Halib::GetButtonDown(0, Halib::DOWN);
	dpadInput.x -= Halib::GetButtonDown(0, Halib::LEFT);
	dpadInput.x += Halib::GetButtonDown(0, Halib::RIGHT);

	dpadInput *= ACCELERATION * deltaTime;

	velocity += dpadInput;
	velocity.x = velocity.x > MAX_SPEED ? MAX_SPEED : velocity.x;
	velocity.x = velocity.x < -MAX_SPEED ? -MAX_SPEED : velocity.x;
	velocity.y = velocity.y > MAX_SPEED ? MAX_SPEED : velocity.y;
	velocity.y = velocity.y < -MAX_SPEED ? -MAX_SPEED : velocity.y;

	if (dpadInput.x == 0)
		velocity.x *= DEACCELERATION;
	if (dpadInput.y == 0)
		velocity.y *= DEACCELERATION;

	AddPosition(Halib::Vec3(velocity, 0));
}

void PartyCharacter::UpdateSprite()
{
	if (::abs(velocity.x) > ::abs(velocity.y))
	{
		if (velocity.x > 0)
			sprite.animationStartIndex.x = 3;
		else
			sprite.animationStartIndex.x = 2;
	}
	else
	{
		if (velocity.y > 0)
			sprite.animationStartIndex.x = 0;
		else
			sprite.animationStartIndex.x = 1;
	}
	sprite.frameIndex.x = sprite.animationStartIndex.x;
	sprite.framesPerSecond = Halib::Magnitude(velocity) * 3;
}

PartyCharacter::PartyCharacter(Halib::Sprite sprite, Halib::VecI2 position) : Entity(sprite, Halib::Vec3(position, 0)), velocity(Halib::Vec2(0, 0))
{

}

void PartyCharacter::Update(float deltaTime)
{
	
	UpdatePosition(deltaTime);
	UpdateSprite();
}

void PartyCharacter::Draw(float deltaTime)
{
	Halib::VecI2 intPos = GetPosition();
	sprite.Draw(intPos, deltaTime);
}

Halib::Sprite& PartyCharacter::GetSprite()
{
	return sprite;
}