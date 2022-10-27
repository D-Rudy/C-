#include <iostream>
#include "domino.hpp"


Domino creerUnDomino(int a, int b)
{
    Domino domino;
    domino.valG=a;
    domino.valD=b;

    return domino;
}

void afficherUnDomino(const Domino& d)
{
    std::cout<<"("<<d.valG<<":"<<d.valD<<")"<<std::endl;
}

Jeu creerJeuPioche()
{
    Jeu j;
    for(int g = 0; g <7; g++)
        for(int d = g; d < 7; d++)
            j.tabDominos.push_back(creerUnDomino(g, d));


    return j;
}

void afficherJeu(const Jeu& j)
{
    for(int i = 0; i < j.tabDominos.size(); i++)
        afficherUnDomino(j.tabDominos[i]);
}

Domino retournerUnDomino(const Domino& d)
{
    Domino d1;
    d1.valG = d.valD;
    d1.valD = d.valG;
    return d1;
}

int pointsDomino(const Domino& d)
{
    return d.valG+d.valD;
}

int pointsJeu (const Jeu& j)
{
    int  points = 0;
    for(int i = 0; i < j.tabDominos.size(); i++)
        points += pointsDomino(j.tabDominos[i]);

    return points;
}
