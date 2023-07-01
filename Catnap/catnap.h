#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;

void destroyGame(SDL_Window*& gameWindow, SDL_Renderer*& renderer);
bool init(SDL_Window*& gameWindow, SDL_Renderer*& renderer);