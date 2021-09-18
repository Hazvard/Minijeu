/**
 * \file graphics.c
 * \author Demange Dan
 * \brief Gestion des ressources graphiques
 * \version 0.0
 * \date 
 */

#include "graphics.h"


//Les fonctions .

void refresh_graphics(SDL_Renderer *renderer){
    SDL_RenderClear(renderer); // Nettoie la fenêtre
    SDL_RenderPresent(renderer);

}

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height){


    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)) {
        fprintf(stderr, "Erreur initialisation de la SDL : %s", SDL_GetError());
        return -1;
    }

    if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, window, renderer)) {
        fprintf(stderr, "Erreur lors de la creation de l'image et du renderer : %s", SDL_GetError());
        return -1;
    }
    return 0;
} 

void init(SDL_Window **window, SDL_Renderer **renderer){
    init_sdl(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


}










