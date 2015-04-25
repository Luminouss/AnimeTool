// AnimeTool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WindowManager.h"
#include "sdl.h"

int main(int argc, char* args[])
{
	WindowManager* winManager = new WindowManager();


	SDL_Quit();
	return 0;
}

