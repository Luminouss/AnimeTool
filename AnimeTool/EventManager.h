#pragma once
#ifndef EventManager_H
#define EventManager_H

#include <SDL.h>

class WindowManager;
class GraphicManager;

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
	EventManager(WindowManager*, GraphicManager*);
	~EventManager();

	void handleEvent();
	void Shutdown();
private:
	void InitializeEventManager();

	//Variables
public:
	bool Quit = false;
	bool dragging = false;

private:
	SDL_Event e;
	WindowManager* winManager = NULL;
	GraphicManager* gManager = NULL;
};

#endif