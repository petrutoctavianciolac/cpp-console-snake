#include "point.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

void Point::setX(char c, int n)
{
    if(c == 'a')
        x++;

    if(c == 'd')
        x--;
        
    if(c == 'n')
        x = n;
}

void Point::setY(char c, int n)
{
    if(c == 'a')
        y++;

    if(c == 'd')
        y--;

    if(c == 'n')
        y = n;
}