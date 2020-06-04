#ifndef CHILDOPERATORS_H
#define CHILDOPERATORS_H
#include "token.h"

class operators : public Token
{
public:

    operators();

    operators(char x, int rank);

    int Type();

    double getVal();

    char GetFace();

private:
    char face;

    int prec;

};


char operators::GetFace(){
    return face;
}

operators::operators(){

}


operators::operators(char x,int rank){
    face = x;
    prec = rank;

}

double operators::getVal(){
    return prec;
}

int operators::Type(){
    return OPERATOR;
}

#endif // CHILDOPERATORS_H
