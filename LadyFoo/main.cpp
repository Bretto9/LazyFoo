/* 
 * File:   main.cpp
 * Author: JoseDavid
 *
 * Created on 13 de julio de 2014, 19:48
 */
#include <stdio.h>
#include <cstdlib>
#include <SDL2/SDL.h>

using namespace std;

// Ventana para renderizar
SDL_Window *gWindow = NULL;

// Superficie de la ventana
SDL_Surface *gScreenSurface = NULL;

// Superficie de la imagen
SDL_Surface *gHelloWorld = NULL;

// Inicializador
bool init();

//Cargador
bool loadMedia();

// Finalizador
void close();

/*
 * 
 */
int main(int argc, char** argv) {
    if(!init()){
        printf("Fallo al inicializar");
    } else {
        if(!loadMedia()){
            printf("Fallo al cargar imagen");
        } else {
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            
            SDL_UpdateWindowSurface(gWindow);
            
            SDL_Delay(3000);
        }
    }
    close();
    return 0;
}

bool init() {
    bool exito = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Ventana - SDL_Error: %s \n", SDL_GetError());
        exito = false;
    } else {
        gWindow = SDL_CreateWindow("T02", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window - SDL_Error: %s \n", SDL_GetError());
            exito = false;
        } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return exito;
}

bool loadMedia() {
    bool exito = true;

    gHelloWorld = SDL_LoadBMP("hello_world.bmp");
    if (gHelloWorld == NULL) {
        printf("IMAGEN - SDL_Error: %s\n", SDL_GetError());
        exito = false;
    }
    return exito;
}

void close() {
    // Destruir Imagen
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    //Destruir Ventana
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Finalizar SDL
    SDL_Quit();
}