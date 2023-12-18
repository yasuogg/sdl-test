#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "functions.h"



#define SCREEN_WIDTH 0
#define SCREEN_HEIGHT 0

int main(int argc, char** argv){
SDL_Init(SDL_INIT_VIDEO);
SDL_Rect top,try_poss;
top.h=0;
top.w=0;
top.x=0;
top.y=0;
SDL_Surface *png_image=NULL,*test_text;
SDL_Color textColor = { 255, 255, 255 };
    SDL_Window *window=NULL;
    window= SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_FULLSCREEN_DESKTOP);
SDL_Surface *gScreenSurface = SDL_GetWindowSurface( window );






    //SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface *background=SDL_LoadBMP("images/STARTESPACE.bmp");
   png_image=IMG_Load("images/id.png");
    //OPEN FONT 
TTF_Init();
TTF_Font * font = TTF_OpenFont("fonts/ARIAL.TTF",65);
test_text=TTF_RenderText_Solid(font,"welcome", textColor);
//posistion 
try_poss.h=0;
try_poss.w=0;
try_poss.x=SCREEN_WIDTH/2;
try_poss.y=SCREEN_HEIGHT/2+50;
//
//music
//Mix_Chunk * pcwin=Mix_LoadWAV("pcwin.ogg");
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);
Mix_Music* music = Mix_LoadMUS("sounds/sound.ogg");
Mix_VolumeMusic(100);
Mix_PlayMusic(music,-1);

    bool running = true;
    while(running){

        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                    case SDL_KEYDOWN: 

                switch (event.key.keysym.sym)

                 {

                case SDLK_ESCAPE:
                running=0;
               break;
               case SDLK_SPACE:
               Mix_HaltMusic();
               break;
               case SDLK_F1:
               Mix_PlayMusic(music,-1);
               break;
       }

                default:
                    break;
            }
        }

        
        	//Apply the current image
				SDL_BlitSurface( background, NULL, gScreenSurface, NULL);
                SDL_BlitSurface( png_image, NULL, gScreenSurface,&top);
			        SDL_BlitSurface( test_text, NULL, gScreenSurface,&try_poss);

				//Update the surface
				SDL_UpdateWindowSurface( window );
    }
SDL_FreeSurface(background);
SDL_FreeSurface(png_image);
SDL_FreeSurface(test_text);
    Mix_FreeMusic(music);
    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}