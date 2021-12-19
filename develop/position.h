
#ifndef POSITION_H
#define POSITION_H

class Position{

public:
    Position();
    Position(unsigned int);
    Position(unsigned int , unsigned int);

    unsigned int x()const;
    unsigned int y()const;

    void setX(unsigned int);
    void setY(unsigned int);

private:
    unsigned int d_x,d_y;
};
#endif // POSITION_H
