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

	

	Halib::rendersystem.backgroundColor = Halib::Color(15, 15, 15);

	//This is your game loop. The program should never leave it.
	while(!Halib::GetShouldClose()) 
	{
		Halib::Update();

		Halib::rendersystem.camera.position += Halib::VecI2(1, 0);
	}
	return 0;
}
