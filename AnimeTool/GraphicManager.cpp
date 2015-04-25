#include "stdafx.h"
#include "GraphicManager.h"
#include "WindowManager.h"


GraphicManager::GraphicManager(WindowManager* manager)
{
	winManager = manager;
	screen = NULL;

	InitializeGraphics();
}


GraphicManager::~GraphicManager()
{
}

SDL_Surface* GraphicManager::loadImage(std::string filename)
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

void GraphicManager::applySurface(int x, int y, SDL_Surface* input, SDL_Surface* output)
{
	//Create temporary rectangle and hold offsets
	SDL_Rect temp_offsets;

	//apply offsets to rectangle
	temp_offsets.x = x;
	temp_offsets.y = y;

	//BLit the Surface
	SDL_BlitSurface(input, NULL, output, &temp_offsets);
}

int GraphicManager::InitializeGraphics()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return 1;

	//Setup the Screen
	screen = SDL_SetVideoMode(winManager->SCREEN_WIDTH, winManager->SCREEN_HEIGHT, winManager->SCREEN_BPP, SDL_SWSURFACE | SDL_NOFRAME);

	//Check if screen had errors in the initialization
	if (screen == NULL)
		return 1;


	//Load Images and Colors
	backgroundColor = SDL_MapRGBA(screen->format, 30, 30, 30, 255);
	titlebarColor = SDL_MapRGBA(screen->format, 45, 45, 48, 255);

	//setup rectangles
	titlebar.x = titlebar.y = 0;
	titlebar.w = screen->w;
	titlebar.h = 35;

	//Set Window Properties
	SDL_FillRect(screen, NULL, backgroundColor);//Background
	SDL_FillRect(screen, &titlebar, titlebarColor);//Titlebar


	//Update Screen
	if (SDL_Flip(screen) == -1)
		return 1;

	SDL_Delay(2500);

	//End programm
	SDL_FreeSurface(screen);

	return 0;
}