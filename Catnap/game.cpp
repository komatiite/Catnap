#include "game.h"

Game::Game(SDL_Window*& gameWindow,
	SDL_Renderer*& renderer) : mGameWindow(gameWindow), mRenderer(renderer) {

}

Game::~Game() {
}

void Game::runGame() {
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

		renderGame();
	}

}

void Game::renderGame() {

}

void Game::destroyResources() {

}