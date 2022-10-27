#include <iostream>
#include "domino.cpp"

using namespace std;


int main(){

        Domino domino;
        Jeu jeu;

        jeu = creerJeuPioche();
        afficherJeu(jeu);

        cout<<"points = " << pointsJeu(jeu);

        return 0;
}
