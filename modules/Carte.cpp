#include "Carte.hpp"
 
using namespace std;
using namespace sf;

Carte::Carte(){
	if (!tileSet1Texture.loadFromFile("ressources/tuiles.png")){
        cout << "Erreur durant le chargement de l'image du tileset 1." << endl;
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
	x1 = (debutAbscisse % TILE_SIZE) * -1; //coord de départ pour l'affichage de la map
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE); //coord de fin de la map

	mapY = debutOrdonne / TILE_SIZE;
    y1 = (debutOrdonne % TILE_SIZE) * -1;
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);

    for (y = y1; y < y2; y += TILE_SIZE){
        /* A chaque début de ligne, on réinitialise mapX qui contient la colonne
        (0 au début puisqu'on ne scrolle pas) */
        mapX = debutAbscisse / TILE_SIZE;
    
        /* A chaque colonne de tile, on dessine la bonne tile en allant
        de x = 0 à x = 640 */
            for (x = x1; x < x2; x += TILE_SIZE){

                /* Suivant le numéro de notre tile, on découpe le tileset (a = le numéro
                de la tile */
                a = tile[mapY][mapX];
        
                /* Calcul pour obtenir son y (pour un tileset de 10 tiles
                par ligne, d'où le 10 */
                ysource = a / 10 * TILE_SIZE;

                /* Et son x */
                xsource = a % 10 * TILE_SIZE;
        
                /* Fonction qui blitte la bonne tile au bon endroit suivant le timer */
                if (tileSetNumber == 0){
                    tileSet1.setPosition(Vector2f(x, y));
                    tileSet1.setTextureRect(sf::IntRect(xsource, ysource, TILE_SIZE, TILE_SIZE));
                    window.draw(tileSet1);
                } else{
                    tileSet1B.setPosition(Vector2f(x, y));
                    tileSet1B.setTextureRect(sf::IntRect(xsource, ysource, TILE_SIZE, TILE_SIZE));
                    window.draw(tileSet1B);
                }
        
                mapX++;
            }
    
        mapY++;
        
    }
}

void Carte::testDefilement(void){
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
    string strBuf, strTmp;//que du temporaire    
    stringstream iostr;//stringstream de gstion des chaines
    fin.open(filename, fstream::in); //ouverture fichier
    

    if (!fin.is_open()){
        cerr << "Erreur de chargement du fichier.\n";
        exit(1);
    }
    
    //On lit notre fichier jusqu'à la fin (eof = end of file)
    while (!fin.eof()){
        getline(fin, strBuf);//On récupère la ligne dans la chaîne strBuf

        //Si la ligne est vide, on continue la boucle
        if (!strBuf.size())
            continue;

        iostr.clear();//Sinon on poursuit et on réinitialise notre stringstream
    
        //On y envoie le contenu du buffer strBuf
        iostr.str(strBuf);
    
        //On réinitialise le vecteur ligne
        myVectData.clear();
    
        //On boucle pour lire chaque numéro de tile du fichier map
        while (true){

            //Pour chaque ligne on récupère le numéro de la tile, en
            //les parsant grâce aux espaces qui les séparent (' ')
            getline(iostr, strTmp, ' ');
    
            //On récupère ce numéro dans dans notre vecteur ligne
            myVectData.push_back(atoi(strTmp.c_str()));
    
            //Si on a fini, on quitte la boucle
            if (!iostr.good())
                break;
        }
    
        //Si le vecteur ligne n'est pas vide, on l'envoie dans notre vecteur à 2 dimensions
        if (myVectData.size())
            lignes.push_back(myVectData);
    }
    
    //On ferme le fichier
    fin.close();
    
    //On va maintenant remplir les variables de notre classe à l'aide de notre vecteur
    //à 2 dimensions temporaire.
    //On commence par récupérer les 3 premières valeurs de la 1ère ligne (0)
    //qui sont les valeurs de départ du héros et du tileset à afficher
    beginx = lignes[0][0];
    
    beginy = lignes[0][1];
    
    tilesetAffiche = lignes[0][2];
    
    //On charge ensuite la première ligne individuellement car elle contient + de données
    //(décalage de 3 numéros à cause des 3 précédents)
    for (x = 3; x < MAX_MAP_X + 3; x++){
        tile[y][x - 3] = lignes[y][x];
    }
    
    //Puis on charge le reste du tableau de tiles pour la couche 1.
    //On boucle jusqu'à MAX_MAP_Y et MAX_MAP_X, soit les dimensions
    //maxi de la map (400 x 150 tiles, pour rappel)
    for (y = 1; y < MAX_MAP_Y; y++){
        for (x = 0; x < MAX_MAP_X; x++){
            //On copie la valeur de notre vecteur temporaire
            //dans notre tableau à deux dimensions
            tile[y][x] = lignes[y][x];
    
            //On détecte si la tile n'est pas vide
            if (tile[y][x] > 0){

                //Si c'est la cas, on augmente la valeur de maxX ou
                //maxY car la map n'est pas encore finie.

                if (x > maxX){
                    maxX = x;
                }
    
                if (y > maxY){
                    maxY = y;
                }
            }
        }
    }
    
    //On fait la même chose pour la seconde couche de tiles :
    for (y = 0; y < MAX_MAP_Y; y++){
        for (x = 0; x < MAX_MAP_X; x++){
            tile2[y][x] = lignes[y + MAX_MAP_Y][x];
        }
    }
    
    //Puis pour la troisième :
    for (y = 0; y < MAX_MAP_Y; y++){
        for (x = 0; x < MAX_MAP_X; x++){
            tile3[y][x] = lignes[y + MAX_MAP_Y * 2][x];
        }
    }
    
    //Et enfin pour la quatrième (la couche des collisions
    //et des tiles spéciales) :
    for (y = 0; y < MAX_MAP_Y; y++){
        for (x = 0; x < MAX_MAP_X; x++){
            tile4[y][x] = lignes[y + MAX_MAP_Y * 3][x];
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
    
    for (int i = 0; i < 20; i++){
        coffre[i].type = lignes[y][74 + i];
    }
    
    for (int i = 0; i < 10; i++){
        button[i].type = lignes[y][99 + i];
    }
    
    for (int i = 0; i < 10; i++){
        piege[i].type = lignes[y][109 + i];
    }
    
    
    //conversion en pixels
    maxX = (maxX + 1) * TILE_SIZE;
    maxY = (maxY + 1) * TILE_SIZE;
}