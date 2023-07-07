#pragma once

#include <SDL.h>
#include <iostream>
#include "text_display.h"

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
	//Text_Display _text_display;
	
	void render_game(Text_Display& text_display);
	void destroy_resources(Text_Display& text_display);
};