#include "main.hpp"

int main(int argc, char ** argv) {
	sf::RenderWindow renderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Elise's adventurs"); //fenetre utilisée pour le rendering
	sf::Time t2 = sf::milliseconds(10);
	sf::Clock clock; //on crée une horloge pour pouvoir attendre

	sf::Time attente = clock.getElapsedTime(); //on crée une mesure du temps écoulé

  //On limite à 60 image par secondes
	renderWindow.setFramerateLimit(60);

  //On active la synchro verticale
  renderWindow.setVerticalSyncEnabled(true);



  //Instanciation des classes
  
  // Ajouter la classe input / handleevent de Simon
  Entree entree;
  Carte map; // Nouvelle classe carte
  Elise  elise ;
  
 
  //On commence au premier niveau
  map.setLevel(2);
  map.changeLevel();
 
 // On initialise Elise
 elise.initialize(map) ;



  // Boucle de jeu
  while (renderWindow.isOpen()){
 
    // Gestion des inputs / handle event Par Simon
    entree.gestionEntrees(renderWindow);

    //Updates (besoin de handle event)
    maj(entree, map, elise);
 
    // Dessin - draw
    draw(renderWindow, map, elise);
    renderWindow.display();
  }
 
  // On quitte
  return 0;
 
}
 
 
 
//Fonction de mise à jour du jeu : gère la logique du jeu

void maj(Entree &entree, Carte &map, Elise &elise){
  //map.testDefilement(); // Défilement auto
  elise.update(entree, map) ;


}
 
 
 
//Fonction de dessin du jeu : dessine tous les éléments
void draw(RenderWindow &window, Carte &map, Elise &elise){
  //On efface tout
  window.clear();
 
  // Affiche la map de tiles
  map.draw(window);


  // On affiche Elise
  elise.drawElise(window, map);
 


  
}