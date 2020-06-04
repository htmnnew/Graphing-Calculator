#ifndef CHILDNUMBERS_H
#define CHILDNUMBERS_H
#include "token.h"

class numbers : public Token
{
public:

    numbers();

    numbers(double x);

    double getVal();

    int Type();

private:
    double value;

};

numbers::numbers(){

}

numbers::numbers(double x){
    value = x;
}

double numbers::getVal(){
    return value;
}

int numbers::Type(){
    return NUMBER;
}

#endif // CHILDNUMBERS_H
