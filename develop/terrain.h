
#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain{


public:
    Terrain(const Position&,const Position&,const vector<Mur>&);
    Terrain(const Position&,const Position&);
/***
Les murs
le cible
le laser
*/
void ajouterMur(const Mur&);
void ajouterMirroir(const Mirroir&);

void changerPosiLaser(const Position&);
void ajouterCible(const Position&);

//la fonction renvoie vrai si on a tirrer sur une cible, sinon false
bool tirrer();//principale
void placerMur(const Mur&); //faire les tests pour que la taille du mur ne depasse pas la taille du terrain

private:
    vector<Mur> _murs;
    vector<Mirroir> _mirroirs;
    Position _laser;
    Position _cible;


};
#endif // TERRAIN_H
