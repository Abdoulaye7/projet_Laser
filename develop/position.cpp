
#include "position.h"
#include <iostream>


Position::Position():Position{0,0}{}
Position::Position(unsigned int xy):Position{xy,xy}{}
Position::Position(unsigned int x, unsigned int y):
    d_x{x},
    d_y{y}
    {

    }


unsigned int Position::x()const
{
    return d_x;
}
unsigned int Position::y()const
{
    return d_y;
}

void Position::setX(unsigned int x)
{
    d_x=x;
}
void Position::setY(unsigned int y)
{
    d_y=y;
}
