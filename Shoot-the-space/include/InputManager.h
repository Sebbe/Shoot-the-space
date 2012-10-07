#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>

class InputManager {

public:
	InputManager();
	bool* GetDownKeys();
	bool IsKeyPressed(SDLKey key);
	bool IsKeyHeld(SDLKey key);
	bool IsKeyReleased(SDLKey key);
	bool IsKeyDown(SDLKey key);
	bool IsKeyUp(SDLKey key);
	bool CloseWindow();
	void Update();
private:
	bool _curKeysHeld[323];
	bool _prevKeysHeld[323];
	SDL_Event _event;
	bool _closeWindow;
};

#endif