#ifndef TAILLE_H
#define TAILLE_H


class Taille{

public:
    Taille();
    Taille(unsigned int );
    Taille(unsigned int,unsigned int);
    unsigned int largeur()const;
    unsigned int longeur()const;

    void setLargeur(unsigned int);
    void setLongeur(unsigned int);
private:
        unsigned int d_longeur;
        unsigned int d_largeur;
};
#endif // TAILLE_H
