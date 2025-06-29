#include "Halib/Graphic.h"
#include "Halib/System.h"
#include "SplashScreen.h"

int main() 
{
	Halib::Init();

	SplashScreen::ShowSplashScreen();

	//This is your game loop. The program should never leave it.
	while(!Halib::GetShouldClose()) 
	{
		Halib::Clear(0b0010000100001001);
		
		Halib::Show();
	}
	return 0;
}
