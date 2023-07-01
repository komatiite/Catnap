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

	while (!quit) {

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
		}

		render_game();
	}

}

void Game::render_game() {

}

void Game::destroy_resources() {

}