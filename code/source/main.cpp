#include "Halib/Graphic.h"
#include "Halib/System.h"
#include "Halib/Audio.h"
#include "SplashScreen.h"
#include "PartyCharacter.h"
#include <vector>

int main() 
{
	Halib::Init();

	//SplashScreen::ShowSplashScreen();

	//std::shared_ptr<Halib::Audio> music1 = Halib::audiosystem.LoadMusic("assets/Audio/gustygardengalaxy.wav", 60);
	std::shared_ptr<Halib::Audio> music1 = Halib::audiosystem.LoadMusic("assets/Audio/T1.wav", 60);
	std::shared_ptr<Halib::Audio> music2 = Halib::audiosystem.LoadMusic("assets/Audio/T2.wav", 60);
	std::shared_ptr<Halib::Audio> music3 = Halib::audiosystem.LoadMusic("assets/Audio/T3.wav", 60);
	std::shared_ptr<Halib::Audio> music4 = Halib::audiosystem.LoadMusic("assets/Audio/T4.wav", 60);
	std::shared_ptr<Halib::Audio> music5 = Halib::audiosystem.LoadMusic("assets/Audio/T5.wav", 60);
	Halib::audiosystem.Play(music1);
	Halib::audiosystem.Play(music2);
	Halib::audiosystem.Play(music3);
	Halib::audiosystem.Play(music4);
	Halib::audiosystem.Play(music5);

	auto sound1 = Halib::audiosystem.LoudSound("assets/Audio/beep.wav");
	auto sound2 = Halib::audiosystem.LoudSound("assets/Audio/drum.wav");
	auto sound3 = Halib::audiosystem.LoudSound("assets/Audio/slum.wav");
	auto sound4 = Halib::audiosystem.LoudSound("assets/Audio/wow.wav");
	std::vector<std::shared_ptr<Halib::Audio>> sounds;
	sounds.push_back(sound1);
	sounds.push_back(sound2);
	sounds.push_back(sound3);
	sounds.push_back(sound4);

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

		int index = rand() % 4;
		Halib::audiosystem.Play(sounds[index]);
		//Halib::rendersystem.camera.position = Halib::VecI2(player->GetPosition()) - Halib::GetScreenSize() / 2;
	}

	player->Destroy();

	return 0;
}
