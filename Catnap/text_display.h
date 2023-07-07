#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

class Text_Display {
public:
	Text_Display(SDL_Renderer*& renderer);
	~Text_Display();
	bool load_text();
	bool create_text(string text_string, SDL_Color text_color);
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	int getWidth();
	int getHeight();
	void free();

private:
	TTF_Font* _font;
	SDL_Texture* _texture;
	SDL_Renderer*& _renderer;
	int _width;
	int _height;
};