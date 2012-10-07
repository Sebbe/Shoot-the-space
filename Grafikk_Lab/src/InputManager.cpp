#include "InputManager.h"
#include <SDL.H>

InputManager::InputManager() {
	_closeWindow = false;
	_resize = false;
	resizeHeight = 0;
	resizeWidth = 0;
	for(int i = 0; i < 323; i++) {
		_curKeysHeld[i] = _prevKeysHeld[i] = false;
	}
}

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

bool InputManager::IsKeyDown(SDLKey key) {
	return _curKeysHeld[key];
}

bool InputManager::IsKeyUp(SDLKey key) {
	return _curKeysHeld[key];
}

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

bool* InputManager::GetDownKeys() {
	return _curKeysHeld;
}

bool InputManager::CloseWindow() {
	return _closeWindow;
}

bool InputManager::Resize() {
	return _resize;
}