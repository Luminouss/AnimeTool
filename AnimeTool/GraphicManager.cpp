#include "stdafx.h"
#include "GraphicManager.h"
#include "WindowManager.h"
#include "Surface.h"


GraphicManager::GraphicManager(WindowManager* manager)
{
	winManager = manager;
	surface = NULL;
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
	surface = new Surface();

	if (!surface->setupSurface(winManager->SCREEN_WIDTH, winManager->SCREEN_HEIGHT, winManager->SCREEN_BPP, SDL_SWSURFACE | SDL_NOFRAME))
		return 1;


	//Load Images and Colors
	backgroundColor = SDL_MapRGBA(surface->getSurface()->format, 30, 30, 30, 255);


	//Setup rectangles
	surface->addRect("titlebar", 0, 0, surface->getSurface()->w, 35, 45, 45, 48, 255);
	surface->addRect("exitbutton", winManager->SCREEN_WIDTH - 40,0 , 40, 35, 255, 0, 0, 255);
	
	FillRects();

	return 0;
}

int GraphicManager::Update()
{
	//Update Screen
	if (SDL_Flip(surface->getSurface()) == -1)
		return 1;

	//printf("Updated Screen");
	return 0;
}

void GraphicManager::Shutdown()
{
	backgroundColor = NULL;
	titlebarColor = NULL;
	flags = NULL;

	if (winManager != NULL){
		winManager = NULL;
		delete(winManager);
	}


	surface = NULL;
	delete(surface);

}


int GraphicManager::FillRects()
{
	SDL_FillRect(surface->getSurface(), NULL, backgroundColor);//Background

	std::vector<Rect*> temprects = surface->getRect();
	for (size_t i = 0; i < temprects.size(); i++)
	{
		surface->fillRect(temprects[i]);
	}
	
	return 1;
}

Surface* GraphicManager::getSurface()
{
	return surface;
}