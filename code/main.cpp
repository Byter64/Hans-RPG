#include <Hall/Hall.h>
#include "Halib/Image.h"
#include "Halib/Misc.h"

int main() 
{
	Hall::Init();

	Halib::Image hansLogo = Halib::Image("assets/hans_logo.bmp");
	//This is your game loop. The program should never leave it.
	while(!Hall::ShouldClose()) 
	{
		hansLogo.Draw(Halib::VecI2{40, 40});
		Halib::Misc::ShowFrame();
	}
	return 0;
}
