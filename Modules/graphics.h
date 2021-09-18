/**
 * \file graphics.h
 * \brief Module contenant les ressources graphiques
 * \author DEMANGE Dan
 * \version 0.0
 * \date 16/09/2021
 */



#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768




//Definitions

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{

};




/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct sprite_s sprite_t;




// Fonctions
/**
* \brief fonction qui met à jour l'affichage
* \param renderer Vraiment besoin d'expliquer ?
*/
void refresh_graphics(SDL_Renderer *renderer);



/**
 * \brief La fonction initialise le jeu
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 */

void init(SDL_Window **window, SDL_Renderer **renderer);








#endif