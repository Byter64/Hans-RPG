#include <Hall/Hall.h>
#include "Halib/Image.h"
#include "Halib/Misc.h"
#include "SplashScreen.h"

int main() 
{
	Hall::Init();

	SplashScreen::ShowSplashScreen();

	//This is your game loop. The program should never leave it.
	while(!Hall::ShouldClose()) 
	{
		Halib::Misc::ClearFrame(0b0010000100001001);
		
		Halib::Misc::ShowFrame();
	}
	return 0;
}
