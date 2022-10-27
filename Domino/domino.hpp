#include <vector>

const int NBDOMINOS = 28;

struct Domino
{
    int valG;
    int valD;
};


struct Jeu
{
    std::vector<Domino> tabDominos;
};

Domino creerUnDomino(int a, int b);

void afficherUnDomino(const Domino& d);

Jeu creerJeuPioche();

void afficherJeu(const Jeu& j);

Domino retournerUnDomino(const Domino& d);

int pointsDomino (const Domino& d);

int pointsJeu (const Jeu& j);

