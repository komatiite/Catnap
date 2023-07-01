#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;

class Game {
public:
	Game(SDL_Window*& gameWindow,
		SDL_Renderer*& renderer);
	~Game();
	void runGame();

private:
	SDL_Window*& mGameWindow;
	SDL_Renderer*& mRenderer;
	
	void renderGame();
	void destroyResources();
};