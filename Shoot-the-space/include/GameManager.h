#ifndef _GAMEMANAGER_H_

#define _GAMEMANAGER_H_



#include <memory>

#include <list>

#include <SDL.h>

#include "InputManager.h"

#include "Timer.h"

#include "Renderable.h"

#include "Spaceship.h"
#include "Updateable.h"

/**

 * This class handles the game logic and display.

 * Uses SDL as the display manager, and glm for 

 * vector and matrix computations

 */

class GameManager {

public:

	/**
	 * Constructor
	 */
	GameManager();

	/**
	 * Destructor
	 */
	~GameManager();

	/**
	 * Initializes the game, including the OpenGL context
	 * and data required
	 */

	void init();

	/**
	 * The main loop of the game. Runs the SDL main loop
	 */
	void play();

	/**
	 * Quit function
	 */

	void quit();

	/**
	 * Function that handles rendering into the OpenGL context
	 */

	void render();

	void Update();

	/**
	  * Function that is called when the window is resized
	  */

	void resize(unsigned int width, unsigned int height);

	InputManager inputManager;

	static std::vector<Renderable*> renderList;
	static std::vector<Updateable*> updateList;
protected:

	/**
	 * Creates the OpenGL context using SDL
	 */

	void createOpenGLContext();

	/**
	 * Sets states for OpenGL that we want to keep persistent
	 * throughout the game
	 */
	void setOpenGLStates();
	static const unsigned int window_width = 1024;
	static const unsigned int window_height = 800;

	float deltaTime;
	int fps;
	float fpsTime;
private:
	Timer my_timer; //< Timer for machine independent motion
};

#endif // _GAMEMANAGER_H_

