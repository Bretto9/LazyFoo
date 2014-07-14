/* 
 * File:   main.cpp
 * Author: JoseDavid
 *
 * Created on 13 de julio de 2014, 20:19
 */

#include <cstdlib>
#include <SDL2/SDL.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    bool quit = false;
    
    SDL_Event e;
    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
    }
    return 0;
}

