#include "Input/InputManager.h"
#include <SDL.H>

/** initilize the inputmanager */
InputManager::InputManager() {
	_closeWindow = false;
	_resize = false;
	resizeHeight = 0;
	resizeWidth = 0;
	for(int i = 0; i < 323; i++) {
		_curKeysHeld[i] = _prevKeysHeld[i] = false;
	}
}

/**
 * Goes true all the buttons that is pressed and save it to the array
 *
 */
void InputManager::Update() {
	_resize = false;
	for(int i = 0; i < 323; i++) {
		_prevKeysHeld[i] = _curKeysHeld[i];
	}
	while(SDL_PollEvent(&_event)) {
		switch(_event.type) {
			case SDL_QUIT:
				_closeWindow = true;
				break;
			case SDL_KEYDOWN:
				_curKeysHeld[_event.key.keysym.sym] = true;
				break;
			case SDL_KEYUP:
				_curKeysHeld[_event.key.keysym.sym] = false;
				break;
			case SDL_VIDEORESIZE:
				_resize = true;
				resizeWidth = _event.resize.w;
				resizeHeight = _event.resize.h;
				break;
			default:
				break;
		}
	}
}

/** Checks if the button is pressed right now */
bool InputManager::IsKeyDown(SDLKey key) {
	return _curKeysHeld[key];
}

/** Checks i the button is not pressed right now */
bool InputManager::IsKeyUp(SDLKey key) {
	return _curKeysHeld[key];
}

/** Checks if the button is released this frame */
bool InputManager::IsKeyReleased(SDLKey key) {
	if(_prevKeysHeld[key]) {
		if(!_curKeysHeld[key]) {
			return true;
		}
	}
	return false;
}

/**
* return true if the key is hold this and prev frame
*/
bool InputManager::IsKeyHeld(SDLKey key) {
	return _prevKeysHeld[key] && _curKeysHeld[key];
}

/**
* return true if the key is hold this and only this frame
*/
bool InputManager::IsKeyPressed(SDLKey key) {
	if(_curKeysHeld[key]) {
		if(!_prevKeysHeld[key]) {
			return true;
		}
	}
	return false;
}

/** Return array with which keys is held */
bool* InputManager::GetDownKeys() {
	return _curKeysHeld;
}

/** Return true if the window should close (escape or close button pressed */
bool InputManager::CloseWindow() {
	if(IsKeyDown(SDLK_ESCAPE)) return true;
	return _closeWindow;
}

/** Returns true if window is resized */
bool InputManager::Resize() {
	return _resize;
}