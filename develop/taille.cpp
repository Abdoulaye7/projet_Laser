#include "taille.h"
#include<iostream>

Taille::Taille(unsigned int lo,unsigned int larg):
    d_longeur{lo},
    d_largeur{larg}
{
    /**
    pour eviter un beug de la recupperation de chiffre[x], x ne doit pas etre supêrieru a 35
    */
    if(d_largeur>35)
        d_largeur=35;
    if(d_longeur>35)
        d_longeur=35;
}

Taille::Taille(unsigned int longeurLargeur): Taille{longeurLargeur,longeurLargeur}{}

Taille::Taille():Taille(20,20){}



unsigned int Taille::largeur()const
{
    return d_longeur;
}
unsigned int Taille::longeur()const
{
    return d_largeur;
}

void Taille::setLargeur(unsigned int longeur)
{
    d_longeur = longeur;
}
void Taille::setLongeur(unsigned int largeur)
{
    d_largeur= largeur;
}
