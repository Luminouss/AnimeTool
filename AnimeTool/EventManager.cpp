#include "stdafx.h"
#include "EventManager.h"
#include "WindowManager.h"


EventManager::EventManager(WindowManager* manager)
{
	winManager = manager;

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
				if (e.button.y >= 0 && e.button.y <= 35)
				{
					dragging = true;
				}
			}
		case SDL_MOUSEBUTTONUP:
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				dragging = false;
			}
		case SDL_MOUSEMOTION:
			if (dragging)
			{
				winManager->dragWindow(e.motion.x, e.motion.y);
			}
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