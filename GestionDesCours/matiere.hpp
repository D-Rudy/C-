#ifndef H_MATIERE
#define H_MATIERE

class Matiere
{
    std::string intitule;
    int coefficient;
    float note;

public:
    Matiere(const std::string& i, int coef);

    std::string getIntitule() const;

    int getCoefficient() const;

    float getNote() const;

    void setIntitule(const std::string& i);

    void setCoefficient (int c);

    void setNote(float n );

    void afficher() const;
};

#endif // H_MATIERE
