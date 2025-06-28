#include "SplashScreen.h"
#include "Halib/Image.h"
#include "Halib/Misc.h"

static void DarkenImage(Halib::Image& image)
{
	Hall::Color* color = image.GetData();
	for(; color < (image.GetData() + image.GetWidth() * image.GetHeight()); color++)
	{
		*color = (*color >> 1) | (*color & 1);
	}
}

void SplashScreen::ShowSplashScreen()
{
	Halib::Image hansLogo("assets/hans_logo.bmp");
	
	float timePoint = Halib::Misc::GetTimeSinceStartup();
	float newTimePoint = Halib::Misc::GetTimeSinceStartup();
	float delta = 1/60.0f;

	float time = 0;
	while(!Hall::ShouldClose()) 
	{ 
		timePoint = newTimePoint;
		newTimePoint = Halib::Misc::GetTimeSinceStartup();
		delta = newTimePoint - timePoint; 
		time += delta;
		printf("%f\n", time);

		if(time >= 1)
		{
			time = 0;
			DarkenImage(hansLogo);
		}

		Halib::Misc::ClearFrame(0b0010000100001001);
		hansLogo.Draw(Halib::VecI2{40, 40});
		Halib::Misc::ShowFrame();
	}
}