
#ifndef MUR_H
#define MUR_H

enum Direction{NORD,SUD,EST,OUEST};
class Mur{

public:
    Mur(const Position& , const Direction&,unsigned int);
    Mur(const Position& , const Direction&);

    Position depart()const;
    Direction direction()const;
    unsigned int taille()const;



    void depart(const Position&);
    void direction(const Direction&);
    void taille(unsigned int);

private:

    Position d_depart;
    Direction d_direction;
    unsigned int d_taille;



};
#endif // MUR_H
