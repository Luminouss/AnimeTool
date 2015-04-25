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