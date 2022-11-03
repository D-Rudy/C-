#include <iostream>
#include "domino.cpp"

using namespace std;


int main(){

        Domino domino;
        Jeu jeu;

        jeu = creerJeuPioche();
        afficherJeu(jeu);

        cout<<"points = " << pointsJeuRec(jeu, jeu.tabDominos.size());

        return 0;
}
