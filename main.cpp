#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SFML/Graphics.hpp"
#include "modules/carte.hpp"
#include "modules/Elise.hpp"

using namespace sf; // Permet de ne pas écrire sf::
using namespace std;

// Taille de la fenêtre : 800x600 pixels
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char ** argv) {
	sf::RenderWindow renderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Elise's adventurs"); //fenetre utilisée pour le rendering
	sf::Time t2 = sf::milliseconds(10);
	sf::Clock clock; //on crée une horloge pour pouvoir attendre
	sf::Time attente = clock.getElapsedTime(); //on crée une mesure du temps écoulé
	renderWindow.setFramerateLimit(60);




  Elise  bout ;
  Carte fond1;
  


	while (renderWindow.isOpen()) {

        renderWindow.clear();
        fond1.drawBackground(renderWindow) ;
        bout.drawElise(renderWindow, static_cast<int> ( clock.getElapsedTime().asSeconds() * 8 ) % 8, 1 ) ;

		sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }

	


    



      

  
        renderWindow.display();	
    
	}
	return 0;
}