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
#include "InputManager.h"
#include "Spaceship.h"
#include "Bullet.h"

using std::cerr;
using std::endl;
using GLUtils::checkGLErrors;

std::vector<Renderable*> GameManager::renderList;
std::vector<Updateable*> GameManager::updateList;
/*
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
  // glFrustum(10.0f, 10.0, 10.0, 10.0f, 0, 20);
   gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0f, 0.0f, 0.0f);

}



void GameManager::setOpenGLStates() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(1.0, 1.0, 1.0, 1.0);

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
}

void GameManager::render() {
	//Clear screen, and set the correct program
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
		for(std::vector<Renderable*>::iterator it = GameManager::renderList.begin(); it != GameManager::renderList.end();) {
			(*it)->Render();
			if((*it)->Delete()) {
				Renderable *temp = (*it);
				delete temp;
				it = GameManager::renderList.erase(it);	
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

*/


GameManager::GameManager() {
	my_timer.restart();
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	degrees = 0.0f;

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
   gluPerspective(50, width/height, 0.1, 10);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0f, 0.0f, -5.0f);
}

void GameManager::setOpenGLStates() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(1.0, 1.0, 1.0, 1.0);

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
}

void GameManager::drawQuad() {
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
}

void GameManager::drawCube() {
	drawQuad();
	glRotatef(90, 1, 0, 0);
	drawQuad();
	glRotatef(90, 1, 0, 0);
	drawQuad();
	glRotatef(90, 1, 0, 0);
	drawQuad();
	glRotatef(90, 0, 1, 0);
	drawQuad();
	glRotatef(180, 0, 1, 0);
	drawQuad();
}

void GameManager::render() {
	degrees += 90.0f*static_cast<float>(deltaTime);
	if (degrees >= 360) {
		degrees -= 360;
	}

	glPushMatrix();

	//First, make sure our framebuffer is empty 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	glPopMatrix();
	glPushMatrix();
			for(std::vector<Renderable*>::iterator it = GameManager::renderList.begin(); it != GameManager::renderList.end();) {
			(*it)->Render();
			if((*it)->Delete()) {
				Renderable *temp = (*it);
				delete temp;
				it = GameManager::renderList.erase(it);	
			} else {
				++it;
			}
		}
	glPopMatrix();
	checkGLErrors();
}

void GameManager::play() {
	/*
	bool doExit = false;

	//SDL main loop
	while (!doExit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {// poll for pending events
			switch (event.type) {
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
				case SDLK_ESCAPE:
					doExit = true;
					break;
				case SDLK_q:
					if (event.key.keysym.mod & KMOD_CTRL) doExit = true; //Ctrl+q
					break;
				case SDLK_a:
					x += 0.01f;
					break;
				case SDLK_d:
					x -= 0.01f;
					break;
				case SDLK_w:
					z += 0.1f;
					break;
				case SDLK_s:
					z -= 0.1f;
					break;
				}
				break;
			case SDL_QUIT: //e.g., user clicks the upper right x
				doExit = true;
				break;
			case SDL_VIDEORESIZE:
			   resize(event.resize.w, event.resize.h);
			   break; 
			}
		}

		//Render, and swap front and back buffers
		render();
		SDL_GL_SwapBuffers();
	}
	quit();
	*/

	//SDL main loop
	
	while (!inputManager.CloseWindow()) {
		fpsTime += deltaTime = my_timer.elapsedAndRestart();
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

	for(int i = 0; i < GameManager::renderList.size(); i++) {
		GameManager::renderList[i]->Update(deltaTime);
	}
}

void GameManager::quit() {
	std::cout << "Bye bye..." << std::endl;
}

Image GameManager::readTexture(std::string image) {
	Image img;
    std::ifstream file(image, std::ios::binary | std::ios::in);

	DWORD size = 0;	

	//Read BMP header
	file.seekg(18, std::ios_base::beg); //Skip 18 bytes
	file.read(reinterpret_cast<char*>(&img.width), 4); //Read the 4 byte width
	file.read(reinterpret_cast<char*>(&img.height), 4); //Read the 4 byte height
	file.seekg(0, std::ios_base::end); 
	size = static_cast<long>(file.tellg()) - 54; //Get the number of bytes in the file (minus the header)
	file.seekg(54, std::ios_base::beg); //Rewind the file to just after the BMP header (skip 54 bytes)

	//Allocate data and read contents
	img.data.resize(size);
	file.read(&img.data[0], size);
	file.close();

	if (img.width*img.height*3==size)
		img.components = 3;
	else if (img.width*img.height*4==size)
		img.components = 4;
	else {
		std::cout << "Unknown number of components!" << std::endl;
		exit(-1);
	}

	return img;
}