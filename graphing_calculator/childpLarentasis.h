#ifndef CHILDLPARENTASIS_H
#define CHILDLPARENTASIS_H
#include "token.h"

class Lparent : public Token
{
public:

    Lparent();

    int Type();

private:
    char face = '(';

};

Lparent::Lparent(){

}

int Lparent::Type(){
    return LPAREN;
}

#endif // CHILDLPARENTASIS_H
