#include <vector>

int static numMatAutoIncrement = 0;


struct Voiture{
    int numMat;
    std::string modele;
    int kilometrage;
    bool etat;
};

struct Parc{
    std::vector<Voiture> parc;
};

void AfficherMenu (int& choix);
Voiture saisirUneVoiture();
void afficherUneVoiture(const Voiture &v);
void initParc(Parc& p, int n);
int saisirImmatriculation();
int rechercheVoiture(const Parc& p, int n);
void louerUneVoiture(Parc &p, int numMat);
void retourVoiture(Parc &p, int numMat);
void etatVoiture(const Parc& p, int numMat);
void etatParc(const Parc& p);
void ajouterUneVoiture(Parc& p);
void supprimerVoiture(Parc& p, int numMat);
void save(std::string f,Parc& p );










