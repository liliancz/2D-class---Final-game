
#include <iostream>
#include <assert.h>
#include <time.h>
#include <ctime>
#include <stack> 
#include <stdio.h>
#include <stdlib.h>    
#include <time.h>       
#include "SDL2_mixer-2.0.2\include\SDL_mixer.h"
#include "SDL2-2.0.8\include\SDL.h"
#include "SDL2-2.0.8\include\SDL_image.h"

#pragma warning(disable : 4996)
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2.lib")
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2main.lib")
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2_image.lib")
#pragma comment(lib,"SDL2_mixer-2.0.2\\lib\\x86\\SDL2_mixer.lib")

namespace Game
{
	SDL_Renderer *renderer = NULL;
	int screen_width = 500;
	int screen_height = 550;
}

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);

	int sdlresult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlresult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	SDL_Window *window = SDL_CreateWindow("ALE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::screen_width, Game::screen_height, SDL_WINDOW_SHOWN);
	Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	SDL_RenderPresent(Game::renderer);


	return 0;
}