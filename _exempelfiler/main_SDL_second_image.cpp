//
//  sdl2_second
//  

#include <iostream>
#include <string>
#include "Constants.h" //gResPath-contains the path to your resources.

// Alla dessa SDL inkluderingsfiler används inte i detta testprogram.
// Bifogas endast för test av SDL installation! 

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_mixer.h> 
#include <SDL2/SDL_ttf.h>
#define FPS 60

/*  PATH TO YOUR RESOURCE FOLDER 'resources'
*   'gResPath' is a global constant defined in "Constants.h", 
*   representing the relative path to your resource folders as a string,
*   i.e. ' const std::string gResPath = "../../resources/" '
*   Use it through its namespace, 'constants::gResPath'.
*
*   Change to your own path if you choose a different approach!
*   Absolut Path(Second choice)
*   gResPath = "/Users/kjellna/dev/cpp/sdl2_second/resources/";
*
*   If you need to copy your 'resources' folder into directory
*   '/build/debug/', in that case change gResPath="./resources/"
*/

//#define FPS 60


int main(int argc, char* argv[]) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{ std::cout << "Error SDL2 Initialization : " << SDL_GetError(); return EXIT_FAILURE; }

	if (TTF_Init() < 0)
	{ std::cout << "Error SDL_ttf Initialization : " << SDL_GetError(); return EXIT_FAILURE; }

	if (Mix_OpenAudio ( 22050, AUDIO_S16SYS, 2, 4096) != 0){
		std::cout << "Error Audio Initialization" << std::endl;
	}

	// Getting music file
	Mix_Chunk* musik = Mix_LoadWAV((constants::gResPath + "/sounds/jump.mp3").c_str());

	// Creating window and renderer
	SDL_Window* window 		= SDL_CreateWindow("Window", 100, 50, 800, 600, 0);
	SDL_Renderer* renderer 	= SDL_CreateRenderer(window, -1, 0);

	// Creating background surface and texture
	SDL_Surface* bg_sur = IMG_Load( (constants::gResPath + "images/bg.jpg").c_str() );
	SDL_Texture* bg_tex = SDL_CreateTextureFromSurface(renderer, bg_sur);
	SDL_FreeSurface(bg_sur);

	// Creating top surface and texture
	SDL_Surface* cat_sur = IMG_Load((constants::gResPath + "images/cats.jpeg").c_str() );
	Uint32 white = SDL_MapRGB(cat_sur->format, 255, 255, 255); // make white transparent
	SDL_SetColorKey(cat_sur, SDL_TRUE, white); // set transparent white to surface
	SDL_Texture* cat_tex = SDL_CreateTextureFromSurface(renderer, cat_sur);	
	SDL_Rect cat_rect = {88, 333, (cat_sur->w)/10, (cat_sur->h)/10}; 
	SDL_FreeSurface(cat_sur);

	std::cout << "End Program using the application\'s windows menu \"quit\" or just close the window!" << std::endl;

	// Loop till dess att programmet avslutas!
	bool running = true;
	bool drag = false;
	const int tickInterval = 1000 / FPS;
	Mix_PlayChannel(-1, musik, -1);

	while (running) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type){
				case SDL_QUIT: 
					running = false; 
					break;
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym){
						case SDLK_UP:
							cat_rect.y -= 5; 
							musik->volume += 2;
							break;
						case SDLK_DOWN: 
							cat_rect.y += 5; 
							musik->volume -= 2;
							break;
						case SDLK_LEFT:
							cat_rect.x -= 5; break;
						case SDLK_RIGHT: 
							cat_rect.x += 5; break;
					} break; 
				case SDL_MOUSEBUTTONDOWN: {
					SDL_Point p = {e.button.x, e.button.y};
					if (SDL_PointInRect(&p, &cat_rect)){
						drag = true;
					}
				} break;
				case SDL_MOUSEBUTTONUP:
					drag = false;
					break;
				case SDL_MOUSEMOTION:
					if (drag){
						cat_rect.x += e.motion.xrel;
						cat_rect.y += e.motion.yrel;
					} 
					break;
				default:
					break;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bg_tex, NULL, NULL);
		SDL_RenderCopy(renderer, cat_tex, NULL, &cat_rect);
		SDL_RenderPresent(renderer);

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0){
			SDL_Delay(delay);
		}
	}

	// Städa innan programmet avslutas!

	SDL_DestroyTexture(bg_tex);
	SDL_DestroyTexture(cat_tex);
	SDL_DestroyRenderer(renderer);
	Mix_FreeChunk(musik);
	SDL_DestroyWindow(window);

	TTF_Quit();
	SDL_Quit();
	Mix_CloseAudio();
	
	return EXIT_SUCCESS;
}