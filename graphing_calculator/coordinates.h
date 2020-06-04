#ifndef COORDINATES_H
#define COORDINATES_H
#include <iostream>

using namespace std;


class Coordinates
{
public:
    Coordinates(){}
    Coordinates(double xCord,double yCord);


     friend ostream& operator <<(ostream& os, const Coordinates& Printme);


    double x;
    double y;
};


ostream& operator <<(ostream& outs, const Coordinates& Printme)
{
    outs << Printme.x << ',' << Printme.y<<endl;
    return outs;
}

Coordinates::Coordinates(double xCord,double yCord){
    x = xCord;
    y = yCord;
}


#endif // COORDINATES_H
