#include "text_display.h"

Text_Display::Text_Display(SDL_Renderer*& renderer) : _renderer(renderer) {

}

Text_Display::~Text_Display() {}

bool Text_Display::load_text() {
	_font = TTF_OpenFont("lazy.ttf", 28);
	if (_font == NULL) {
		cout << "Text_Display::load_text - Unable to load font. SDL_ttf Error: " << TTF_GetError() << endl;
		return false;
	}

	SDL_Color text_colour = { 0, 0, 0 };
	if (!create_text("load text test", text_colour))
	{
		cout << "Text_Display::load_text - Unable to render text" << endl;
		return false;
	}

	return true;
}

bool Text_Display::create_text(string text_string, SDL_Color text_color) {
	//free();

	SDL_Surface* text_surface = TTF_RenderText_Solid(_font, text_string.c_str(), text_color);

	if (text_surface == NULL) {
		cout << "Text_Display::create_text - Unable to render text surface. SDL_ttf error: " << TTF_GetError() << endl;
		return false;
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, text_surface);

	if (_texture == NULL) {
		cout << "Text_Display::create_text - Unable to create texture from text surface. SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	_width = text_surface->w;
	_height = text_surface->h;

	SDL_FreeSurface(text_surface);

	return true;
}

void Text_Display::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect render_rect = { x, y, _width, _height };

	if (clip != NULL) {
		render_rect.w = clip->w;
		render_rect.h = clip->h;
	}

	SDL_RenderCopyEx(_renderer, _texture, clip, &render_rect, angle, center, flip);
}


int Text_Display::getWidth() {
	return _width;
}

int Text_Display::getHeight() {
	return _height;
}

void Text_Display::free() {
	TTF_CloseFont(_font);
	_font = NULL;

	if (_texture != NULL) {
		SDL_DestroyTexture(_texture);
		_texture = NULL;
		_width = 0;
		_height = 0;
	}
}