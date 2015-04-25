#pragma once
#ifndef EventManager_H
#define EventManager_H

#include <SDL.h>

class WindowManager;

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

class EventManager
{
//Functions
public:
	EventManager(WindowManager*);
	~EventManager();

	void handleEvent();
	void Shutdown();
private:
	void InitializeEventManager();

	//Variables
public:
	bool Quit = false;

private:
	SDL_Event e;
	WindowManager* winManager = NULL;
};

#endif