#include "Carte.hpp"
 
using namespace std;
using namespace sf;

Carte::Carte(){
	if (!tileSetTexture.loadFromFile("ressources/tuiles.png")){
        cout << "Erreur durant le chargement de l'image du tileset." << endl;
    }
    else{
        tileSet.setTexture(tileSetTexture);
    }

    testdefil = 0;
    level = 1;
    debutAbscisse = 0;
    debutOrdonne = 0;
}


//GETTERS
int Carte::getBeginX(void) const { 
	return beginx; 
}

int Carte::getBeginY(void) const { 
	return beginy; 
}

int Carte::getDebutAbscisse(void) const { 
	return debutAbscisse; 
}

int Carte::getDebutOrdonne(void) const { 
	return debutOrdonne; 
}

int Carte::getMaxX(void) const { 
	return maxX; 
}

int Carte::getMaxY(void) const { 
	return maxY; 
}

int Carte::getTile(int y, int x) const { 
	return tile[y][x]; 
}

int Carte::getLevel(void) const { 
	return level; 
}

//SETTERS
void Carte::setLevel(int valeur) { 
	level = valeur; 
}

void Carte::setDebutAbscisse(int valeur) { 
	debutAbscisse = valeur; 
}

void Carte::setDebutOrdonne(int valeur) { 
	debutOrdonne = valeur; 
}

void Carte::setTile(int y, int x, int valeur) {   //sert possiblement à rien mais au moins c'est là
	tile[y][x] = valeur; 
}



//AUTRES FONCTIONS
void Carte::changeLevel(void){ // Récupère le nom de la map pour la charger
    string filename;
    filename = "cartes/map" + to_string(level) + ".txt";
    loadMap(filename);
}

void Carte::draw(RenderWindow &window){
	int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;

	mapX = debutAbscisse / TILE_SIZE; 
	x1 = (debutAbscisse % TILE_SIZE) * (-1); //coord de départ pour l'affichage de la map
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE); //coord de fin de la map, on fait expres de sortir de l'écran

	mapY = debutOrdonne / TILE_SIZE;
    y1 = (debutOrdonne % TILE_SIZE) * (-1);
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE); //le ? dit juste: si y !=0, alors y = tile size


    //dessin de la map ligne par ligne, par tranche de TILE_SIZE pixels
    for (y = y1; y < y2; y += TILE_SIZE){
        mapX = debutAbscisse / TILE_SIZE; //reinit de mapX au début de chaque ligne

        for (x = x1; x < x2; x += TILE_SIZE){
            a = tile[mapY][mapX]; //numéro de la tile sur le tileset
        
            /* Calcul pour obtenir son y (pour un tileset de 10 tiles
            par ligne, d'où le 10 */
            ysource = a / 5 * TILE_SIZE;
            xsource = a % 5 * TILE_SIZE;
        
            tileSet.setPosition(Vector2f(x, y));
            tileSet.setTextureRect(sf::IntRect(xsource, ysource, TILE_SIZE, TILE_SIZE)); //on resize la texture de l'objet tileset vers un carré contenant une seule tile
            window.draw(tileSet);

            mapX++;
        }
    
        mapY++;
        
    }
}

void Carte::testDefilement(void){ //ni changé ni testé mais ca devrait etre pareil qu'avant
    //Test de défilement de la map
    
    
    //On commence à faire défiler vers la droite (valeur == 0)
    if (testdefil == 0){
        //Tant que le début du blittage de la map est inférieur aux coordonnées
        //en X de la fin de la map (- la largeur de l'écran pour ne pas afficher
        //du noir), on fait défiler la map.
        if (debutAbscisse < maxX - SCREEN_WIDTH)
            //Vous pouvez changer cette valeur pour faire défiler la map plus ou moins vite
            debutAbscisse += 2;
        else
            testdefil = 1;
    }
    //Une fois au bout, on fait défiler vers le bas (valeur == 1)
    else if (testdefil == 1){
        if (debutOrdonne < maxY - SCREEN_HEIGHT)
            //Vous pouvez changer cette valeur pour faire défiler la map plus ou moins vite
            debutOrdonne += 2;
        else
            testdefil = 2;
    }

    //Une fois en bas, on fait défiler vers la gauche (valeur == 2)
    else if (testdefil == 2){
        if (debutAbscisse > 0)
            //Vous pouvez changer cette valeur pour faire défiler la map plus ou moins vite
            debutAbscisse -= 2;
        else
            testdefil = 3;
    }

    //Puis on remonte au point de départ (valeur == 3) et on recommence
    else if (testdefil == 3){
        if (debutOrdonne > 0)
            //Vous pouvez changer cette valeur pour faire défiler la map plus ou moins vite
            debutOrdonne -= 2;
        else
            testdefil = 0;
    }
}

void Carte::loadMap(string filename){   //PAS ENCORE FINI
    //flux de lecture
    fstream fin;

    //controle boucle
    int x = 0;
    int y = 0;
    
    maxX = 0;
    maxY = 0;
    
    
    vector < vector < int > > lignes;//vcteur de vecteur car 2D 
    vector < int > myVectData;//tete de lecture    
    string strBuf, strTmp;//que du temporaire, juste des buffers  
    stringstream iostr;//stringstream de gstion des chaines
    fin.open(filename, fstream::in); //ouverture fichier
    

    if (!fin.is_open()){
        cerr << "Erreur de chargement du fichier.\n";
        exit(1);
    }
    
    //On lit notre fichier jusqu'à la fin (eof = end of file)
    while (!fin.eof()){
        getline(fin, strBuf);//On récupère la ligne dans la chaîne strBuf

        if (!strBuf.size()) //ligne vide = on continue la boucle while
            continue;

        iostr.clear(); //reinitialisation du stream
        iostr.str(strBuf); //injection de la ligne récupérée précédemment dans le stream
    
        myVectData.clear(); //reinit du vecteur ligne
    
        //On boucle pour lire chaque numéro de tile du fichier map
        while (true){
            getline(iostr, strTmp, ' '); //recup du numéro de la tile, parsing avec un espace
            //On récupère ce numéro dans dans notre vecteur ligne
            myVectData.push_back(atoi(strTmp.c_str()));
    
            //Si on a fini, on quitte la boucle
            if (!iostr.good())  //la fonction good dit si le stream a rencontré des erreurs
                break;
        }
    
        //Si le vecteur ligne n'est pas vide, on l'envoie dans notre vecteur à 2 dimensions
        if (myVectData.size())
            lignes.push_back(myVectData); //ajoute la data à la fin du vecteur 2D
    }
    fin.close();
    
/*  si on en a besoin, ce sera les coordonnées de départ du perso, à afficher au début de la map
    beginx = lignes[0][0];
    beginy = lignes[0][1];
    */
    
    /*
    Si lecture des coordonnées personnage, on lit la premiere ligne de manière spécifique avant d'entrer dans la boucle générale
    for (x = 2; x < MAX_MAP_X+2; x++){
        tile[y][x - 2] = lignes[y][x];
    }
    */

    //double boucle de lecture du tableau ligne pour arriver à un tableau de tiles
    //pour l'instant on est sur un max de 80 * 80 tiles, voir hpp
    for (y = 0; y < MAX_MAP_Y; y++){
        for (x = 0; x < MAX_MAP_X; x++){
            tile[y][x] = lignes[y][x];
    
            //Réajustement de limites théoriques si elles sont dépassées
            if (tile[y][x] > 0){
                if (x > maxX){
                    maxX = x;
                }
                if (y > maxY){
                    maxY = y;
                }
            }
        }
    }    
    
    //On charge les variables supplémentaires
    y = MAX_MAP_Y * 4;
    
    warpUp = lignes[y][0];
    warpDown = lignes[y][1];
    warpLeft = lignes[y][2];
    warpRight = lignes[y][3];
    
    for (int i = 0; i < 10; i++){
        warpSP[i].value = lignes[y][i + 4];
    }
    /*
    for (int i = 0; i < 20; i++){
        coffre[i].type = lignes[y][74 + i];
    }
    
    for (int i = 0; i < 10; i++){
        button[i].type = lignes[y][99 + i];
    }
    
    for (int i = 0; i < 10; i++){
        piege[i].type = lignes[y][109 + i];
    }
    */
    
    
    //conversion en pixels
    maxX = (maxX + 1) * TILE_SIZE;
    maxY = (maxY + 1) * TILE_SIZE;
}