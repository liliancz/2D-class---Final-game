//include SDL header
#include "SDL2-2.0.8\include\SDL.h"
#include "SDL2-2.0.8\include\SDL_image.h"
#include <iostream>
#include <assert.h>
#include <time.h>
#include <ctime>
#include <stack> 
#include <stdio.h>

#define songname "startsong.wav"

#pragma warning(disable : 4996)
using namespace std;

#include "SDL2-2.0.8\include\SDL.h"

#include "SDL2-2.0.8\include\SDL_image.h"

//load libraries
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2.lib")
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2main.lib")
//copy the SDL2_image.lib from the SDL image folder to your SDL lib folder
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2_image.lib")

#pragma comment(linker,"/subsystem:console")

unsigned char prev_key_state[256];
unsigned char *keys = NULL;




namespace Game
{
	SDL_Renderer *renderer = NULL;
	int screen_width = 700;
	int screen_height =600;
}


int random_figure()
{
	srand(time(NULL));
	int random_number = rand() % 6;
	return random_number;

}


void print_coins(SDL_Texture *font_texture, int number)
{
	/////////////////////////////////////////////////////////////////////////////////////////


	char coins_text[17];
	int coins_text_size = 32;

	coins_text[16] = 0;
	char tmp[20];
	sprintf(coins_text, "Coins: %d", number);

	float text_x = 2;
	float text_y = 2;
	for (int i = 0; i < 16; i++)
	{
		SDL_Rect src;
		src.x = 64 * (coins_text[i] % 16);//column
		src.y = 64 * (coins_text[i] / 16);//row
		src.w = 64;
		src.h = 64;

		SDL_Rect dest;
		dest.x = text_x;
		dest.y = text_y;
		dest.w = coins_text_size;
		dest.h = dest.w;

		//set transparency of the texture.
		//0 to 255, 255 is opaque
		SDL_SetTextureAlphaMod(font_texture, 255);

		SDL_RenderCopyEx(Game::renderer, font_texture, &src, &dest, 0, NULL, SDL_FLIP_NONE);

		//increment text_x!
		text_x += dest.w;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
void print_won(SDL_Texture *font_texture, int number)
{
	/////////////////////////////////////////////////////////////////////////////////////////


	char coins_text[17];
	int coins_text_size = 32;

	coins_text[16] = 0;
	char tmp[20];
	sprintf(coins_text, "Won: %d", number);

	float text_x = 2;
	float text_y = coins_text_size+2;
	for (int i = 0; i < 16; i++)
	{
		SDL_Rect src;
		src.x = 64 * (coins_text[i] % 16);//column
		src.y = 64 * (coins_text[i] / 16);//row
		src.w = 64;
		src.h = 64;

		SDL_Rect dest;
		dest.x = text_x;
		dest.y = text_y;
		dest.w = coins_text_size;
		dest.h = dest.w;

		//set transparency of the texture.
		//0 to 255, 255 is opaque
		SDL_SetTextureAlphaMod(font_texture, 255);

		SDL_RenderCopyEx(Game::renderer, font_texture, &src, &dest, 0, NULL, SDL_FLIP_NONE);

		//increment text_x!
		text_x += dest.w;
	}
	/////////////////////

}

int main(int argc, char **argv)
{
	int total_coins=1000;
	
	// ini audio
	SDL_Init(SDL_INIT_AUDIO);

	SDL_AudioSpec wavSpec;
	Uint8* wavBuffer;
	Uint32 wavLength;

	SDL_LoadWAV("startsong.wav", &wavSpec, &wavBuffer, &wavLength);
	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

	
	int sdlresult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlresult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	srand(time(0));
	
	prev_key_state[256];
	keys = (unsigned char*)SDL_GetKeyboardState(NULL);
	
	//place the png file next to your main.cpp
	const int n_imagenes = 10;
	const char *imagenes[n_imagenes];
	SDL_Surface *sprite_surface[n_imagenes];
	SDL_Texture *sprite_texture[n_imagenes];
	const char *font_filename = "font_sheet.png";

	imagenes[0] = "CIGARRETE.png";
	imagenes[1] = "heart.jpg";
	imagenes[2] = "cherry2.png";
	imagenes[3] = "WATERMELON.jpg";
	imagenes[4] = "CHARMANDER.jpg";
	imagenes[5] = "fox.png";
	imagenes[6] = "coin.png";

	SDL_Window *window = SDL_CreateWindow("ALE",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,Game::screen_width, Game::screen_height, SDL_WINDOW_SHOWN);

	Game::renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);

	for (int i = 0; i <= 6; i++)
	{
		sprite_surface[i] = IMG_Load(imagenes[i]);
		assert(sprite_surface[i]);
		sprite_texture[i] = SDL_CreateTextureFromSurface(Game::renderer, sprite_surface[i]);
		assert(sprite_texture[i]);
		SDL_FreeSurface(sprite_surface[i]);
	}
		
	SDL_Surface *font_surface = IMG_Load(font_filename);
	assert(font_surface);
	SDL_Texture *font_texture = SDL_CreateTextureFromSurface(Game::renderer, font_surface);
	SDL_FreeSurface(font_surface);

	// set color to black
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	//clear screen with black
	SDL_RenderClear(Game::renderer);

	unsigned int last_text_change_time = SDL_GetTicks();

	print_coins(font_texture, 0);

	print_won(font_texture, 0);
	
	unsigned char prev_key_state[256];
	unsigned char *keys = (unsigned char*)SDL_GetKeyboardState(NULL);


	float dest_0_y[3] = { 100.0, 100.0, 100.0 }; // 1st row
	float dest_1_y[3] = { 200.0, 200.0, 200.0 }; // 2nd row
	float dest_2_y[3] = { 300.0, 300.0, 300.0 }; // 3rd row
	float dest_3_y[3] = { 400.0, 400.0, 400.0 }; // 4th row
	float dest_4_y[3] = { 500.0, 500.0, 500.0 }; // 5th row
	float dest_5_y[3] = { 600.0, 600.0, 600.0 }; // 6th row
	float dest_6_y[3] = { 700.0, 700.0, 700.0 }; // 6th row

	int colum1 = 100;
	int colum2 = 300;
	int colum3 = 500;
	int won = 0;


	unsigned int current_time = SDL_GetTicks();



	// drawing the pictures 
	
	SDL_Rect tmp_rect[21];
	for (int i = 0; i < 21; i++)
	{
		tmp_rect[i].w = 90;
		tmp_rect[i].h = 90;
	}
	tmp_rect[0].x = colum1;
	tmp_rect[0].y = dest_0_y[0];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[0], NULL, (const SDL_Rect*)&tmp_rect[0], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[1].x = colum1;
	tmp_rect[1].y = dest_1_y[0];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[1], NULL, (const SDL_Rect*)&tmp_rect[1], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[2].x = colum1;
	tmp_rect[2].y = dest_2_y[0];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[2], NULL, (const SDL_Rect*)&tmp_rect[2], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[3].x = colum1;
	tmp_rect[3].y = dest_3_y[0];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[3], NULL, (const SDL_Rect*)&tmp_rect[3], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[4].x = colum1;
	tmp_rect[4].y = dest_4_y[0];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[4], NULL, (const SDL_Rect*)&tmp_rect[4], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[5].x = colum1;
	tmp_rect[5].y = dest_5_y[0];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[5], NULL, (const SDL_Rect*)&tmp_rect[5], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[6].x = colum1;
	tmp_rect[6].y = dest_6_y[0];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[6], NULL, (const SDL_Rect*)&tmp_rect[6], 0, NULL, SDL_FLIP_NONE);

	//----------------------------------------------------------------------
	tmp_rect[7].x = colum2;
	tmp_rect[7].y = dest_0_y[1];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[0], NULL, (const SDL_Rect*)&tmp_rect[7], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[8].x = colum2;
	tmp_rect[8].y = dest_1_y[1];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[1], NULL, (const SDL_Rect*)&tmp_rect[8], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[9].x = colum2;
	tmp_rect[9].y = dest_2_y[1];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[2], NULL, (const SDL_Rect*)&tmp_rect[9], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[10].x = colum2;
	tmp_rect[10].y = dest_3_y[1];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[3], NULL, (const SDL_Rect*)&tmp_rect[10], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[11].x = colum2;
	tmp_rect[11].y = dest_4_y[1];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[4], NULL, (const SDL_Rect*)&tmp_rect[11], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[12].x = colum2;
	tmp_rect[12].y = dest_5_y[1];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[5], NULL, (const SDL_Rect*)&tmp_rect[12], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[13].x = colum2;
	tmp_rect[13].y = dest_6_y[1];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[6], NULL, (const SDL_Rect*)&tmp_rect[13], 0, NULL, SDL_FLIP_NONE);

	//-------------------------------------------------------------------------------------------
	tmp_rect[14].x = colum3;
	tmp_rect[14].y = dest_0_y[2];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[0], NULL, (const SDL_Rect*)&tmp_rect[14], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[15].x = colum3;
	tmp_rect[15].y = dest_1_y[2];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[1], NULL, (const SDL_Rect*)&tmp_rect[15], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[16].x = colum3;
	tmp_rect[16].y = dest_2_y[2];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[2], NULL, (const SDL_Rect*)&tmp_rect[16], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[17].x = colum3;
	tmp_rect[17].y = dest_3_y[2];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[3], NULL, (const SDL_Rect*)&tmp_rect[17], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[18].x = colum3;
	tmp_rect[18].y = dest_4_y[2];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[4], NULL, (const SDL_Rect*)&tmp_rect[18], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[19].x = colum3;
	tmp_rect[19].y = dest_5_y[2];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[5], NULL, (const SDL_Rect*)&tmp_rect[19], 0, NULL, SDL_FLIP_NONE);

	tmp_rect[20].x = colum3;
	tmp_rect[20].y = dest_6_y[2];
	SDL_RenderCopyEx(Game::renderer, sprite_texture[6], NULL, (const SDL_Rect*)&tmp_rect[20], 0, NULL, SDL_FLIP_NONE);

	//-----------------------------------------------------------------------------------------

	//	SDL_RenderCopyEx(Game::renderer, sprite_texture0, &src, destfloat0, 0, NULL, SDL_FLIP_NONE);
	//	SDL_RenderCopyEx(Game::renderer, sprite_texture2, &src, destfloat2, 0, NULL, SDL_FLIP_NONE);

	//flip buffers
	SDL_RenderPresent(Game::renderer);

	bool done = false;
	while (!done)
	{
	
		memcpy(prev_key_state, keys, 256);

		//consume all window events first
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				done = true;
			}
		}
		
		//GAME CODE

		




		
		int out_of_screen = 450;

		float v1 = (rand() % 4) + 1;
		float v2 = v1 * 2;
		float v3 = v2 * 2;
		int pressed = false;
		if (keys[SDL_SCANCODE_SPACE])
		{
			printf("\nSPINNING\n");
			pressed = true;
			total_coins -= 100;
		}
		
		Uint32 timeout = SDL_GetTicks() + 1000 + rand() % 10; // time spining
			
		while (pressed)
		{
			// play audio

			int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
			SDL_PauseAudioDevice(deviceId, 0);


			while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) 
			{

				for (int i = 0; i < 1; i++)
				{
					dest_0_y[0] += v1;
					dest_1_y[0] += v1;
					dest_2_y[0] += v1;
					dest_3_y[0] += v1;
					dest_4_y[0] += v1;
					dest_5_y[0] += v1;
					dest_6_y[0] += v1;

					dest_0_y[1] += v2;
					dest_1_y[1] += v2;
					dest_2_y[1] += v2;
					dest_3_y[1] += v2;
					dest_4_y[1] += v2;
					dest_5_y[1] += v2;
					dest_6_y[1] += v2;

					dest_0_y[2] += v3;
					dest_1_y[2] += v3;
					dest_2_y[2] += v3;
					dest_3_y[2] += v3;
					dest_4_y[2] += v3;
					dest_5_y[2] += v3;
					dest_6_y[2] += v3;

					int max = 800;
					int min = 100;

					if (dest_0_y[0] >= max) dest_0_y[0] = min;
					if (dest_1_y[0] >= max) dest_1_y[0] = min;
					if (dest_2_y[0] >= max) dest_2_y[0] = min;
					if (dest_3_y[0] >= max) dest_3_y[0] = min;
					if (dest_4_y[0] >= max) dest_4_y[0] = min;
					if (dest_5_y[0] >= max) dest_5_y[0] = min;
					if (dest_6_y[0] >= max) dest_6_y[0] = min;

					if (dest_0_y[1] >= max) dest_0_y[1] = min;
					if (dest_1_y[1] >= max) dest_1_y[1] = min;
					if (dest_2_y[1] >= max) dest_2_y[1] = min;
					if (dest_3_y[1] >= max) dest_3_y[1] = min;
					if (dest_4_y[1] >= max) dest_4_y[1] = min;
					if (dest_5_y[1] >= max) dest_5_y[1] = min;
					if (dest_6_y[1] >= max) dest_6_y[1] = min;

					if (dest_0_y[2] >= max) dest_0_y[2] = min;
					if (dest_1_y[2] >= max) dest_1_y[2] = min;
					if (dest_2_y[2] >= max) dest_2_y[2] = min;
					if (dest_3_y[2] >= max) dest_3_y[2] = min;
					if (dest_4_y[2] >= max) dest_4_y[2] = min;
					if (dest_5_y[2] >= max) dest_5_y[2] = min;
					if (dest_6_y[2] >= max) dest_6_y[2] = min;

					
						
					// every frame
					//RENDER
						// set color to black
					SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
					//clear screen with black
					SDL_RenderClear(Game::renderer);
					
					
					tmp_rect[0].x = colum1;
					tmp_rect[0].y = dest_0_y[0];
					if (tmp_rect[0].y >= out_of_screen)
					{
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[0], NULL, (const SDL_Rect*)&tmp_rect[0], 0, NULL, SDL_FLIP_NONE);
					}
					
					tmp_rect[1].x = colum1;
					tmp_rect[1].y = dest_1_y[0];

					if (tmp_rect[1].y >= out_of_screen)
					{
						
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[1], NULL, (const SDL_Rect*)&tmp_rect[1], 0, NULL, SDL_FLIP_NONE);
					}
					
					tmp_rect[2].x = colum1;
					tmp_rect[2].y = dest_2_y[0];
					
					if (tmp_rect[2].y >= out_of_screen)
					{
						
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[2], NULL, (const SDL_Rect*)&tmp_rect[2], 0, NULL, SDL_FLIP_NONE);
					}

					tmp_rect[3].x = colum1;
					tmp_rect[3].y = dest_3_y[0];

					if (tmp_rect[3].y >= out_of_screen)
					{
						
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[3], NULL, (const SDL_Rect*)&tmp_rect[3], 0, NULL, SDL_FLIP_NONE);
					}

					tmp_rect[4].x = colum1;
					tmp_rect[4].y = dest_4_y[0];
					if (tmp_rect[4].y >= out_of_screen)
					{
						
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[4], NULL, (const SDL_Rect*)&tmp_rect[4], 0, NULL, SDL_FLIP_NONE);
					}

					tmp_rect[5].x = colum1;
					tmp_rect[5].y = dest_5_y[0];
					if (tmp_rect[5].y >= out_of_screen)
					{
						
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[5], NULL, (const SDL_Rect*)&tmp_rect[5], 0, NULL, SDL_FLIP_NONE);
					}
					

					tmp_rect[6].x = colum1;
					tmp_rect[6].y = dest_6_y[0];
					

					if (tmp_rect[6].y >= out_of_screen)
					{
						
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[6], NULL, (const SDL_Rect*)&tmp_rect[6], 0, NULL, SDL_FLIP_NONE);
					}

					//----------------------------------------------------------------------
					tmp_rect[7].x = colum2;
					tmp_rect[7].y = dest_0_y[1];
					if (tmp_rect[7].y >= out_of_screen)
					{

					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[0], NULL, (const SDL_Rect*)&tmp_rect[7], 0, NULL, SDL_FLIP_NONE);
					}
					

					tmp_rect[8].x = colum2;
					tmp_rect[8].y = dest_1_y[1];
					if (tmp_rect[8].y >= out_of_screen)
					{

					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[1], NULL, (const SDL_Rect*)&tmp_rect[8], 0, NULL, SDL_FLIP_NONE);
					}


					tmp_rect[9].x = colum2;
					tmp_rect[9].y = dest_2_y[1];
					if (tmp_rect[9].y >= out_of_screen)
					{

					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[2], NULL, (const SDL_Rect*)&tmp_rect[9], 0, NULL, SDL_FLIP_NONE);
					}
					tmp_rect[10].x = colum2;
					tmp_rect[10].y = dest_3_y[1];
					if (tmp_rect[10].y >= out_of_screen)
					{
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[3], NULL, (const SDL_Rect*)&tmp_rect[10], 0, NULL, SDL_FLIP_NONE);
					}
					tmp_rect[11].x = colum2;
					tmp_rect[11].y = dest_4_y[1];
					if (tmp_rect[11].y >= out_of_screen)
					{

					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[4], NULL, (const SDL_Rect*)&tmp_rect[11], 0, NULL, SDL_FLIP_NONE);
					}
					tmp_rect[12].x = colum2;
					tmp_rect[12].y = dest_5_y[1];
					if (tmp_rect[12].y < out_of_screen)
					SDL_RenderCopyEx(Game::renderer, sprite_texture[5], NULL, (const SDL_Rect*)&tmp_rect[12], 0, NULL, SDL_FLIP_NONE);

					tmp_rect[13].x = colum2;
					tmp_rect[13].y = dest_6_y[1];
					

					if (tmp_rect[13].y >= out_of_screen)
					{
						
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[6], NULL, (const SDL_Rect*)&tmp_rect[13], 0, NULL, SDL_FLIP_NONE);
					}

					//-------------------------------------------------------------------------------------------
					tmp_rect[14].x = colum3;
					tmp_rect[14].y = dest_0_y[2];
					if (tmp_rect[14].y >= out_of_screen)
					{ }
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[0], NULL, (const SDL_Rect*)&tmp_rect[14], 0, NULL, SDL_FLIP_NONE);
					}
					tmp_rect[15].x = colum3;
					tmp_rect[15].y = dest_1_y[2];
					if (tmp_rect[15].y >= out_of_screen)
					{ }
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[1], NULL, (const SDL_Rect*)&tmp_rect[15], 0, NULL, SDL_FLIP_NONE);
					}
					tmp_rect[16].x = colum3;
					tmp_rect[16].y = dest_2_y[2];
					if (tmp_rect[16].y >= out_of_screen)
					{
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[2], NULL, (const SDL_Rect*)&tmp_rect[16], 0, NULL, SDL_FLIP_NONE);
					}
					tmp_rect[17].x = colum3;
					tmp_rect[17].y = dest_3_y[2];
					if (tmp_rect[17].y >= out_of_screen)
					{
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[3], NULL, (const SDL_Rect*)&tmp_rect[17], 0, NULL, SDL_FLIP_NONE);
					}
					tmp_rect[18].x = colum3;
					tmp_rect[18].y = dest_4_y[2];
					if (tmp_rect[18].y >= out_of_screen)
					{ }
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[4], NULL, (const SDL_Rect*)&tmp_rect[18], 0, NULL, SDL_FLIP_NONE);
					}
					tmp_rect[19].x = colum3;
					tmp_rect[19].y = dest_5_y[2];
				

					if (tmp_rect[19].y >= out_of_screen)
					{
						
					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[5], NULL, (const SDL_Rect*)&tmp_rect[19], 0, NULL, SDL_FLIP_NONE);
					}

					tmp_rect[20].x = colum3;
					tmp_rect[20].y = dest_6_y[2];

					if (tmp_rect[20].y >= out_of_screen)
					{

					}
					else
					{
						SDL_RenderCopyEx(Game::renderer, sprite_texture[6], NULL, (const SDL_Rect*)&tmp_rect[20], 0, NULL, SDL_FLIP_NONE);
					}

					
		
					print_won(font_texture, won);
					print_coins(font_texture, total_coins);
			

					//flip buffers
					SDL_RenderPresent(Game::renderer);
				}
			pressed = false;
			}	

			won = 0;
			if (tmp_rect[0].y < out_of_screen && tmp_rect[7].y < out_of_screen && tmp_rect[14].y < out_of_screen)
			{
				printf("\n100 COIN EARN");
				won +=100;
			}

			if (tmp_rect[1].y < out_of_screen && tmp_rect[8].y < out_of_screen && tmp_rect[15].y < out_of_screen)
			{
				printf("\n100 COIN EARN");
				won += 100;
			}

			if (tmp_rect[2].y < out_of_screen && tmp_rect[9].y < out_of_screen && tmp_rect[16].y < out_of_screen)
			{
				printf("\n100 COIN EARN");
				won += 100;
			}

			if (tmp_rect[3].y < out_of_screen && tmp_rect[10].y < out_of_screen && tmp_rect[17].y < out_of_screen)
			{
				printf("\n100 COIN EARN");
				won += 100;
			}

			if (tmp_rect[4].y < out_of_screen && tmp_rect[11].y < out_of_screen && tmp_rect[18].y < out_of_screen)
			{
				printf("\n100 COIN EARN");
				won += 100;
			}
			if (tmp_rect[5].y < out_of_screen && tmp_rect[12].y < out_of_screen && tmp_rect[19].y < out_of_screen)
			{
				printf("\n100 COIN EARN");
				won += 100;
			}
			if (tmp_rect[6].y < out_of_screen && tmp_rect[13].y < out_of_screen && tmp_rect[20].y < out_of_screen)
			{
				printf("\n100 COIN EARN");
				won += 100;
			}

			total_coins += won;
	
		}
	
	}	
	
	SDL_Delay(3000);
		// clean up
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
	SDL_Quit();

	return 0;
}
