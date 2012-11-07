#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include <memory>
#include <Windows.h>
#include <gl\GL.h>
#include <list>
#include <SDL.h>
#include "Input/InputManager.h"
#include "Timer.h"
#include "Renderable.h"
#include "Spaceship.h"
#include "Updateable.h"
#include "World.h"
#include "Ship\SimpleEnemy.h"
#include "SpawnManager.h"
#include "Collision\CollisionManager.h"

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

	

	static float ZNEAR;
	static float ZFAR;
	static std::vector<Renderable*> renderList;
	static std::vector<Updateable*> updateList;
	static CollisionManager collisionManager;
	static InputManager inputManager;
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
	static const unsigned int window_width = 800;
	static const unsigned int window_height = 600;

	float deltaTime;
	int fps;
	float fpsTime;
private:
	Timer my_timer; //< Timer for machine independent motion
	float x, y, z;
	float degrees;

	
	Bulletpool bulletpool;
	Spaceship *ship;
	World world;
	SpawnManager spawnManager;
};

#endif // _GAMEMANAGER_H_

