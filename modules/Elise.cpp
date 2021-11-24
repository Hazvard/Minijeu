#include "Elise.hpp"
 
using namespace std;
using namespace sf;
 
//Constructeur ------------------------------------------------------------------------------
Elise::Elise(){

	// eliseSprite.setScale(sf::Vector2f(0.5, 0.5));
	// eliseSprite.setPosition(sf::Vector2f(10.f, 50.f));

    //Chargement des ressources graphiques

    for(int i = 0 ; i < 8 ; i++){
	    if (!eliseMarcheTexture[i].loadFromFile("ressources/Elise_marche.png", sf::IntRect(320 * i, 0 , 320, 320))){
		    std::cout <<"Erreur de load de la texture" << std::endl;
	    }
    }
    
    for(int i = 0 ; i < 8 ; i++){
	    if (!eliseNeutreTexture[i].loadFromFile("ressources/Elise_neutre.png", sf::IntRect(320 * i, 0 , 320, 320))){
		    std::cout <<"Erreur de load de la texture" << std::endl;
	    }
    }

    // Initialisation des variables
    int stamina = 100 ;

    int frameNumber = frameTimer = frameMax = abscisse = ordonne = w = h = 0;


}
 
//Fonctions ---------------------------------------------------------------------------------

int Elise::getAbscisse(){
    return abscisse ;
}

int Elise::getOrdonne(){
    return ordonne ;
}

int Elise::getHeight(){
    return h ;
}

int Elise::getWidth(){
    return w ;
}

int Elise::getStamina(){
    return stamina ;
}

void Elise::setAbscisse(int valeur){
    abscisse = valeur ;
}

void Elise::setOrdonne(int valeur){
    ordonne = valeur ;
}

void Elise::setWidth(int valeur){
    w = valeur ;
}

void Elise::setHeight(int valeur){
    h = valeur ;
}

void Elise::setStamina(int valeur){
    stamina = valeur ;
}

void Elise::initialize(Map &map){

    // Au départ, Elise regarde à droite en animation neutre
    direction = RIGHT ;
    etat = NEUTRE ;

    // On commence à la frame 0
    frameNumber = 0 ;

    // La valeur entre deux deux frames
    frameTimer = TEMPS_ENTRE_DEUX_FRAMES ;

    // Le maximum de case de frames de l'image
    frameMax = 3 ;

    abscisse = map.getBeginX();
    ordonne = map.getBeginY();

    // Initialise la caméra
    map.setStartX(0) ;
    map.setStartY(0);

    w = ELISE_WIDTH ;
    h = ELISE_HEIGTH ;

}

void Elise::drawElise(sf::RenderWindow &window, Map &map){

    // On gère le décompte, s'il arrive à 0
    if ( frameTimer <= 0 ){
        // On le rénitialise
        frameTimer = TEMPS_ENTRE_DEUX_FRAMES ;

        // ON passe à la frame suivante
        frameNumber++ ;

        // Si on dépasse la frame maximum on repasse à le première
        if( frameNumber >= frameMax )
            frameNumber = 0 ;
    }
    // Sinon, on continue décompte
    else{
        if(etat != NEUTRE)
            frameTimer -= 1 + (enDeplacement * 2) ;
        else
            frameTimer --;
    }

    // On place le joueur correctement sur la map
    // truc de texture .setPosition(Vector2f(abscisse - map.getStartX(), ordonne - map.getStartY()));
}


void Elise::centerScrolling(Map &map){

	int centrex = w/2 + x; //centre d'élise
	int centrey = h/2 + y;
	int minx = LIMITE_ABSCISSE + map.getStartX();  //Constantes d'élise, voir hpp
	int maxx = minx + LIMITE_WIDTH;
	int miny = LIMITE_ORDONNE + map.getStartY();
	int maxy = miny + LIMITE_HEIGHT;

	//centrage de la map sur x
	if(centrex < minx){
		map.setStartX(map.getStartX() - SCROLL_DISTANCE);
	}
	else if(centrex > maxx){
		map.setStartX(map.getStartX() + SCROLL_DISTANCE);
	}

	//si on arrive en bout de map sur x
	if (map.getStartX() < 0){
		map.setStartX(0);
	}
	else if(map.getMaxX() <= map.getStartX() + SCREEN_WIDTH){
		map.setStartX(map.getMaxX() - SCREEN_WIDTH);
	}

	//meme chose pour y
	if(centrey < miny){
		map.setStartY(map.getStartY() - SCROLL_DISTANCE);
	}
	else if(centrey > maxy){
		map.setStartY(map.getStartY() + SCROLL_DISTANCE);
	}

	if (map.getStartY() < 0){
		map.setStartY(0);
	}
	else if(map.getMaxY() <= map.getStartY() + SCREEN_HEIGHT){
		map.setStartY(map.getMaxY() - SCREEN_HEIGHT);
	}
}

void Elise::collisionObjets(Map &map){

	int xg, xd, yh, yb; //coordonnées de test pour voir quelles tiles touche elise : gauche, droite, haut, bas
	bool okay = true; //controle de la boucle while
	i = TILE_SIZE; //itérateur pour parcourir la boucle, à modifier selon la taille d'elise: on vérifie les collisions par ligne de tiles, et le i sert à changer de ligne

	/*
	Sous entendu par la classe player:
	int x, y, w, h: position et taille d'élise
	int dirX, dirY : vecteurs de déplacement du sprite
	MUR et autres gros titres: attributs de la tile, on pourra les remplacer apres
	TILESIZE vient de elise.hpp
	*/

	//on boucle sur l'axe de x pour controler le contact des tiles
	while(okay){

		//on reporte les mesures de position d'elise vers des mesures sur la map (conversion base pixel vers base ecran)
		xg = (x + dirX)/TILE_SIZE;
		xd = (x + dirX + w - 1)/TILE_SIZE; //si c'est kaputt, enlever le -1
		yh = y/TILE_SIZE;
		yb = (y + i - 1)/TILE_SIZE; //le i sert à descendre d'une ligne de tiles

		//on checke pas si on est dans les limites de l'écran, c'est pour les losers ca

		if(dirX >0){
			if(map.getTile(yh, xd) == DUR || map.getTile(yb, xd) == DUR){
				//on colle elise à la tile qu'on peut pas traverser
				x = xd*TILE_SIZE; //revient à ajouter dirX + w - 1 à x
				x = x-w -1;
				dirX = 0;
			}
		}
		else if(dirX<0){
			if(map.getTile(yh, xg) == DUR || map.getTile(yb, xg) == DUR){
				x = (xg + 1)*TILE_SIZE; //revient à ajouter dirX + 1
				dirX = 0;
			}
		}

		okay = !(i == h); //sortie de la boucle si on a vérifié toutes les tiles
		i = i+ TILE_SIZE;
		if(i>h)
			i=h;
	}

	//meme chose pour l'axe y
	i = TILE_SIZE;
	okay = true;
	while(okay){

		xg = x/TILE_SIZE;
		xd = (x+i) / TILE_SIZE;
		yh = (y + dirY)/TILE_SIZE;
		yb = (y + dirY +h) / TILE_SIZE;

		if(dirY>0){ //attention, vers le bas!
			if(map.getTile(yb, xd) == DUR || map.getTile(yb, xg) == DUR){
				y = yb*TILE_SIZE;
				y = y - h - 1; //evient à faire y = y -1
				dirY = 0;
			}
		}
		else if(dirX<0){ //vers le haut
			if(map.getTile(yh, xd) == DUR || map.getTile(yh, xg) == DUR){
				y = (yh + 1) *TILE_SIZE;
				dirY = 0;
			}
		}
		okay = !(i==w);
		i = i+ TILE_SIZE;
		if(i>w)
			i = w;
	}

	//application des mouvements, si ils ont été corrigés ils seront nuls
	x = x + dirX;
	y = y +dirY;

	//correction des dépassements
	if(x<0)
		x = 0
	if (x + w >= map.getMaxX())
		x=map.getMaxX() - w;
	if(y<0)
		y = 0;
	if (y + h > map.getMaxY())
		y = map.getMaxY() - h;
}