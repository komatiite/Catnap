#include "game.h"

Game::Game(SDL_Window*& game_window,
	SDL_Surface*& surface,
	SDL_Renderer*& renderer) : _game_window(game_window), _surface(surface), _renderer(renderer) {
}

Game::~Game() {
}

void Game::run_game() {
	cout << "running game" << endl;

	bool quit = false;
	SDL_Event event;

	Text_Display text_display(_renderer);

	if (!text_display.load_text()) {
		cout << "Game::run_game - terminating game" << endl;
		quit = true;
	}


	while (!quit) {

		// scan events
		// -- mouseclick, run through menu items, game Things

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
		}

		SDL_Color text_colour = { 0, 0, 0 };
		text_display.create_text("Yay this wrks!", text_colour);

		render_game(text_display);
	}

	destroy_resources(text_display);

}

void Game::render_game(Text_Display& text_display) {
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);

	text_display.render((1920 - text_display.getWidth()) / 2, (1080 - text_display.getHeight()) / 2);

	SDL_RenderPresent(_renderer);
}

void Game::destroy_resources(Text_Display& text_display) {
	text_display.free();
}