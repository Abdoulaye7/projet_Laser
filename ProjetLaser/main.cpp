#include <iostream>
#include<vector>
using namespace std;

enum Direction{NORD,SUD,EST,OUEST};
enum MirroirType{AIGU,GRAVE};
class Taille{
    unsigned int _longeur;
    unsigned int _largeur;
public:
    Taille();
    Taille(unsigned int );
    Taille(unsigned int,unsigned int);
    unsigned int largeur()const;
    unsigned int longeur()const;

    void largeur(unsigned int);
    void longeur(unsigned int);
};


Taille::Taille(unsigned int lo,unsigned int larg):
    _longeur{lo},
    _largeur{larg}
{
    /**
    pour eviter un beug de la recupperation de chiffre[x], x ne doit pas etre supêrieru a 35
    */
    if(_largeur>35)
        _largeur=35;
    if(_longeur>35)
        _longeur=35;
}

Taille::Taille(unsigned int longeurLargeur): Taille{longeurLargeur,longeurLargeur}{}

Taille::Taille():Taille(20,20){}






unsigned int Taille::largeur()const
{
    return _longeur;
}
unsigned int Taille::longeur()const
{
    return _largeur;
}

void Taille::largeur(unsigned int longeur)
{
    _longeur = longeur;
}
void Taille::longeur(unsigned int largeur)
{
    _largeur= largeur;
}

vector<char> chiffre{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y','Z'};




void dessinerTerrain(const Taille &t){
    cout<<"  ";
    for(auto x=0;x<t.largeur();x++)
        cout<<chiffre[x]<<" ";
    cout<<endl;
    cout<<"  ";
    for(auto x=0;x<t.largeur();x++){
        cout<<" _";
    }


    for(auto i=0;i<t.longeur(); i++){
        cout<<endl<<chiffre[i]<<"| ";
    }
    cout<<endl<<"  ";
    for(auto x=0;x<t.largeur();x++)
        cout<<"_ ";
    cout<<endl<<"  ";
    for(auto x=0;x<t.largeur();x++)
        cout<<chiffre[x]<<" ";
    cout<<endl;


}

class Position{
    unsigned int _x,_y;
public:
    Position();
    Position(unsigned int);
    Position(unsigned int , unsigned int);

    unsigned int x()const;
    unsigned int y()const;

    void x(unsigned int);
    void y(unsigned int);
};

Position::Position():Position{0,0}{}
Position::Position(unsigned int xy):Position{xy,xy}{}
Position::Position(unsigned int x, unsigned int y):
    _x{x},
    _y{y}
    {

    }


unsigned int Position::x()const{return _x;}
unsigned int Position::y()const{return _y;}

void Position::x(unsigned int x){_x=x;}
void Position::y(unsigned int y){_y=y;}

class Mur{
    Position _depart;
    Direction _direction;
    unsigned int _taille;
public:
    Mur(const Position& , const Direction&,unsigned int);
    Mur(const Position& , const Direction&);

    Position depart()const;
    Direction direction()const;
    unsigned int taille()const;



    void depart(const Position&);
    void direction(const Direction&);
    void taille(unsigned int);

};
Mur::Mur(const Position& p, const Direction& d,unsigned int t):
    _depart{p},
    _direction{d},
    _taille{t}{}
Mur::Mur(const Position& p, const Direction& d):
    Mur{p,d,1}{}//faut mettre a jour plus tard, par ce que si la taiuklle est 1, on a pas besoin de la direction

Position Mur::depart()const{return _depart;}
Direction Mur::direction()const{return _direction;}
unsigned int Mur::taille()const{return _taille;}
void Mur::depart(const Position& depart){_depart=depart;}
void Mur::direction(const Direction& d){_direction=d;}
void Mur::taille(unsigned int t){_taille=t;}

class Mirroir{
    Position _position;
    MirroirType _type;
public:
    Mirroir(const Position&,const MirroirType&);
};
Mirroir::Mirroir(const Position& p,const MirroirType& t):
    _position{p},
    _type{t}{}
class Terrain{
    vector<Mur> _murs;
    vector<Mirroir> _mirroirs;
    Position _laser;
    Position _cible;

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


};
Terrain::Terrain(const Position&l,const Position& c,const vector<Mur>& m):
    _laser{l},_cible{c},_murs{m}{}
Terrain::Terrain(const Position& l,const Position& c):_laser{l},_cible{c}{
    _murs.resize(0);
}
void Terrain::ajouterMirroir(const Mirroir& m){
    _mirroirs.push_back(m);
}










Mirroir placerMirroir(){
    cout<<"Definissez le type du mirroir "<<endl;
    cout<<"AIGU = \'/\' utiliser 0"<<endl<<"GRAVE = \'//' utiliser 1"<<endl;

    MirroirType mt;
    int mt_int;
    cout<<endl<<"Valeur (0 ou 1):";
    cin>>mt_int;
    if(mt_int==0)
        mt=AIGU;
    else
        mt=GRAVE;

    cout<<endl<<"saissez la position du mirroir (respecter le taille du terrain)"<<endl<<endl<<"Taille x  y:";
    unsigned int x,y;
    cin>>x>>y;
    Position p(x,y);

    return Mirroir(p,mt);
}
void placerMirroirs(Terrain& t){
    unsigned int nbMirroirs;
    cout<<"combnien de mirroirs tu veux placer??";cin>>nbMirroirs;
    while(nbMirroirs>0){
        t.ajouterMirroir(placerMirroir());
        nbMirroirs--;
    }
}
void placeLaser(){}
void effacer(){}

void run(){
    //unsigned int longeur,largeur;
    //cout<<"Saississez la lon et la largeur du terrain";cin>>longeur>>largeur;
    //Terrain t(longeur,largeur);

    //bool enjeux=true;
    //positionner la cible
   /* while(enjeux){
        //placerMirroirs(t);


        //placeLaser(); //meme methodology que les mirroirs, sauf que on doit avoir unioquement un laser, pas plus
        /*if(t.tirrer()){

        // et ajouter des murs (aleatoirement) ,

            //Afficher les messages de felicitations
            //augmenter la taille du terrain en respectant la taiolle de 35



        }else{
            //on repositionne la cible
        }

        //effacer les mirroirs etv le lasers
    enjeux=false;
    }*/
    //cout<<endl;
}
int main()
{

    run();

    return 0;
}
