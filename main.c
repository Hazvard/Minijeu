/**
 * \file main.c
 * \brief 
 * \author 
 * \version 
 * \date 
 */

#include <stdio.h>
#include <stdlib.h>
#include "Modules/graphics.h"
#include "Modules/world.h"
#include "Modules/player.h"




















/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main()
{

    //Initialisation de la fenêtre
    SDL_Window *window   = NULL;
    SDL_Renderer *renderer = NULL;

    init(&window, &renderer);
    SDL_SetWindowTitle(window, "Les aventure d'Elise");
    SDL_SetRenderDrawColor(renderer, 37, 126, 148, 255);



    while (1) { // main boucle de jeu
        SDL_Event event; // échape pour quitter
        if (SDL_PollEvent(&event) && (SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym)))
            break;
        refresh_graphics(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;































    // // Création de la fenètre
    // SDL_Renderer *renderer = NULL;
    // SDL_Window *window = NULL;

    // SDL_Event event;

    // SDL_SetMainReady();
    // init_sdl(&window, &renderer, SCREEN_WIDTH, SCREEN_HEIGHT);



    // while (1) { // Boucle de jeu


    //     SDL_Event event; // Fermeture de la fenêtre
    //     if (SDL_PollEvent(&event) && (SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym)))
    //         break; // quitte le jeu

            
    //    //refresh_graphics(renderer);
    // }



    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();



    // return 0;
}
