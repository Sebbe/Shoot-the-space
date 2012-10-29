#include "GameManager.h"
#include "GLUtils/GLUtils.hpp"
#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <assert.h>
#include <stdexcept>
#include "input/InputManager.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "Bulletpool.h"
#include "World.h"
#include "Utils/Vector3D.h"

using std::cerr;
using std::endl;
using GLUtils::checkGLErrors;

std::vector<Renderable*> GameManager::renderList;
std::vector<Updateable*> GameManager::updateList;

float GameManager::ZFAR = 50.0f;
float GameManager::ZNEAR = 0.1f;

GameManager::GameManager() {
	my_timer.restart();
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	degrees = 0.0f;
	
	fps = 0;
	fpsTime = 0;
	srand(static_cast<unsigned int>(time( NULL )) );

	ship = new Spaceship(&inputManager, &bulletpool);
	GameManager::renderList.push_back(ship);
	spawnManager.SetMaxEnemies(30);
	spawnManager.Init();
}

GameManager::~GameManager() {

}

void GameManager::createOpenGLContext() {
	// Set OpenGL attributes
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Use double buffering
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16); // Use framebuffer with 16 bit depth buffer
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8); // Use framebuffer with 8 bit for red
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8); // Use framebuffer with 8 bit for green
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8); // Use framebuffer with 8 bit for blue
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); // Use framebuffer with 8 bit for alpha
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1); 
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4); 


	SDL_WM_SetCaption("NITH - PG430 Space Invaders", "");

	// Initalize video
	if (SDL_SetVideoMode(window_width, window_height, 0, SDL_OPENGL
			| SDL_DOUBLEBUF | SDL_RESIZABLE) == NULL) {
		std::stringstream err;
		err << "SDL_SetVideoMode failed ";
		throw std::runtime_error(err.str());
	}
}

void GameManager::resize(unsigned int width, unsigned int height) {
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(50, width/height, ZNEAR, ZFAR);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0f, 0.0f, -5.0f);
}

void GameManager::setOpenGLStates() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	//Enable culling of back/front-faces
	glEnable(GL_CULL_FACE);

	//Enable blending, and set the blend function
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Set anti-aliasing hints
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	resize(window_width, window_height);
}

void GameManager::init() {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::stringstream err;
		err << "Could not initialize SDL: " << SDL_GetError();
		throw std::runtime_error(err.str());
	}
	atexit( SDL_Quit);

	createOpenGLContext();
	setOpenGLStates();

	//Finally check for errors
	checkGLErrors();

	world.Init();
}

void GameManager::render() {
	//First, make sure our framebuffer is empty 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
		world.Render();
		ship->Render();
		spawnManager.Render();
		bulletpool.Render();
	glPopMatrix();
	checkGLErrors();
}

void GameManager::play() {
	while (!inputManager.CloseWindow()) {
		deltaTime = my_timer.elapsedAndRestart();
		// update everything
		
		if(inputManager.Resize()) {
			resize(inputManager.resizeWidth, inputManager.resizeHeight);
		}
		
		Update();
		//Render, and swap front and back buffers
		render();
		SDL_GL_SwapBuffers();
	}

	quit();
}

void GameManager::Update() {
	inputManager.Update();
	ship->Update(deltaTime);
	spawnManager.Update(deltaTime);
	bulletpool.Update(deltaTime);
}

void GameManager::quit() {
	std::cout << "Bye bye..." << std::endl;
}