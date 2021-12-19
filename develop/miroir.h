
#ifndef MIROIR_H
#define MIROIR_H


enum MirroirType{AIGU,GRAVE};
public:
    Mirroir(const Position&,const MirroirType&);
private:
    
    Position d_position;
    MirroirType d_type;
};
#endif // MIROIR_H
