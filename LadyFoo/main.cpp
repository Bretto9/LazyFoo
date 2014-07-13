/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main( int argc, char* args[] )
{
    SDL_Window *w = NULL;
    
    SDL_Surface *s = NULL;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL no se ha inicializado. SDL_Error: %s\n", SDL_GetError());
    } else{
        w = SDL_CreateWindow("Tutorial de SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(w == NULL){
            printf("No se pudo crear la ventana: SDL_ERROR: %s\n", SDL_GetError());
        } else {
            s = SDL_GetWindowSurface(w);
            
            SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 0x00, 0x00, 0x00));
            
            SDL_UpdateWindowSurface(w);
            
            SDL_Delay(5000);
            
            SDL_DestroyWindow(w);
            
            SDL_Quit();
            
        }
    }

	return 0;
}