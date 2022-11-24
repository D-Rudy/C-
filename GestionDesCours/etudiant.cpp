#include "etudiant.hpp"

    Etudiant(const std::string& nom);
    void ajouterMatiere(Matiere& m, float n);
    std::string getNom()const;
    std::vector<Matiere> getTabMatiere()const;
    void afficher() const;
    void setNom(std::string& n);
    float calculerMoyenne()const;
    bool rechercheMatiere(const std::string& nomMat)const;
