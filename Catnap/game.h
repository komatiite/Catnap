#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;

class Game {
public:
	Game(SDL_Window*& game_window,
		SDL_Surface*& surface,
		SDL_Renderer*& renderer);
	~Game();
	void run_game();

private:
	SDL_Window*& _game_window;
	SDL_Surface*& _surface;
	SDL_Renderer*& _renderer;
	
	void render_game();
	void destroy_resources();
};