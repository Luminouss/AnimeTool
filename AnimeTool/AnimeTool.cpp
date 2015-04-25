// AnimeTool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sdl.h"
#include <string>

//screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//Surfaces
SDL_Surface* screen = NULL;

SDL_Surface* loadImage(std::string filename)
{
	//Temporary storage for the image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the Image
	loadedImage = SDL_LoadBMP(filename.c_str());

	//Nothing went wrong?
	if (loadedImage != NULL)
	{
		//optimize image
		optimizedImage = SDL_DisplayFormat(loadedImage);

		//delete temp image
		SDL_FreeSurface(loadedImage);

	}
	return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface* input, SDL_Surface* output)
{
	//Create temporary rectangle and hold offsets
	SDL_Rect temp_offsets;

	//apply offsets to rectangle
	temp_offsets.x = x;
	temp_offsets.y = y;

	//BLit the Surface
	SDL_BlitSurface(input, NULL, output, &temp_offsets);
}

int main(int argc, char* args[])
{
	SDL_Rect titlebar;

	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return 1;
	}

	//Setup the Screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_NOFRAME);

	//Setup Rectangles
	titlebar.x = titlebar.y = 0;
	titlebar.w = screen->w;
	titlebar.h = 35;

	//Check if screen initialization had errors
	if (screen == NULL)
	{
		return 1;
	}

	//Set Window Properties
	SDL_WM_SetCaption("Hello World", NULL);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 30, 30, 30));
	SDL_FillRect(screen, &titlebar, SDL_MapRGB(screen->format, 45, 45, 48));

	//Load Images


	//Update the screen
	if (SDL_Flip(screen) == -1)
	{
		return 1;
	}

	//Wait 2 seconds
	SDL_Delay(2000);


	//Free the surfaces
	SDL_FreeSurface(screen);

	//Quit SDL
	SDL_Quit();

	//Return
	return 0;
}

