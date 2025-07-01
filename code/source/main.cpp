#include "Halib/Graphic.h"
#include "Halib/System.h"
#include "SplashScreen.h"

int main() 
{
	Halib::Init();

	SplashScreen::ShowSplashScreen();

	Halib::Sprite player1 = Halib::Sprite("assets/NinjaAdventure/Actor/Characters/NinjaMasked/SpriteSheet.bmp", Halib::VecI2(4, 7));
	player1.SetupAnimation(Halib::VecI2(0, 0), 4, 1, Halib::Sprite::DOWN);
	player1.isPlaying = true;

	Halib::Sprite player2 = player1;
	player2.SetupAnimation(Halib::VecI2(1, 0), 4, 5, Halib::Sprite::DOWN);

	Halib::Sprite player3 = player1;
	player3.SetupAnimation(Halib::VecI2(2, 0), 4, 2, Halib::Sprite::DOWN);

	Halib::Sprite player4 = player1;
	player4.SetupAnimation(Halib::VecI2(3, 0), 4, 20, Halib::Sprite::DOWN);
	player4.scale = Halib::VecI2(2, 5);

	Halib::Camera camera = Halib::Camera();

	float timePoint = Halib::GetTimeSinceStartup();
	float newTimePoint = Halib::GetTimeSinceStartup();
	float deltaTime = 1 / 30.0f;

	//This is your game loop. The program should never leave it.
	while(!Halib::GetShouldClose()) 
	{
		timePoint = newTimePoint;
		newTimePoint = Halib::GetTimeSinceStartup();
		deltaTime = newTimePoint - timePoint;

		Halib::Clear(Halib::Color(15, 15, 15));
		
		player1.Draw(Halib::VecI2(10, 10), deltaTime, camera);
		player2.Draw(Halib::VecI2(40, 10), deltaTime, camera);
		player3.Draw(Halib::VecI2(80, 10), deltaTime, camera);
		player4.Draw(Halib::VecI2(120, 10), deltaTime, camera);
		Halib::Show();

		camera.position += Halib::VecI2(1, 0);
	}
	return 0;
}
