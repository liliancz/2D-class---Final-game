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


using namespace std;


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_AUDIO);

	SDL_AudioSpec wavSpec;
	Uint8* wavBuffer;
	Uint32 wavLength;


	SDL_LoadWAV("startsong.wav", &wavSpec, &wavBuffer, &wavLength);

	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	
	// play audio

	int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
	

	// keep application running long enough to hear the sound

	SDL_Delay(3000);
	// clean up

	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
	SDL_Quit();



	return 0;
}