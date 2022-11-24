#ifndef H_ETUDIANT
#define H_ETUDIANT

#include "matiere.hpp"
#include <vector>

cons int MAX_MATIERE = 3;

class Etudiant
{
    int numEtudiant;
    std::string nomEtudiant;
    std::vector<Matiere> tabMat;

public:
    Etudiant(const std::string& nom);
    void ajouterMatiere(Matiere& m, float n);
    std::string getNom()const;
    std::vector<Matiere> getTabMatiere()const;
    void afficher() const;
    void setNom(std::string& n);
    float calculerMoyenne()const;
    bool rechercheMatiere(const std::string& nomMat)const;
};

#endif // H_ETUDIANT
