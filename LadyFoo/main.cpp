/* 
 * File:   main.cpp
 * Author: JoseDavid
 *
 * Created on 13 de julio de 2014, 20:19
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gHelloWorld = NULL;

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

    gHelloWorld = SDL_LoadBMP("x.bmp");
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

/*
 * 
 */
int main(int argc, char** argv) {
    bool quit = false;
    if (init()) {
        if (loadMedia()) {
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            SDL_Event e;
            while (!quit) {
                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
            }
        } else {
            cout << "Error al cargar imagen" << endl;
            return 1;
        }
    } else {
        cout << "Error al inicializar" << endl;
        return 1;
        
    }
    return 0;
}

