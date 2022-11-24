#include "matiere.cpp"
#include <iostream>

int main()
{
    Matiere* m=new Matiere("Math", 6);//Dynamique
    Matiere m1("Histoire",2);//static

    m1.setNote(8);
    m->setNote(12);
    m->afficher();
    m1.afficher();
    return 0;
}
