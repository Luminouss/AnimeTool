#include "stdafx.h"
#include "EventManager.h"
#include "WindowManager.h"
#include "GraphicManager.h"

#include <iostream>



EventManager::EventManager(WindowManager* manager, GraphicManager* graphics)
{
	winManager = manager;
	gManager = graphics;
	InitializeEventManager();
}


EventManager::~EventManager()
{
}

void EventManager::InitializeEventManager()
{

}

void EventManager::handleEvent()
{
	while (SDL_PollEvent(&e) != 0)
	{ // HANDLE EVENTS

		switch (e.type)
		{
			//IF EVENT IS == KEYPRESSED
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE: // IF ESCAPE PRESSED
				Quit = true;
				break;

			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				int x = e.button.x;
				int y = e.button.y;
				Surface* surface = gManager->getSurface();

				if (surface->collideMR(x, y, surface->getRectName("titlebar")))
				{
					if (surface->collideMR(x, y, surface->getRectName("exitbutton")))
					{
						Quit = true;
						break;
					}

					if (!dragging)
					{
						dragging = true;
						winManager->saveOldMousePositionsWindow();
						printf("start dragging the window\n");
					}
				}
				//if (e.button.y >= 0 && e.button.y <= 35)
				//{
				//}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				if (dragging)
				{
					dragging = false;
					printf("stopped dragging the window\n");
				}
			}
			break;
		//case ANYTHING ELSE
		}
	}
}

void EventManager::Shutdown()
{
	if (winManager != NULL){
		winManager = NULL;
		delete(winManager);
	}

}