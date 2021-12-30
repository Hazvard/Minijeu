#include "Carte.hpp"
 
using namespace std;
using namespace sf;

Carte::Carte(){
    //on charge le tileset de la frame 1
	if (!tileSetTexture1.loadFromFile("ressources/Frame1.png")){
        cout << "Erreur durant le chargement de l'image du tileset 1." << endl;
    }
    else{
        tileSet1.setTexture(tileSetTexture1);
    }

    //on charge le tileset 2
    if (!tileSetTexture2.loadFromFile("ressources/Frame2.png")){ //réutiliser la même texture en la redéfinissant ne fonctionne pas
        cout << "Erreur durant le chargement de l'image du tileset 2." << endl;
    }
    else{
        tileSet2.setTexture(tileSetTexture2);
    }

    //On charge la police
    if (!font.loadFromFile("ressources/arial.ttf")){
         cout << "Erreur durant le chargement de la police." << endl;
    }

    testdefil = 0;
    level = 1;
    debutAbscisse = 0;
    debutOrdonne = 0;
    timer =  timeMenu = seconds(0.00f);
    tempsdonne = 60 ;
    menu = false ;
}

void Carte::initialisation(){
    testdefil = 0;
    level = 1;
    debutAbscisse = 0;
    debutOrdonne = 0;
    timer =  timeMenu = seconds(0.00f);
    tempsdonne = 60 ;
    menu = false ;
    frameTimer.restart() ;
    TimerMenu.restart() ;
}

//GETTERS
int Carte::getBeginX() const { 
	return beginx; 
}

int Carte::getBeginY() const { 
	return beginy; 
}

int Carte::getDebutAbscisse() const { 
	return debutAbscisse; 
}

int Carte::getDebutOrdonne() const { 
	return debutOrdonne; 
}

int Carte::getMaxX() const { 
	return maxX; 
}

int Carte::getMaxY() const { 
	return maxY; 
}

int Carte::getTile(int y, int x) const { 
	return tile[y][x]; 
}

int Carte::getLevel() const { 
	return level; 
}


float Carte::getTimer(){
    if(menu){

        timeMenu =  TimerMenu.getElapsedTime() + timeMenu ;
        TimerMenu.restart() ;
        return timer.asSeconds();

    }else{
        TimerMenu.restart() ;
        timer = frameTimer.getElapsedTime() - timeMenu;
        return timer.asSeconds() ;
    }
}

bool Carte::getMenu(){
    return menu ;
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

void Carte::setBegin(int x, int y){
    beginx = x;
    beginy = y;
}

void Carte::TimerAZero(){
    timer = timer - timer ;
}

void Carte::setMenu(bool b){
    menu = b ;
}


//AUTRES FONCTIONS

std::string Carte::decompte(){
    if(menu){
        
    }
    return to_string(tempsdonne - (int)getTimer()) ;
}

//renvoie un intpour le décompte (pour le game over)
int Carte::decompteInt(){
    return tempsdonne - (int)getTimer();
}

bool Carte::tempsDepasse(){
    return decompteInt() < 1 ;
}

//ajoute du temps sur le compteur principal
void Carte::addTime(){
    tempsdonne = tempsdonne + TEMPSSUPPLEMENTAIRE;
}

void Carte::creerListeDeCartes(){ //enchaine les cartes dans une liste dynamique
    //on choisit juste des nombres random dans un tableau de nombres, et on les empile dans la liste
    int tableaubasique [10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //on considère qu'on a 10 maps exactement
    int zebi = -1;

    for(int i = 0; i < 10; i++){
        zebi = rand() % 10 + 1;  //sélection d'un nombre entre 1 et 10

        while(tableaubasique[zebi] == -1){
            zebi++;
            if(zebi>10){
                zebi = 1;
            }
        }

        listeDeCartes.inserer(0, tableaubasique[zebi]);
        tableaubasique[zebi] = -1;
    }


}


void Carte::changeLevel(void){ // Récupère le noeud 0 de la liste et le supprime
    string filename;
    filename = "cartes/map" + to_string(level) + ".txt";
    loadMap(filename);
}

void Carte::nextLevel(void){
    level++;
    (*this).addTime();
    (*this).changeLevel();  //apres, elise s'initialise elle même si cette fonction est appellée par la fin d'un niveau.
}

void Carte::draw(RenderWindow &window){




    //code fait avec soin par mes petites mains
	int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;

	mapX = debutAbscisse / TILE_SIZE; 
	x1 = (debutAbscisse % TILE_SIZE) * (-1); //coord de départ pour l'affichage de la map
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE); //coord de fin de la map, on fait expres de sortir de l'écran

	mapY = debutOrdonne / TILE_SIZE;
    y1 = (debutOrdonne % TILE_SIZE) * (-1);
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE); //le ? dit juste: si y !=0, alors y = tile size


    //test de sélection de la frame
    bool choixFrame; //on exteriorise la sélection de la frame de la boucle de draw pour éviter que le tileset change en cours de dessin
    Time instant = frameTimer.getElapsedTime();

    int frameur = (int)instant.asSeconds(); 
    choixFrame = (frameur%2 == 0); //true si l'instant est pair, false sinon

    //dessin de la map ligne par ligne, par tranche de TILE_SIZE pixels
    for (y = y1; y < y2; y += TILE_SIZE){
        mapX = debutAbscisse / TILE_SIZE; //reinit de mapX au début de chaque ligne

        for (x = x1; x < x2; x += TILE_SIZE){
            a = tile[mapY][mapX]; //numéro de la tile sur le tileset
        
            /* Calcul pour obtenir son y (pour un tileset de 10 tiles
            par ligne, d'où le 10 */
            ysource = a / 6 * TILE_SIZE;
            xsource = a % 6 * TILE_SIZE;
            
            if(choixFrame){
                tileSet1.setPosition(Vector2f(x, y));
                tileSet1.setTextureRect(sf::IntRect(xsource, ysource, TILE_SIZE, TILE_SIZE)); //on resize la texture de l'objet tileset vers un carré contenant une seule tile
                window.draw(tileSet1); //tileset est un sprite donc ok pour le dessiner
            }
            else{
                tileSet2.setPosition(Vector2f(x, y));
                tileSet2.setTextureRect(sf::IntRect(xsource, ysource, TILE_SIZE, TILE_SIZE)); //on resize la texture de l'objet tileset vers un carré contenant une seule tile
                window.draw(tileSet2); //tileset est un sprite donc ok pour le dessiner
            }

            mapX++;
        }
    
        mapY++;
        
    }

}

void Carte::drawTimer(RenderWindow &window){
    if(!tempsDepasse()){
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(75, 30));
        rectangle.setOutlineColor(sf::Color::Blue);
        rectangle.setOutlineThickness(5);
        rectangle.setPosition(380.f, 12.f);
        window.draw(rectangle);

        sf::Text text;

        // select the font
        text.setFont(font);
        text.setString(decompte()); // On affiche le décompte

        // taille des character
        text.setCharacterSize(35); // en pixels

        // couleur
        text.setFillColor(sf::Color::Blue);

        text.setPosition(400.f, 5.f) ;

        // Si on vzut faire souligner ou gras
        //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
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

void Carte::loadMap(string filename){
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


    //double boucle de lecture du tableau ligne pour arriver à un tableau de tiles
    //pour l'instant on est sur un max de 80 * 80 tiles, voir hpp

    //au cas ou on ait pas de begin
    beginx = 0;
    beginy = 0;
    
    for (y = 0; y < MAX_MAP_Y; y++){
        for (x = 0; x < MAX_MAP_X; x++){
            tile[y][x] = lignes[y][x];
            if(tile[y][x] == 5){ //tile 5 = carré bleu
                beginx = x*TILE_SIZE;
                beginy = y*TILE_SIZE;
            }
    
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

/*
    //débug
    //On charge les variables supplémentaires
    y = MAX_MAP_Y * 4;
    
    warpUp = lignes[y][0];
    warpDown = lignes[y][1];
    warpLeft = lignes[y][2];
    warpRight = lignes[y][3];
    
    for (int i = 0; i < 10; i++){
        warpSP[i].value = lignes[y][i + 4];
    }
*/




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