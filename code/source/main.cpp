#include "Halib/Graphic.h"
#include "Halib/System.h"
#include "SplashScreen.h"
#include "PartyCharacter.h"

int main() 
{
	Halib::Init();

	SplashScreen::ShowSplashScreen();

	Halib::Sprite playerSprite = Halib::Sprite("assets/NinjaAdventure/Actor/Characters/NinjaMasked/SpriteSheet.bmp", Halib::VecI2(4, 7));
	playerSprite.SetupAnimation(Halib::VecI2(0, 0), 4, 3, Halib::Sprite::DOWN);
	playerSprite.isPlaying = true;
	PartyCharacter player = PartyCharacter(playerSprite, Halib::VecI2(200, 120));


	Halib::Camera camera = Halib::Camera();

	float timePoint = Halib::GetTimeSinceStartup();
	float newTimePoint = Halib::GetTimeSinceStartup();
	float deltaTime = 1 / 30.0f;

	//This is your game loop. The program should never leave it.
	while(!Halib::GetShouldClose()) 
	{
		Halib::UpdateInputs();
		timePoint = newTimePoint;
		newTimePoint = Halib::GetTimeSinceStartup();
		deltaTime = newTimePoint - timePoint;


		player.Update(deltaTime);

		Halib::Clear(Halib::Color(15, 15, 15));
		
		player.Draw(deltaTime);
		Halib::Show();

		//camera.position += Halib::VecI2(1, 0);
	}
	return 0;
}
