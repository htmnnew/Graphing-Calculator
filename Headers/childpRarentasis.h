#ifndef CHILDRPARENTASIS_H
#define CHILDRPARENTASIS_H
#include "token.h"

class Rparent : public Token
{
public:

    Rparent();

    int Type();


private:
    char face = ')';
};

Rparent::Rparent(){

}

int Rparent::Type(){
    return RPAREN;
}

#endif // CHILDRPARENTASIS_H
