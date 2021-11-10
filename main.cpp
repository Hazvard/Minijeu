#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SFML/Graphics.hpp"
#include "modules/carte.hpp"

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

	sf::Texture texture1; //on loade la texture de la premier frame
	if (!texture1.loadFromFile("ressources/test.png", sf::IntRect(0, 0, 20, 20))){
		std::cout <<"Erreur de load de la texture" << std::endl;
	}

	sf::Texture texture2; //on charge la texture de la seconde frame
	if (!texture2.loadFromFile("ressources/test.png", sf::IntRect(20, 0, 20, 20))){
		std::cout <<"Erreur de load de la texture" << std::endl;
	}

	sf::Sprite elise;  //sprite de la fille
	elise.setScale(sf::Vector2f(4.f, 4.f));
	elise.setPosition(sf::Vector2f(10.f, 50.f));


  Carte fond1;
  


	while (renderWindow.isOpen()) {

  
		sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }
        
        /*
        renderWindow.clear();
		elise.setTexture(texture1);
		renderWindow.draw(elise);
		renderWindow.display();
		//clock.restart();

		std::cout << "horloge:" << clock.GetElapsedTime() << std::endl;
*/

    

		while((static_cast<int>(attente.asSeconds())%2) == 0){
			renderWindow.clear();
			elise.setTexture(texture1);
      fond1.drawBackground(renderWindow) ;
			renderWindow.draw(elise);
			renderWindow.display();
			attente = clock.getElapsedTime();
		}

		while((static_cast<int>(attente.asSeconds())%2) != 0){
			renderWindow.clear();
      fond1.drawBackground(renderWindow) ;
			elise.setTexture(texture2);
			renderWindow.draw(elise);
      renderWindow.display();
			attente = clock.getElapsedTime();
		}	
    
	}
	return 0;
}