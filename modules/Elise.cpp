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
    map.setDebutAbscisse(0) ;
    map.setDebutOrdonne(0);

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




    // Fonction Simon
    void Elise::centerScrolling(Map &map){

	int colup = abscisse; //collision vers le haut : un perso est défini en haut à gauche, donc pas besoin d'offset
	int coldown = abscisse + h;
	int colleft = ordonne;
	int colright = ordonne + w;

	//si le player arrive sur le bord gauche de la map, on scrolle

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
	*/

	while(okay){

		//on reporte les mesures de position d'elise vers des mesures sur la map (conversion base pixel vers base ecran)
		xg = (x + dirX)/TILE_SIZE;
		xd = (x + dirX + w - 1)/TILE_SIZE; //si c'est kaputt, enlever le -1
		yh = y/TILE_SIZE;
		yb = (y + i - 1)/TILE_SIZE; //le i sert à descendre d'une ligne de tiles

	}

//A PARTIR D'ICI C'EST DE LA MERDE

	int zebi; //t'occupe pas, variable de controle




	//on ne teste pas si le player est dans les limites de l'écran, mais on pourrait

	//test pour aller vers la droite
	if (dirX > 0){

		if (map.getTile(bdy, bdx + dirX) == MUR || map.getTile(hgy, bdx + dirX) == MUR){ //si les deux tiles superposées à la droite sont des murs
			zebi = 0;
			dirX = 0;
			while(!(map.getTile(bdy, bdx + dirX) == MUR || map.getTile(hgy, bdx + dirX) == MUR)){  //on recherche la valeur de dirX pour se coller au mur
				dirX++;
				zebi++;
			}
			if(zebi != 0){  //pour bien s'assurer qu'on n'est pas dans le cas où le while n'a pas été fait
				dirX--; //au cas où
			}	
			okay = false; //ne pas appliquer le mouvement plus tard			
		}
	}

	//test pour aller vers la gauche
	if(dirX<0){

		if(map.getTile(bdy, hgx - dirX) == MUR || map.getTile(hgy, hgx - dirX) == MUR){
			zebi = 0;
			dirX == 0;
			while(!(map.getTile(bdy, hgx - dirX) == MUR || map.getTile(hgy, hgx - dirX) == MUR)){
				dirX--;
				zebi++;
			}
			if(zebi != 0){
				dirX++;
			}
			okay = false; //ne pas appliquer le mouvement plus tard	
		}
	}

	//test pour aller vers le haut    ON CONSIDERE QUE SES PIEDS DOIVENT TOUCHER LA TEXTURE MUR, DONC ON UTILISE LES MESURES DE Y DU BAS
	if(dirY<0){

		if(map.getTile(bdy - dirY, hgx) == MUR || map.getTile(bdy - dirY, bdx) == MUR){
			zebi = 0;
			dirY=0;
			while(!(map.getTile(bdy - dirY, hgx) == MUR || map.getTile(bdy - dirY, bdx) == MUR)){
				dirY--;
				zebi++;
			}
			if(zebi != 0){
				dirY++;
			}	
			okay = false; //ne pas appliquer le mouvement plus tard				
		}
	}

	//test pour aller vers le bas	ON CONSIDERE QUE ELISE PEUT PASSER DERRIERE LES OBSTACLES, POUR ETRE CACHÉE À UN RANG DE PIXEL PRES, DONC ON UTILISE LES MESURES DE Y DU BAS
	if(dirY>0){

		if(map.getTile(hgy + dirY, hgx) == MUR || map.getTile(hgy + dirY, bdx) == MUR){
			zebi = 0;
			dirY = 0;
			while(!(map.getTile(hgy + dirY, hgx) == MUR || map.getTile(hgy + dirY, bdx) == MUR)){
				dirY--;
				zebi++;
			}
			if(zebi != 0){
				dirY++;
			}	
			okay = false; //ne pas appliquer le mouvement plus tard				
		}
	}

	//on applique les mouvements si rien n'a été bloqué
	if(okay){
		abscisse +=  dirX;
		ordonne +=  dirY;
	}

	//on vérifie si on est au bord de la map
	if( abscisse < 0 ){
		abscisse = 0;
	}

	if( abscisse + w >=map.getMaxX()){
		abscisse = map.getMaxX() - w;
	}

 	if (ordonne < 0){
	y = 0;
	}
	
//  	if ( ordonne + h > map.getMaxY()){
// 	y = map.getMaxY() - h;
// 	}
// }