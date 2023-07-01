#include "game.h"
#include "catnap.h"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main(int argc, char* args[]) {
	SDL_Window* game_window;
	SDL_Surface *surface;
	SDL_Renderer* renderer;

	if (!init(game_window, surface, renderer)) {
		cout << ("ERROR - Could not initalize game.\n") << endl;
		return 1;
	}

	Game game(game_window, surface, renderer);
	game.run_game();

	destroy_game(game_window, surface, renderer);

	return 0;
}

void destroy_game(SDL_Window*& game_window, SDL_Surface*& surface, SDL_Renderer*& renderer) {
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_FreeSurface(surface);
	surface = NULL;

	SDL_DestroyWindow(game_window);
	game_window = NULL;
	
	SDL_Quit();
}

bool init(SDL_Window*& game_window, SDL_Surface*& surface, SDL_Renderer*& renderer) {
	const string window_title = "Catnap";

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("ERROR - SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	game_window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (game_window == NULL) {
		printf("ERROR - Window could not be created. SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	surface = SDL_GetWindowSurface(game_window);

	renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		printf("Renderer could not be created. SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}