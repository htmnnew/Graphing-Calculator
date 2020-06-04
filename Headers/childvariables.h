#ifndef CHILDVARIABLES_H
#define CHILDVARIABLES_H
#include "token.h"

class variable : public Token
{
public:
    variable();

    variable(int sign);

    int Type();

    double getVal();

private:
    char x = 'x';

    double val; //-1 = negative, 1 = positive
};

variable::variable(int sign){
    val = sign;
}

variable::variable(){
}

int variable::Type(){
    return VARIABLE;
}

double variable::getVal(){
    return val;
}

#endif // CHILDVARIABLES_H
