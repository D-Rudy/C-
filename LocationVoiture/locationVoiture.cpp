#include <fstream>
#include <iostream>
#include "locationVoiture.hpp"

  Parc p;
void AfficherMenu (int& choix){

    std::cout << "-------MENU-------" << std::endl;
    std::cout << "1 : Louer une voiture" << std::endl;
    std::cout << "2 : Retourner une voiture" << std::endl;
    std::cout << "3 : Etat d'une voiture" << std::endl;
    std::cout << "4 : Etat du parc de voitures" << std::endl;
    std::cout << "5 : Ajouter une voiture" << std::endl;
    std::cout << "6 : Supprimer une voiture" << std::endl;
    std::cout << "7 : Sauvegarder l'etat du parc" << std::endl;
    std::cout << "8 : Quitter" << std::endl;

    if (choix == 1){
        int numMat = saisirImmatriculation();
        louerUneVoiture(p, numMat);

    }
    if (choix ==2){
        int numMat = saisirImmatriculation();
        retourVoiture(p, numMat);
    }
    if(choix == 3){
        int numMat = saisirImmatriculation();
        etatVoiture(p, numMat);
    }
    if(choix == 4){
        etatParc(p);
    }
    if(choix == 5){
        ajouterUneVoiture(p);
        choix = 0;
        AfficherMenu(choix);
        // ajoute voiture dans le parc(sauf immat);
    }
    if(choix == 6){
        int numMat = saisirImmatriculation();
        supprimerVoiture(p, numMat);
    }
    if(choix == 7){
        std::cout << "Saisir nom fichier : " << std::endl;
        std::string f;
        std::cin >> f;
        save(f, p);
    }

    if(choix == 8){
        std::cout<<"Bye !";
        exit(0);
    }
    std::cout<<"Choix: "<<std::endl;
    std::cin>>choix;
    AfficherMenu(choix);

}

Voiture saisirUneVoiture(){
    Voiture v;
    v.etat = false;

    std::cout << "Entrez le modele : "<<std::endl;
    std::cin >> v.modele;
    std::cout << "Entrez le kilometrage : "<<std::endl;
    std::cin >> v.kilometrage;
    std::cout << numMatAutoIncrement<<std::endl;
    numMatAutoIncrement++;
    v.numMat = numMatAutoIncrement;
    std::cout << numMatAutoIncrement<<std::endl;
    std::cout <<v.numMat<<std::endl;
    return v;
}

void afficherUneVoiture(const Voiture& v){
 std::string etat;

    if (!v.etat)
        etat = "disponible";
    else
        etat = "En location";

    std::cout <<v.numMat<< " "<<v.modele<< " "<<v.kilometrage<< " "<<etat<< std::endl;
}

void initParc(Parc& p, int n){
    for (int i = 0; i < n; i++){
        p.parc.push_back(saisirUneVoiture());
    }
        int choix = 0;
        AfficherMenu(choix);

}

int saisirImmatriculation(){
    int n;

    std::cout << "Veuillez saisir le numero d'immatriculation : "<<std::endl;
    std::cin >> n;

    return n;
}

int rechercheVoiture(const Parc& p, int n){
    int tailleParc = p.parc.size();
    for(int i = 0; i < tailleParc; i++){
        if(p.parc[i].numMat == n){
            return i;
        }
    }
    return -1;
}

void louerUneVoiture(Parc& p, int numMat){

    int indice = rechercheVoiture(p, numMat);
    if(indice == -1){
        std::cout << "Erreur." << std::endl;
    }
    else{
        if(!p.parc[indice].etat){
                    p.parc[indice].etat = true;
        std::cout << "voiture louée." << std::endl;
        }else{
            std::cout << "Voiture déja en location." << std::endl;
        }
    }
}

void retourVoiture(Parc &p, int numMat){
    int indice = rechercheVoiture(p, numMat);
    if(indice == -1){
        std::cout << "Erreur" << std::endl;
    }
    else{
        if(p.parc[indice].etat){
            p.parc[indice].etat = false;
            std::cout << "Nombre de kilometre effectué : " << std::endl;
            int km = 0;
            std::cin>> km;
            p.parc[indice].kilometrage = p.parc[indice].kilometrage + km;
            std::cout << "Disponible." << std::endl;
        }else{
            std::cout << "voiture non louée." << std::endl;
        }

    }
}

void etatVoiture(const Parc& p, int numMat){

    int indice = rechercheVoiture(p, numMat);
    if(indice == -1){
        std::cout << "Erreur." << std::endl;
    }
    else{
        afficherUneVoiture(p.parc[indice]);
    }
}


void etatParc(const Parc& p){
    std::cout << "Nombre total de voitures : " << p.parc.size() << std::endl;
    for (int i = 0; i < p.parc.size(); i++) {
        afficherUneVoiture(p.parc[i]);
    }
}


void ajouterUneVoiture(Parc &p){
        p.parc.push_back(saisirUneVoiture());
        std::cout << "Voiture Ajoutée" << std::endl;
}

void supprimerVoiture(Parc &p, int numMat){
    for(int i = 0; i < p.parc.size(); i++){
        if(p.parc[i].numMat == numMat){
            p.parc.erase(p.parc.begin()+i);
            std::cout<<"Voiture supprimée";
        }

    }
}
void save(std::string f,Parc& p ){
   for(int i = 0; i < p.parc.size(); i++){
        std::ofstream fichier;
        fichier.open(f);
        if(fichier){
            fichier<<"Immatriculation: "<<p.parc[i].numMat<<std::endl;
            fichier<<"Modele: "<<p.parc[i].modele<<std::endl;
            fichier<<"Kilometrage: "<<p.parc[i].kilometrage<<std::endl;
            fichier<<"Etat: "<<p.parc[i].etat<<std::endl;
            fichier<<std::endl<<"======================================="<<std::endl;

        }
    fichier.close();

    }

}

