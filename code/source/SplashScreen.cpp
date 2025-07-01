#include "SplashScreen.h"
#include "Halib/Graphic.h"
#include "Halib/Misc.h"
#include "Halib/System.h"
#include <Hall/Hall.h>

static void DarkenColor(Halib::Color& color)
{
	color.SetRed(color.GetRed() / 2);
	color.SetGreen(color.GetGreen() / 2);
	color.SetBlue(color.GetBlue() / 2);
}

static void DarkenImage(Halib::Image& image)
{
	Halib::Color* color = image.GetData();
	for(; color < (image.GetData() + image.GetWidth() * image.GetHeight()); color++)
	{
		DarkenColor(*color);
	}
}

void SplashScreen::ShowSplashScreen()
{
	Halib::Image byterLogo("assets/byterLogo.bmp");
	Halib::Font pixelGameFont("assets/Font/pixel-game/Pixel Game.otf");
	
	float timePoint = Halib::Misc::GetTimeSinceStartup();
	float newTimePoint = Halib::Misc::GetTimeSinceStartup();
	float delta = 1/60.0f;

	float time = 0;
	int darkenCounter = 0;
	Halib::Color textColor{31, 31, 31, true};
	while(!Halib::GetShouldClose()) 
	{ 
		timePoint = newTimePoint;
		newTimePoint = Halib::Misc::GetTimeSinceStartup();
		delta = newTimePoint - timePoint; 
		time += delta;

		//I need a sound here :(
		if(time >= 3)
		{
			time = 2.5f;
			DarkenImage(byterLogo);
			DarkenColor(textColor);
			darkenCounter++;
		}

		Halib::Clear(Halib::Color(0, 0, 0));
		Halib::Draw(byterLogo, Halib::VecI2{150, 40});
		Halib::Draw(std::string("A Byte-Intensive Game"), Halib::VecI2{145, 150}, pixelGameFont, textColor);

		Halib::Show();

		if(darkenCounter == 5)
		{
			break;
		}
	}
}