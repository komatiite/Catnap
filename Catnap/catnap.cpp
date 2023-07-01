#include "game.h"
#include "catnap.h"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main(int argc, char* args[]) {
	SDL_Window* gameWindow;
	SDL_Renderer* renderer;

	if (!init(gameWindow, renderer)) {
		cout << ("ERROR - Could not initalize game.\n") << endl;
		return 1;
	}

	Game game(gameWindow, renderer);
	game.runGame();

	destroyGame(gameWindow, renderer);

	return 0;
}

void destroyGame(SDL_Window*& gameWindow, SDL_Renderer*& renderer) {
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;
	
	SDL_Quit();
}

bool init(SDL_Window*& gameWindow, SDL_Renderer*& renderer) {
	const string windowTitle = "Catnap";

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("ERROR - SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	gameWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (gameWindow == NULL) {
		printf("ERROR - Window could not be created. SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		printf("Renderer could not be created. SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}