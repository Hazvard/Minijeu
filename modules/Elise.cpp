#include "Elise.hpp"
 
using namespace std;
using namespace sf;
 
//Constructeur ------------------------------------------------------------------------------
Elise::Elise(){

	// eliseSprite.setScale(sf::Vector2f(0.5, 0.5));
	// eliseSprite.setPosition(sf::Vector2f(10.f, 50.f));

    //Chargement des ressources graphiques

	if (!eliseMarcheTexture.loadFromFile("ressources/Elise.png")){
	    std::cout <<"Erreur de load de la texture" << std::endl;
	}else{
		eliseSprite.setTexture(eliseMarcheTexture); // On lie le sprite aavec la texture
		eliseSprite.setScale(2.3, 2.3) ; // On diminue sa taille pour pas le faire dépasser
	}
    

    // Initialisation des variables
    int stamina = 100 ;

    int frameNumber = frameTimer = frameMax = abscisse = ordonnee = 0;
	elise = true ;

}
 
//Fonctions ---------------------------------------------------------------------------------

int Elise::getAbscisse(){
    return abscisse ;
}

int Elise::getOrdonnee(){
    return ordonnee ;
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

int Elise::getDirX(){
	return dirX;
}

int Elise::getDirY(){
	return dirY;
}

void Elise::setAbscisse(int valeur){
    abscisse = valeur ;
}

void Elise::setOrdonnee(int valeur){
    ordonnee = valeur ;
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

void Elise::setDirX(int val){
	dirX = val;
}

void Elise::setDirY(int val){
	dirY = val;
}

void Elise::changementDeHeros(bool b){
	if(b){
		if (!eliseMarcheTexture.loadFromFile("ressources/Elise.png")){
	    	std::cout <<"Erreur de load de la texture" << std::endl;
		}else{
			eliseSprite.setTexture(eliseMarcheTexture); // On lie le sprite aavec la texture
			eliseSprite.setScale(2.3, 2.3) ; // On diminue sa taille pour pas le faire dépasser
		}
	}else{
		if (!eliseMarcheTexture.loadFromFile("ressources/Chloe.png")){
	    	std::cout <<"Erreur de load de la texture" << std::endl;
		}else{
			eliseSprite.setTexture(eliseMarcheTexture); // On lie le sprite aavec la texture
			eliseSprite.setScale(2.3, 2.3) ; // On diminue sa taille pour pas le faire dépasser
		}
	}
}

void Elise::initialize(Map &map){

    // Au départ, Elise regarde à droite en animation neutre
    sensSprite = DROITE ;
    etat = NEUTRE ;

    // On commence à la frame 0
    frameNumber = 0 ;

    // La valeur entre deux deux frames
    frameTimer = TEMPS_ENTRE_DEUX_FRAMES ;

    // Le maximum de case de frames de l'image
    frameMax = MAXIFRAME ;

    abscisse = map.getBeginX();
    ordonnee = map.getBeginY();

    // Initialise la caméra
    map.setDebutAbscisse(0) ;
    map.setDebutOrdonne(0);

    w = ELISE_WIDTH ;
    h = ELISE_HEIGTH ;

	mort = 0 ;

	reflexion = true ;
	sensSprite = GAUCHE ;

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

    // On place le joueur sur la map

    eliseSprite.setPosition(Vector2f(abscisse - map.getDebutAbscisse(), ordonnee - map.getDebutOrdonne()));
	if(etat == MARCHE){
		if( sensSprite == GAUCHE ){ // On affiche differement le personnage s'il regarde à gauche ou droite

			eliseSprite.setTextureRect(sf::IntRect(frameNumber * ELISE_WIDTH, 3 * ELISE_HEIGTH, ELISE_HEIGTH, ELISE_WIDTH )) ;  // Je avoir problème ici -------------------------------------------
			window.draw(eliseSprite) ;
		}
		else if(sensSprite == DROITE){

			eliseSprite.setTextureRect(sf::IntRect(frameNumber * ELISE_WIDTH, 2 * ELISE_HEIGTH, ELISE_HEIGTH, ELISE_WIDTH )) ; 
			window.draw(eliseSprite) ;

		}else if(sensSprite == HAUT){

			eliseSprite.setTextureRect(sf::IntRect(frameNumber * ELISE_WIDTH, 1 * ELISE_HEIGTH, ELISE_HEIGTH, ELISE_WIDTH )) ; 
			window.draw(eliseSprite) ;

		}else if( sensSprite == BAS){

			eliseSprite.setTextureRect(sf::IntRect(frameNumber * ELISE_WIDTH, 0 * ELISE_HEIGTH, ELISE_HEIGTH, ELISE_WIDTH )) ; 
			window.draw(eliseSprite) ;
		}
	}else{
		eliseSprite.setTextureRect(sf::IntRect(frameNumber * ELISE_WIDTH, 4 * ELISE_HEIGTH, ELISE_HEIGTH, ELISE_WIDTH )) ; 
			window.draw(eliseSprite) ;
	}
    
}


void Elise::centerScrolling(Map &map){  //pas updaté mais normalement c'est le meme que ans la V1 du jeu

	int centrex = (*this).getWidth()/2 + (*this).getAbscisse(); //centre d'élise
	int centrey = (*this).getHeight()/2 + (*this).getOrdonnee();
	int minx = LIMITE_ABSCISSE + map.getDebutAbscisse();  //Constantes d'élise, voir hpp
	int maxx = minx + LIMITE_WIDTH;
	int miny = LIMITE_ORDONNEE + map.getDebutOrdonne();

	int maxy = miny + LIMITE_HEIGHT;

	//centrage de la map sur x
	if(centrex < minx){
		map.setDebutAbscisse(map.getDebutAbscisse() - SCROLL_DISTANCE);
	}
	else if(centrex > maxx){
		map.setDebutAbscisse(map.getDebutAbscisse() + SCROLL_DISTANCE);
	}

	//si on arrive en bout de map sur x
	if (map.getDebutAbscisse() < 0){
		map.setDebutAbscisse(0);
	}
	else if(map.getMaxX() <= map.getDebutAbscisse() + SCREEN_WIDTH){
		map.setDebutAbscisse(map.getMaxX() - SCREEN_WIDTH);
	}

	//meme chose pour y
	if(centrey < miny){
		map.setDebutOrdonne(map.getDebutOrdonne() - SCROLL_DISTANCE);
	}
	else if(centrey > maxy){
		map.setDebutOrdonne(map.getDebutOrdonne() + SCROLL_DISTANCE);
	}

	if (map.getDebutOrdonne() < 0){
		map.setDebutOrdonne(0);
	}
	else if(map.getMaxY() <= map.getDebutOrdonne() + SCREEN_HEIGHT){
		map.setDebutOrdonne(map.getMaxY() - SCREEN_HEIGHT);
	}
}

void Elise::collisionObjets(Map &map){

	int xg, xd, yh, yb; //coordonnées de test pour voir quelles tiles touche elise : gauche, droite, haut, bas
	bool okay = true; //controle de la boucle while
	int i = TILE_SIZE; //itérateur pour parcourir la boucle, à modifier selon la taille d'elise: on vérifie les collisions par ligne de tiles, et le i sert à changer de ligne

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
		xg = ((*this).getAbscisse() + (*this).getDirX())/TILE_SIZE;
		xd = ((*this).getAbscisse() + (*this).getDirX() + (*this).getWidth() - 1)/TILE_SIZE; //si c'est kaputt, enlever le -1
		yh = (*this).getOrdonnee()/TILE_SIZE;
		yb = ((*this).getOrdonnee() + i - 1)/TILE_SIZE; //le i sert à descendre d'une ligne de tiles

		//on checke pas si on est dans les limites de l'écran, c'est pour les losers ca

		if((*this).getDirX() >0){
			if(map.getTile(yh, xd) == DUR || map.getTile(yb, xd) == DUR){
				//on colle elise à la tile qu'on peut pas traverser
				(*this).setAbscisse(xd*TILE_SIZE); //revient à ajouter dirX + w - 1 à x
				(*this).setAbscisse((*this).getAbscisse()- (*this).getWidth() -1);
				(*this).setDirX(0);
			}
		}
		else if((*this).getDirX()<0){
			if(map.getTile(yh, xg) == DUR || map.getTile(yb, xg) == DUR){
				(*this).setAbscisse((xg + 1)*TILE_SIZE); //revient à ajouter dirX + 1
				(*this).setDirX(0);
			}
		}

		okay = !(i == h); //sortie de la boucle si on a vérifié toutes les tiles

		i = i+ TILE_SIZE;
		if(i>(*this).getHeight())
			i=(*this).getHeight();
	}

	//meme chose pour l'axe y
	i = TILE_SIZE;
	okay = true;
	while(okay){

		xg = (*this).getAbscisse()/TILE_SIZE;
		xd = ((*this).getAbscisse()+i) / TILE_SIZE;
		yh = ((*this).getOrdonnee() + (*this).getDirY())/TILE_SIZE;
		yb = ((*this).getOrdonnee() + (*this).getDirY() +(*this).getHeight()) / TILE_SIZE;

		if((*this).getDirY()>0){ //attention, vers le bas!
			if(map.getTile(yb, xd) == DUR || map.getTile(yb, xg) == DUR){
				(*this).setOrdonnee(yb*TILE_SIZE);
				(*this).setOrdonnee((*this).getOrdonnee() - (*this).getHeight() - 1); //evient à faire y = y -1
				(*this).setDirY(0);
			}
		}
		else if((*this).getDirY()<0){ //vers le haut
			if(map.getTile(yh, xd) == DUR || map.getTile(yh, xg) == DUR){
				(*this).setOrdonnee((yh + 1) *TILE_SIZE);
				(*this).setDirY(0);
			}
		}
		okay = !(i==w);
		i = i+ TILE_SIZE;
		if(i>(*this).getWidth())
			i = (*this).getWidth();
	}


	//application des mouvements, si ils ont été corrigés ils seront nuls
	(*this).setAbscisse((*this).getAbscisse() + (*this).getDirX());
	(*this).setOrdonnee((*this).getOrdonnee() +(*this).getDirY());

	//correction des dépassements
	if((*this).getAbscisse()<0)
		(*this).setAbscisse(0);
	if ((*this).getAbscisse() + (*this).getWidth() >= map.getMaxX())
		(*this).setAbscisse(map.getMaxX() - (*this).getWidth());
	if((*this).getOrdonnee()<0)
		(*this).setOrdonnee(0);
	if ((*this).getOrdonnee() + (*this).getHeight() > map.getMaxY())
		(*this).setOrdonnee(map.getMaxY() - (*this).getHeight());
}

void Elise::update(Entree &entree, Map &map){

	if(entree.getswitchSkin()){
		changementDeHeros(entree.getElise()) ;
	}

	if(!mort){ //si on est pas morts

		if(!entree.getMenu()){

			(*this).setDirX(0);
			(*this).setDirY(0);

			if(entree.getTouche().haut){
				(*this).setDirY(-ELISE_SPEED);
				sensSprite = HAUT;

				// //on checke si on doit initiliser l'animation
				if(etat != MARCHE){
					etat = MARCHE;
				}
			}
			if(entree.getTouche().bas){
				(*this).setDirY(ELISE_SPEED);
				sensSprite = BAS;

				// //on checke si on doit initiliser l'animation
				if(etat != MARCHE){
					etat = MARCHE;
				}
			}

			if(entree.getTouche().droite){
				(*this).setDirX(ELISE_SPEED);
				sensSprite = DROITE;

				// //on checke si on doit initiliser l'animation
				if(etat != MARCHE){
					etat = MARCHE;
				}
			}
			if(entree.getTouche().gauche){
				(*this).setDirX(-ELISE_SPEED);
				sensSprite = GAUCHE;

				// //on checke si on doit initiliser l'animation
				if(etat != MARCHE){
					etat = MARCHE;
				}
			}

			if(!entree.getTouche().droite && !entree.getTouche().gauche && !entree.getTouche().bas && !entree.getTouche().haut){ //si rien n'est appuyé (ou alors une autre touche que celles de direction)
				if(etat != NEUTRE){
					etat = NEUTRE;
					frameNumber = 0; //ca sert un peu a rien comme il y a que 2 frames mais osef
					frameTimer = TEMPS_ENTRE_DEUX_FRAMES;
					frameMax = MAXIFRAME;
				}
			}
			centerScrolling(map);
			collisionObjets(map) ;
		}
	}
	
	else{ //Si on est mouru
		mort = 0; //on ressucite
		map.changeLevel(); //reload du niveau
		initialize(map);
	}
}