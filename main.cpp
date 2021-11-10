#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SFML/Graphics.hpp"

int main(int argc, char ** argv) {
	sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "Testage SFML"); //fenetre utilisée pour le rendering
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


	while (renderWindow.isOpen()) {

        renderWindow.clear();

		sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }


        //Tentative de mouvement d'élise
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ //fleche gauche
            elise.move(sf::Vector2f(-5.f, 0.f));  //déplacement relatif à la position absolue
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ //fleche droite
            elise.move(sf::Vector2f(5.f, 0.f));  //vector (abscisse float ordonnée float)
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //fleche haut
            elise.move(sf::Vector2f(0.f, -5.f));  //ATTENTION Ordonnée orientée vers le bas
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ //fleche bas
            elise.move(sf::Vector2f(0.f, 5.f));  
        }


        //Texturage
        if(( static_cast<int> (clock.getElapsedTime().asSeconds()) %10) == 1){  //prévu pour 6 textures (60/6)
            elise.setTexture(texture1);
        }

        if(( static_cast<int> (clock.getElapsedTime().asSeconds()) %10) == 2){
            elise.setTexture(texture2);
        }

        //Affichage d'élise
        renderWindow.draw(elise);
        renderWindow.display();
    	
        /*
		while((static_cast<int>(attente.asSeconds())%2) == 0){
			renderWindow.clear();
			elise.setTexture(texture1);
			renderWindow.draw(elise);
			renderWindow.display();
			attente = clock.getElapsedTime();
		}

		while((static_cast<int>(attente.asSeconds())%2) != 0){
			renderWindow.clear();
			elise.setTexture(texture2);
			renderWindow.draw(elise);
			renderWindow.display();
			attente = clock.getElapsedTime();
		}	

        */
	}
	return 0;
}