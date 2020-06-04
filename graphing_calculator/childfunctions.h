#ifndef CHILDFUNCTIONS_H
#define CHILDFUNCTIONS_H
#include "token.h"

class functions : public Token
{
public:

    functions();

    functions(char Face, int rank);

    int Type();

    double getVal();

    char GetFace();


private:
   char face;

   int prec;
};

functions::functions(){

}

double functions::getVal(){
    return prec;
}

char functions::GetFace(){
    return face;
}

functions::functions(char Face,int rank){
    face = Face;
    prec = rank;
}

int functions::Type(){
    return FUNCTION;
}

#endif // CHILDFUNCTIONS_H
