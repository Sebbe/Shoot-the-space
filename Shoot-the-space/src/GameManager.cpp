#include "GameManager.h"
#include "GLUtils/GLUtils.hpp"
#include <Windows.h>
#include <GL/GL.h>
#include <gl/GLU.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <assert.h>
#include <stdexcept>
#include "InputManager.h"
#include "Spaceship.h"
#include "Bullet.h"

using std::cerr;
using std::endl;
using GLUtils::checkGLErrors;

std::vector<Renderable*> GameManager::renderList;
std::vector<Updateable*> GameManager::updateList;
GameManager::GameManager() {
	my_timer.restart();
	Spaceship *ship = new Spaceship(&inputManager);
	GameManager::renderList.push_back(ship);
	fps = 0;
	fpsTime = 0;
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

	//       left	right	bottom	top		near	far
   glFrustum(-2,	2,		-2,		2,		1.5,		25);

   glLoadIdentity();

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();

}



void GameManager::setOpenGLStates() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0, 0.0, 0.5, 1.0);
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
}

void GameManager::render() {
	//Clear screen, and set the correct program
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
		for(std::vector<Renderable*>::iterator it = GameManager::renderList.begin(); it != GameManager::renderList.end();) {
			(*it)->Render();
			if((*it)->Delete()) {
				Renderable *temp = (*it);
				it = GameManager::renderList.erase(it);
 				delete temp;
					
			} else {
				++it;
			}
		}
	glPopMatrix();
	checkGLErrors();
}



void GameManager::play() {
	//SDL main loop
	
	while (!inputManager.CloseWindow()) {
		fps++;
		fpsTime += deltaTime = my_timer.elapsedAndRestart();
		
		if(fpsTime >= 1.0) {
			std::stringstream ss;
			std::string st;
			ss << "NITH - PG430 Space Invaders, fps: " << fps;
			st = ss.str();
			SDL_WM_SetCaption(st.c_str(), "");
			fps = 0;
			fpsTime -= 1.0;
		}
		// update everything
		
		Update();
		//Render, and swap front and back buffers
		render();
		SDL_GL_SwapBuffers();
	}

	quit();

}

void GameManager::Update() {
	inputManager.Update();

	for(int i = 0; i < GameManager::renderList.size(); i++) {
		GameManager::renderList[i]->Update(deltaTime);
	}
}

void GameManager::quit() {

	std::cout << "Bye bye..." << std::endl;

}