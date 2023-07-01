#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;

void destroy_game(SDL_Window*& game_window, SDL_Surface*& surface, SDL_Renderer*& renderer);
bool init(SDL_Window*& game_window, SDL_Surface*& surface, SDL_Renderer*& renderer);