#pragma once
#include <iostream>
#include <assert.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
using namespace std;

//include SDL header
#include "SDL2-2.0.8/include/SDL.h"

//load libraries
#pragma comment(lib, "SDL2-2.0.8\\lib\\x86\\SDL2.lib")
#pragma comment(lib, "SDL2-2.0.8\\lib\\x86\\SDL2main.lib")
#pragma comment(linker, "/subsystem:console")
//copy the SDL2_image.lib from the SDL image folder to your SDL lib folder
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2_image.lib")


//copy the SDL_image.h from the SDL image folder to your SDL include folder
#include "SDL2-2.0.8\include\SDL_image.h"


SDL_Renderer *renderer = NULL;
const int block_size = 8;


void draw_I(int x, int y)
{
	//draw black outline
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect outline_rect = { x, y, 45, 12 };
	SDL_RenderFillRect(renderer, &outline_rect);

	//draw individual boxes
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_Rect block_rect = { x + 1, y + 1, block_size, block_size };
	SDL_RenderFillRect(renderer, &block_rect);

	for (int i = 0; i < 3; i++)
	{
		block_rect.x += block_size + 1;
		SDL_RenderFillRect(renderer, &block_rect);
	}

}

void draw_O(int x, int y)
{
	//draw black outline
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect outline_rect = { x, y, 23, 23 };
	SDL_RenderFillRect(renderer, &outline_rect);

	SDL_SetRenderDrawColor(renderer, 244, 232, 104, 255);
	SDL_Rect block_rect = { x + 1, y + 1, block_size, block_size };
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size + 1;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x -= block_size + 1;
	block_rect.y += block_size + 1;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size + 1;
	SDL_RenderFillRect(renderer, &block_rect);
}

void draw_heart(int x, int y)
{
	//SDL_SetRenderDrawColor(renderer, 5, 0, 0, 255);
	//SDL_Rect outline_rect = { x, y, 12, 34 };
	//SDL_RenderFillRect(renderer, &outline_rect);

	//outline_rect.x += 11;
	//outline_rect.y += 22;
	//outline_rect.h = 12;
//	SDL_RenderFillRect(renderer, &outline_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	SDL_Rect block_rect = { x , y , block_size, block_size };
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);
	
	block_rect.x += block_size*5;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (2)
	block_rect.x -= block_size*10;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size*3;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (3)
	block_rect.x -= block_size * 12;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (4)
	block_rect.x -= block_size * 13;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (5)
	block_rect.x -= block_size * 13;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (5)
	block_rect.x -= block_size * 13;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (6)
	block_rect.x -= block_size * 12;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (7)
	block_rect.x -= block_size * 10;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (8)
	block_rect.x -= block_size * 8;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (9)
	block_rect.x -= block_size * 6;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (10)
	block_rect.x -= block_size * 4;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 139, 0, 0, 255); // dark red
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size; // start line (11)
	block_rect.x -= block_size * 2;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x += block_size;
	SDL_RenderFillRect(renderer, &block_rect);
	

	
}

void draw_J(int x, int y)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect outline_rect = { x + 11, y, 12, 34 };
	SDL_RenderFillRect(renderer, &outline_rect);

	outline_rect.x -= 11;
	outline_rect.y += 22;
	outline_rect.h = 12;
	SDL_RenderFillRect(renderer, &outline_rect);

	SDL_SetRenderDrawColor(renderer, 255, 95, 0, 255);
	SDL_Rect block_rect = { x + 12, y + 1, block_size, block_size };
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size + 1;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.y += block_size + 1;
	SDL_RenderFillRect(renderer, &block_rect);

	block_rect.x -= block_size + 1;
	SDL_RenderFillRect(renderer, &block_rect);
}
int main(int argc, char **argv)
{
	//place the png file next to your main.cpp
	const char *cigar = "CIGARRETE.png";

	SDL_Init(SDL_INIT_VIDEO);
	//640, 480

	SDL_Window *window = SDL_CreateWindow("ALE - SLOT MACHINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//infinite loop
	for (;;)
	{

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				//terminate the process
				exit(0);
			}
		}


		//load image into a surface.
		SDL_Surface *sprite_surface = IMG_Load(cigar);
		assert(sprite_surface);
		//we draw textures, not surfaces.
		SDL_Texture *sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
		//free the surface as it is not needed anymore
		SDL_FreeSurface(sprite_surface);

		//GAME CODE BEGIN

		//DRAWING CODE
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // BACK COLOR BLACK
		SDL_RenderClear(renderer);
		
		//draw_J(50, 50);
		//draw_heart(100, 50);
		//draw_heart(250, 50);
		//draw_heart(400, 50);
		//draw_O(150, 55);
		//draw_I(200, 60);

		//set transparency of the texture.
		//0 to 255, 255 is opaque
		SDL_SetTextureAlphaMod(sprite_texture, 255);


		//swap buffers
		SDL_RenderPresent(renderer);

		//GAME CODE END
	}










	return 0;
}