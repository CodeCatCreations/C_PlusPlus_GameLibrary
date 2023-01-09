#include "Constants.h" //gResPath-contains path to your resources.
#include "System.h"
#include <iostream>
#include <SDL2/SDL.h>

namespace cwing {

	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		// win = SDL_CreateWindow("Cwing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, 0);
		win = SDL_CreateWindow("GameDemo", 20, 20, 700, 500, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
		TTF_Init();
		font = TTF_OpenFont((constants::gResPath + "fonts/arial.ttf").c_str(), 36);
		// Path to your own 'sounds' folder!

		music = Mix_LoadWAV((constants::gResPath + "sounds/bgTrack.mp3").c_str());
		Mix_VolumeChunk(music, 40);
		Mix_PlayChannel(-1, music, -1);
	}

	System::~System() {
		Mix_FreeChunk(music);
		Mix_CloseAudio();
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	SDL_Renderer* System::get_ren() const {
		return ren;
	}

	TTF_Font* System::get_font() const {
		return font;
	}

	SDL_Window* System::get_win() const {
		return win;
	}

	int System::getWindowWidth() const {
		int w, h;
		SDL_GetWindowSize(System::win, &w, &h);
		return w;
	}
	int System::getWindowHeight() const {
		int w, h;
		SDL_GetWindowSize(System::win, &w, &h);
		return h;
	}

	System sys; // Statiskt globalt objekt (definierad utanför funktioner.)

}