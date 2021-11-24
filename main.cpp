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
  Map map; // Nouvelle classe carte
  Elise  elise ;
  Carte fond1; // Ancienne classe carte
  
 
  //On commence au premier niveau
  map.setLevel(2);
  map.changeLevel();
 
  // Boucle de jeu
  while (renderWindow.isOpen()){
 
    // Gestion des inputs / handle event Par Simon
    entree.gestionEntrees(renderWindow);

    //Updates (besoin de handle event)
    maj(entree, map);
 
    // Dessin - draw
    draw(renderWindow, map);
    //elise.drawElise(renderWindow, static_cast<int> ( clock.getElapsedTime().asSeconds() * 8 ) % 8, 1 ) ;
    renderWindow.display();
  }
 
  // On quitte
  return 0;
 
}
 
 
 
//Fonction de mise à jour du jeu : gère la logique du jeu

void maj(Entree &entree, Map &map){
  map.testDefilement(); // Défilement auto


}
 
 
 
//Fonction de dessin du jeu : dessine tous les éléments
void draw(RenderWindow &window, Map &map){
  //On efface tout
  window.clear();
 
  // Affiche la map de tiles : layer 2 (couche du fond)
  map.draw(2, window);
 
  // Affiche la map de tiles : layer 1 (couche active : sol, etc.)
  map.draw(1, window);
 
  // Affiche la map de tiles : layer 3 (couche en foreground / devant)
  map.draw(3, window);

  
}