#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "container.h"
#include "constants.h"


using namespace std;


class Token
{
public:

    Token();

    friend ostream& operator << (ostream& outs,const Token& token);

    virtual void Print (ostream& outs) const;

    virtual int Type(){}

    virtual double getVal(){}

    virtual char GetFace(){}

    ~Token();
};


Token::Token(){

}

Token::~Token(){
cout<<"Inside Token Distractor";
}

ostream& operator<<(ostream& outs,const Token& token){
    token.Print(outs);
    return outs;
}

void Token::Print(ostream& outs) const{

}

#endif // TOKEN_H
