// add amimated sprites
// add particles


//include SDL header
#include "SDL2-2.0.8\include\SDL.h"
#include "SDL2-2.0.8\include\SDL_image.h"
#include <iostream>
#include <assert.h>
#include <time.h>
#include <ctime>
#include <stack> 
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SDL2_mixer-2.0.2\include\SDL_mixer.h"


#define songname "startsong.wav"
#define songwin "win.wav"
#define songbip "bip.wav"
#define WAV_PATH "bip.wav"

#pragma warning(disable : 4996)


#include "SDL2-2.0.8\include\SDL.h"

#include "SDL2-2.0.8\include\SDL_image.h"

//load libraries
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2.lib")
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2main.lib")
//copy the SDL2_image.lib from the SDL image folder to your SDL lib folder
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2_image.lib")
#pragma comment(lib,"SDL2_mixer-2.0.2\\lib\\x86\\SDL2_mixer.lib")

#pragma comment(linker,"/subsystem:console")

unsigned char prev_key_state[256];
unsigned char *keys = NULL;







namespace Game
{
	SDL_Renderer *renderer = NULL;
	int screen_width = 500;
	int screen_height = 550;
}


int random_figure()
{

	int random_number = rand() % 7;
	return random_number;

}

void init_position(SDL_Texture *sprite_texture[15])
{
	int pos1_x = 50;
	int pos1_y = 100;
	// drawing the pictures 
	SDL_Rect draw[21];
	for (int i = 0; i < 21; i++)
	{
		draw[i].w = 100;
		draw[i].h = 100;
	}

	int number_of_rows = 4;
	int number_of_columns = 3;
	int n;
	for (int j = 0; j < number_of_rows; j++)
	{
		for (int i = 0; i < number_of_columns; i++)
		{
			draw[i].x = pos1_x;
			draw[i].y = pos1_y;
			n = random_figure();
			SDL_RenderCopyEx(Game::renderer, sprite_texture[n], NULL, (const SDL_Rect*)&draw[i], 0, NULL, SDL_FLIP_NONE);
			pos1_x += draw[i].w + 1;
		}
		pos1_y += draw[j].h + 1;
		pos1_x = 50;
	}
}


void Winner(SDL_Texture *sprite_texture[15], int save_winner[16], int number)
{
	int pos1_x = 50;
	int pos1_y = 100;
	// drawing the pictures 
	SDL_Rect draw[21];
	for (int i = 0; i < 21; i++)
	{
		draw[i].w = 100;
		draw[i].h = 100;
	}

	int number_of_rows = 4;
	int number_of_columns = 3;
	int n=0;
	for (int j = 0; j < number_of_rows; j++)
	{
		for (int i = 0; i < number_of_columns; i++)
		{
			draw[i].x = pos1_x;
			draw[i].y = pos1_y;
			n = save_winner[n++];
			if (n == number)
			{
				SDL_RenderCopyEx(Game::renderer, sprite_texture[n+7], NULL, (const SDL_Rect*)&draw[i], 0, NULL, SDL_FLIP_NONE);
			}
			else
			{
				SDL_RenderCopyEx(Game::renderer, sprite_texture[n], NULL, (const SDL_Rect*)&draw[i], 0, NULL, SDL_FLIP_NONE);
			}
			pos1_x += draw[i].w + 1;
		}
		pos1_y += draw[j].h + 1;
		pos1_x = 50;
	}
}
void print_play(SDL_Texture *font_texture)
{
	/////////////////////////////////////////////////////////////////////////////////////////
	char play_text[30];
	int play_text_size = 25;

	play_text[20] = 0;
	//char tmp[20];
	sprintf(play_text, "SPACEBAR TO PLAY %d");

	int text_x = 2;
	int text_y = play_text_size * 2 + 2;
	for (int i = 0; i < 16; i++)
	{
		SDL_Rect src;
		src.x = 64 * (play_text[i] % 16);//column
		src.y = 64 * (play_text[i] / 16);//row
		src.w = 64;
		src.h = 64;

		SDL_Rect dest;
		dest.x = text_x;
		dest.y = text_y;
		dest.w = play_text_size;
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

void print_buycoins(SDL_Texture *font_texture)
{
	/////////////////////////////////////////////////////////////////////////////////////////
	char play_text[30];
	int play_text_size = 25;
	int number = 0;
	play_text[20] = 0;
	//char tmp[20];
	sprintf(play_text, "A= buy 1000");

	int text_x = 2;
	int text_y = 520;
	for (int i = 0; i < 16; i++)
	{
		SDL_Rect src;
		src.x = 64 * (play_text[i] % 16);//column
		src.y = 64 * (play_text[i] / 16);//row
		src.w = 64;
		src.h = 64;

		SDL_Rect dest;
		dest.x = text_x;
		dest.y = text_y;
		dest.w = play_text_size;
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



void print_coins(SDL_Texture *font_texture, int number)
{
	/////////////////////////////////////////////////////////////////////////////////////////


	char coins_text[17];
	int coins_text_size = 25;

	coins_text[16] = 0;
	//	char tmp[20];
	sprintf(coins_text, "Coins: %d", number);

	int text_x = 2;
	int text_y = 2;
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
	char coins_text[17];
	int coins_text_size = 25;
	coins_text[16] = 0;
	sprintf(coins_text, "Won: %d", number);

	int text_x = 2;
	int text_y = coins_text_size + 2;
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

		SDL_SetTextureAlphaMod(font_texture, 255);
		SDL_RenderCopyEx(Game::renderer, font_texture, &src, &dest, 0, NULL, SDL_FLIP_NONE);

		//increment text_x!
		text_x += dest.w;
	}
	/////////////////////

}

int draw_lines(int array[], int number)
{
	SDL_Rect draw[4];
	int x1 = 25, x2 = 100, x3 = 200, x4 = 300, x5 = 400, x6 = 475;
	int y1 = 0, y2 = 0, y3 = 0, y4 = 0, y5=0, y6=0;
	int temp = 0;
	for (int i = 0; i < 16; i++)
	{
		if (i < 4 && number == array[i])
		{
			switch (i + 1)
			{
			case 1:
				draw[1].x = 50;
				draw[1].y = 100;
				x1 = 25;
				y1 = 150;
				x2 = 100;;
				y2 = 150;
				temp = i+1;
				printf("1\n");
				break;
			case 2:
				draw[1].x = 50;
				draw[1].y = 200;
				x1 = 25;
				y1 = 250;
				x2 = 100;
				y2 = 250;
				temp = i+1;
				printf("2\n");
				break;
			case 3:
				draw[1].x = 50;
				draw[1].y = 300;
				x1 = 25;
				y1 = 350;
				x2 = 100;
				y2 = 350;
				temp = i+1;
				printf("3\n");
				break;
			case 4:
				draw[1].x = 50;
				draw[1].y = 400;
				x1 = 25;
				y1 = 450;
				x2 = 100;
				y2 = 450;
				printf("4\n");
				temp = i+1;
				break;
			}
		}
		
		if (temp == 1)
		{
			if (i > 3 && i < 8 && number == array[i])
			{
				switch (i + 1)
				{
				case 5:
					draw[2].x = 150;
					draw[2].y = 100;
					x3 = 200;
					y3 = 150;
					printf("1-5\n");
					temp = i + 1;
					break;
				case 6:
					draw[2].x = 150;
					draw[2].y = 200;
					x3 = 200;
					y3 = 250;
					printf("1-6\n");
					temp = i + 1;
					break;
				}
			}
		}

		if (temp == 2)
		{
			if (i > 3 && i < 8 && number == array[i])
			{
				switch (i + 1)
				{
				case 5:
					draw[2].x = 150;
					draw[2].y = 100;
					x3 = 200;
					y3 = 150;
					temp = i + 1;
					printf("2-5\n");
					break;
				case 6:
					draw[2].x = 150;
					draw[2].y = 200;
					x3 = 200;
					y3 = 250;
					printf("2-6\n");
					temp = i + 1;
					break;
				case 7:
					draw[2].x = 150;
					draw[2].y = 300;
					x3 = 200;
					y3 = 350;
					printf("2-7\n");
					temp = i + 1;
					break;
				}
			}
		}
		
		if (temp == 3)
		{
			if (i > 3 && i < 8 && number == array[i])
			{
				switch (i + 1)
				{
				case 6:
					draw[2].x = 150;
					draw[2].y = 200;
					x3 = 200;
					y3 = 250;
					printf("3-6\n");
					temp = i + 1;
					break;
					
				case 7:
					draw[2].x = 150;
					draw[2].y = 300;
					x3 = 200;
					y3 = 350;
					printf("3-7\n");
					temp = i + 1;
					break;
					
				case 8:
					draw[2].x = 150;
					draw[2].y = 400;
					x3 = 200;
					y3 = 450;
					printf("3-8\n");
					temp = i + 1;
					break;
				}
			}
		}
		if (temp == 4)
		{
			if (i > 3 && i < 8 && number == array[i])
			{
				switch (i + 1)
				{
				case 7:
					draw[2].x = 150;
					draw[2].y = 300;
					x3 = 200;
					y3 = 350;
					printf("4-7\n");
					temp = i + 1;
					break;
				case 8:
					draw[2].x = 150;
					draw[2].y = 400;
					x3 = 200;
					y3 = 450;
					printf("4-8\n");
					temp = i + 1;
					break;
				}
			}
		}
		if (temp == 5)
		{
			if (i > 8 && i < 12 && number == array[i])
			{

				switch (i + 1)
				{
				case 9:
					draw[3].x = 250;
					draw[3].y = 100;
					x4 = 300;
					y4 = 150;
					x5 = 400;
					y5 = 150;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[1], 0, NULL, SDL_FLIP_NONE);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[2], 0, NULL, SDL_FLIP_NONE);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[3], 0, NULL, SDL_FLIP_NONE);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("5-9\n");
					temp = i + 1;
					return 200;
					break;
				case 10:
					draw[3].x = 250;
					draw[3].y = 200;
					x4 = 300;
					y4 = 250;
					x5 = 400;
					y5 = 250;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[1], 0, NULL, SDL_FLIP_NONE);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[2], 0, NULL, SDL_FLIP_NONE);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[3], 0, NULL, SDL_FLIP_NONE);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("5-10\n");
					temp = i + 1;
					return 200;
					break;
				}
			}
		}
		
		if (temp == 6)
		{
			if (i > 8 && i < 12 && number == array[i] )
			{
				switch (i + 1)
				{
				case 9:
					draw[3].x = 250;
					draw[3].y = 100;
					x4 = 300;
					y4 = 150;
					x5 = 400;
					y5 = 150;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[1], 0, NULL, SDL_FLIP_NONE);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[2], 0, NULL, SDL_FLIP_NONE);
					//SDL_RenderCopyEx(Game::renderer, texture[number + 7], NULL, &draw[3], 0, NULL, SDL_FLIP_NONE);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("6-9\n");
					temp = i + 1;
					return 200;
					break;
				case 10:
					draw[3].x = 250;
					draw[3].y = 200;
					x4 = 300;
					y4 = 250;
					x5 = 400;
					y5 = 250;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("6-10\n");
					temp = i + 1;
					break;
				case 11:
					draw[3].x = 250;
					draw[3].y = 300;
					x4 = 300;
					y4 = 350;
					x5 = 400;
					y5 = 350;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					
					printf("6-11\n");
					temp = i + 1;
					return 200;
					break;
				}
			}
		}

		if (temp == 7)
		{
			if (i > 8 && i < 12 && number == array[i])
			{
				switch (i + 1)
				{
				case 10:
					draw[3].x = 250;
					draw[3].y = 200;
					x4 = 300;
					y4 = 250;
					x5 = 400;
					y5 = 250;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("7-10\n");
					temp = i + 1;
					return 200;
					break;
				case 11:
					draw[3].x = 250;
					draw[3].y = 300;
					x4 = 300;
					y4 = 350;
					x5 = 400;
					y5 = 350;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("7-11\n");
					temp = i + 1;
					return 200;
					break;
				case 12:
					draw[3].x = 250;
					draw[3].y = 400;
					x4 = 300;
					y4 = 450;	
					x5 = 400;
					y5 = 450;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("7-12\n");
					temp = i + 1;
					return 200;
					break;
				}
			}
		}
		if (temp == 8)
		{
			if (i > 8 && i < 12 && number == array[i])
			{
				switch (i + 1)
				{
				case 11:
					draw[3].x = 250;
					draw[3].y = 300;
					x4 = 300;
					y4 = 350;
					x5 = 400; 
					y5 = 350;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("WON 200 = 8-11\n");
					temp = i + 1;
					return 200;
					break;
				case 12:
					draw[3].x = 250;
					draw[3].y = 400;
					x4 = 300;
					y4 = 450;
					x5 = 300;
					y5 = 450;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x4, y4, x5, y5);
					printf("8-12\n");
					temp = i + 1;
					return 200;
					break;
				}
			}
		}
		/*
		if (temp == 9)
		{
			if (i > 12 && i < 16 && number == array[i])
			{

				switch (i + 1)
				{
				case 13:
					x5 = 400;
					y5 = 150;
					x6 = 475;
					y6 = 150;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4); 
					SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
					printf("9-13\n");
					temp = i + 1;
					return 200;
					break;
				case 14:
					x5 = 400;
					y5 = 250;
					x6 = 475;
					y6 = 250;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
					printf("9-14\n");
					temp = i + 1;
					return 200;
					break;
				}
			}
		}
		if (temp == 10)
		{
			if (i > 12 && i < 16 && number == array[i])
			{
				switch (i + 1)
				{
				case 13:
					x5 = 400;
					y5 = 150;
					x6 = 475;
					y6 = 150;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
					printf("WON 100\n");
					return 200;
					break;
				case 14:
					x5 = 400;
					y5 = 250;
					x6 = 475;
					y6 = 250;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
					printf("Won 100\n");
					return 200;
					break;
				case 15:
					x5 = 400;
					y5 = 350;
					x6 = 475;
					y6 = 350;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
					printf("Won 100\n");
					return 200;
					break;
				}
			}
		}
		if (i > 12 && i < 16 && number == array[i] && temp == 11)
		{
			switch (i + 1)
			{
			case 14:
				x5 = 400;
				y5 = 250;
				x6 = 475;
				y6 = 250;
				SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
				SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
				SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
				SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
				SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
				printf("Won 100\n");
				return 200;
				break;
			case 15:
				x5 = 400;
				y5 = 350;
				x6 = 475;
				y6 = 350;
				SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
				SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
				SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
				SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
				SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
				printf("Won 100\n");
				return 200;
				break;
			case 16:
				x5 = 400;
				y5 = 450;
				x6 = 475;
				y6 = 450;
				SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
				SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
				SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
				SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
				SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
				printf("Won 100\n");
				return 200;
				break;
			}
		}
		if (temp == 12)
		{
			if (i > 12 && i < 16 && number == array[i])
			{
				switch (i + 1)
				{
				case 15:
					x5 = 400;
					y5 = 350;
					x6 = 475;
					y6 = 350;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
					printf("Won 100\n");
					return 200;
					break;
				case 16:
					x5 = 400;
					y5 = 450;
					x6 = 475;
					y6 = 450;
					SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
					SDL_RenderDrawLine(Game::renderer, x1, y1, x2, y2);
					SDL_RenderDrawLine(Game::renderer, x2, y2, x3, y3);
					SDL_RenderDrawLine(Game::renderer, x3, y3, x4, y4);
					SDL_RenderDrawLine(Game::renderer, x5, y5, x6, y6);
					printf("Won 100\n");
					return 200;
					break;
				}
			}
		}
		*/
	}


	

	return 0;
}


int spin_rows(SDL_Texture *sprite_texture[14], SDL_Texture *font_texture, int total)
{
	int won = 0;
	int pos1_x = 50;
	int pos1_y = 100;
	
	int array1[7] = { 0, 1, 2, 3, 4, 5, 6 };
	int array2[7] = { 0, 2, 4, 6, 1, 3, 5 };
	int array3[7] = { 6, 3, 0, 4, 1, 5, 2 };
	int array4[7] = { 5, 1, 4, 0, 3, 6, 2 };
	
	/*
	int array1[7] = { 0, 1, 2, 3, 0, 1, 2 };
	int array2[7] = { 0, 2, 4, 0, 2, 4, 0 };
	int array3[7] = { 6, 3, 0, 4, 1, 5, 2 };
	int array4[7] = { 0, 1, 2, 3, 0, 2, 4 };
	*/
	int size = 16;

	int random = random_figure();

	SDL_Rect draw[21];
	for (int i = 0; i < 21; i++)
	{
		draw[i].w = 100;
		draw[i].h = 100;
	}

	int number_of_rows = 4;
	int number_of_columns = 3;
	int n;

	int count = 0;

	int save_winner[16];

	n = rand() % 7;
	for (int i = 0; i < number_of_rows; i++)
	{
		draw[i].x = pos1_x;
		draw[i].y = pos1_y;
		SDL_RenderCopyEx(Game::renderer, sprite_texture[array1[n]], NULL, (const SDL_Rect*)&draw[i], 0, NULL, SDL_FLIP_NONE);
		save_winner[count++] = array1[n];
		n = n + 1;
		pos1_y += 100 + 1;
		if (n > 6) n = 0;
	}
	pos1_y = 100;
	n = rand() % 7;

	for (int i = 0; i < number_of_rows; i++)
	{
		draw[i].x = pos1_x + 100 + 1;
		draw[i].y = pos1_y;
		SDL_RenderCopyEx(Game::renderer, sprite_texture[array2[n]], NULL, (const SDL_Rect*)&draw[i], 0, NULL, SDL_FLIP_NONE);
		save_winner[count++] = array2[n];
		n = n + 1;
		//printf(" n:%d i:%d", n, i);
		pos1_y += 100 + 1;
		if (n > 6) n = 0;
	}

	n = rand() % 7;
	pos1_y = 100;
	for (int i = 0; i < number_of_rows; i++)
	{
		draw[i].x = pos1_x + 200 + 2;
		draw[i].y = pos1_y;
		SDL_RenderCopyEx(Game::renderer, sprite_texture[array3[n]], NULL, (const SDL_Rect*)&draw[i], 0, NULL, SDL_FLIP_NONE);
		save_winner[count++] = array3[n];
		n = n + 1;
		//printf(" n:%d i:%d", n, i);
		pos1_y += 100 + 1;
		if (n > 6) n = 0;
	}
	/*
	n = rand() % 7;
	pos1_y = 100;
	for (int i = 0; i < number_of_rows; i++)
	{
		draw[i].x = pos1_x + 300 + 3;
		draw[i].y = pos1_y;
		SDL_RenderCopyEx(Game::renderer, sprite_texture[array4[n]], NULL, (const SDL_Rect*)&draw[i], 0, NULL, SDL_FLIP_NONE);
		save_winner[count++] = array4[n];
		n = n + 1;
		//printf(" n:%d i:%d", n, i);
		pos1_y += 100 + 1;
		if (n > 6) n = 0;
	}
	*/
	int value=0;
	int number_winner = 0;
	for (int i = 0; i < size; i++)
	{
		int countto4 = 0;
		for (int j = i + 1; j < size; j++)
		{
			if (save_winner[i] == save_winner[j])
			{
				countto4++;
				if (countto4 == 2)
				{
					//printf("Won: +200 %d\n", save_winner[i]);
					countto4 = 0;
					number_winner = save_winner[i];
					Winner(sprite_texture, save_winner, number_winner);
					value = draw_lines(save_winner, number_winner);
					




					return value;
					//total += won;

				}
			}

		}
		

	}



	

	if (value > 0)
	{
		SDL_AudioSpec wavSpec;
		Uint32 wavLength;
		Uint8 *wavBuffer;
		SDL_LoadWAV(songwin, &wavSpec, &wavBuffer, &wavLength);
		SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
		int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
		SDL_PauseAudioDevice(deviceId, 0);
		SDL_FreeWAV(wavBuffer);

	}

	total += won;
	
	print_won(font_texture, value);
	print_coins(font_texture, total);
	return total;
}








int main(int argc, char **argv)
{
	int total_coins = 1000;

	SDL_Init(SDL_INIT_AUDIO);// ini audio
	SDL_AudioSpec wavSpec;
	Uint8 *wavBuffer;
	Uint32 wavLength;
	SDL_AudioDeviceID deviceId;


	int sdlresult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlresult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	prev_key_state[256];
	keys = (unsigned char*)SDL_GetKeyboardState(NULL);

	const int n_imagenes = 15;
	const char *imagenes[n_imagenes];
	
	SDL_Surface *sprite_surface[n_imagenes];
	SDL_Texture *sprite_texture[n_imagenes];
;
	const char *font_filename = "font_sheet.png";

	imagenes[0] = "CIGARRETE.png";
	imagenes[1] = "heart_1.jpg";
	imagenes[2] = "cherry2.png";
	imagenes[3] = "WATERMELON.jpg";
	imagenes[4] = "CHARMANDER.jpg";
	imagenes[5] = "fox.png";
	imagenes[6] = "coin.png";

	imagenes[7] = "CIGARRETE_1.png";
	imagenes[8] = "heart.jpg";
	imagenes[9] = "cherry2_1.png";
	imagenes[10] = "WATERMELON_1.jpg";
	imagenes[11] = "CHARMANDER_1.jpg";
	imagenes[12] = "fox_1.png";
	imagenes[13] = "coin_1.png";

	SDL_Window *window = SDL_CreateWindow("ALE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::screen_width, Game::screen_height, SDL_WINDOW_SHOWN);
	Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	for (int i = 0; i <= 13; i++)
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

	unsigned int last_text_change_time = SDL_GetTicks();
	unsigned char prev_key_state[256];
	unsigned char *keys = (unsigned char*)SDL_GetKeyboardState(NULL);

	int pos1_x = 50; // columns
	int pos1_y = 100; // rows
	int won = 0;

	unsigned int current_time = SDL_GetTicks();

	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);	// set color to black
	SDL_RenderClear(Game::renderer);	//clear screen with black
	print_coins(font_texture, total_coins);
	print_won(font_texture, 0);
	init_position(sprite_texture);
	//print_buycoins(font_texture);
	print_play(font_texture);
	SDL_RenderPresent(Game::renderer);
	bool prev_A = false;
	bool press_A = false;
	bool pressed_mouse = false;
	bool prev_pressed_mouse = false;
	bool pressed= false;

	bool done = false;
	while (!done)
	{
		memcpy(prev_key_state, keys, 256);
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				done = true;
			}
		}
		
		int cost_to_play = -50;
		int success;
		SDL_PumpEvents();
		
	
		if (prev_pressed_mouse == false)pressed_mouse= SDL_GetMouseState(NULL, NULL);
		if (pressed_mouse & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			SDL_Log("SPIN");
			total_coins += cost_to_play;
			pressed = true;
			prev_pressed_mouse = true;

		}

		// GET SPACE BAR 
		if (keys[SDL_SCANCODE_SPACE])
		{
			printf("\n Cost to Play -50\n");
			pressed = true;
			total_coins += cost_to_play;

		}
		if (prev_A == false) press_A = keys[SDL_SCANCODE_A];

		if (press_A == true && prev_A== false)
		{
			printf("\n 1000 coins added\n");
			total_coins += 1000;
			print_coins(font_texture, total_coins);
			prev_A = true;

		}
		
		

		//int save_won[16];

		Uint32 timeout = SDL_GetTicks() + 3000; // time spining
		

		while (pressed)
		{
			if (SDL_LoadWAV(songname, &wavSpec, &wavBuffer, &wavLength) == NULL)
			{
				fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
			}
			else
			{
				deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
				// play audio
				success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
				SDL_PauseAudioDevice(deviceId, 0);
				SDL_FreeWAV(wavBuffer);
			}

		


			while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
			{
				SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
				SDL_RenderClear(Game::renderer);
				init_position(sprite_texture);
				print_coins(font_texture, total_coins);
				SDL_RenderPresent(Game::renderer);
				pressed = false;
				//printf("im doing this\n");

				SDL_PumpEvents();
				if (pressed_mouse == true && prev_pressed_mouse == false)
				{
					SDL_Log("STOP PLEASE");
					prev_pressed_mouse = true;
					pressed = false;
					timeout = SDL_GetTicks();
					if (SDL_LoadWAV(songbip, &wavSpec, &wavBuffer, &wavLength) == NULL) {
						fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
					}
					else {

						deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
						// play audio
						success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
						SDL_PauseAudioDevice(deviceId, 0);
						SDL_FreeWAV(wavBuffer);
					}
				}
			}


			if (SDL_LoadWAV(songbip, &wavSpec, &wavBuffer, &wavLength) == NULL) {
				fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
			}
			else {

				deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
				// play audio
				success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
				SDL_PauseAudioDevice(deviceId, 0);
				SDL_FreeWAV(wavBuffer);
			}
			SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
			SDL_RenderClear(Game::renderer);
			int total_spin = spin_rows(sprite_texture, font_texture, total_coins);
			//spin_rows2(sprite_texture, font_texture, total_coins, &save_won);
			total_coins += total_spin;
			print_won(font_texture, total_spin);
			printf("Total coins: %d\n", total_coins);
			print_coins(font_texture, total_coins);
			print_play(font_texture);
			//print_buycoins(font_texture);
			SDL_RenderPresent(Game::renderer);

			prev_A = false;
			press_A = false;
			pressed = false;
			prev_pressed_mouse = false;
		}



	}


	SDL_CloseAudioDevice(deviceId);
	SDL_Quit();
	return 0;
}
			
		