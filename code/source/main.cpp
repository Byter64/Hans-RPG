#include "Halib/Graphic.h"
#include "Halib/System.h"
#include "Halib/Audio.h"
#include "SplashScreen.h"
#include "PartyCharacter.h"

int main() 
{
	Halib::Init();

	SplashScreen::ShowSplashScreen();

	std::shared_ptr<Halib::Audio> music = Halib::audiosystem.LoadMusic("assets/Audio/gustygardengalaxy.wav", 114.2f);
	Halib::audiosystem.Play(music);

	Halib::Sprite playerSprite = Halib::Sprite("assets/NinjaAdventure/Actor/Characters/NinjaMasked/SpriteSheet.bmp", Halib::VecI2(4, 7));
	playerSprite.SetupAnimation(Halib::VecI2(0, 0), 4, 3, Halib::Sprite::DOWN);
	playerSprite.isPlaying = true;
	std::shared_ptr<PartyCharacter> player = std::make_shared<PartyCharacter>(playerSprite, Halib::VecI2(200, 120));
	Halib::AddEntity(player);


	Halib::rendersystem.backgroundColor = Halib::Color(15, 15, 15);

	//This is your game loop. The program should never leave it.
	while(!Halib::GetShouldClose()) 
	{
		Halib::Update();

		Halib::rendersystem.camera.position = Halib::VecI2(player->GetPosition()) - Halib::GetScreenSize() / 2;
	}

	player->Destroy();

	return 0;
}
