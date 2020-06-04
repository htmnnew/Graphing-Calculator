#ifndef EVALUATE_H
#define EVALUATE_H
#include "queue.h"
#include "mystack.h"
#include <iostream>
#include "string"
#include "stdlib.h"
#include <cctype>
#include <sstream>
#include "token.h"
using namespace std;


class Evaluate
{
public:
    Evaluate();

    Queue<Token*> Input(istream& in);

    double Eval(Queue<Token*> &evalme, int x);
};



Evaluate::Evaluate(){

}




#endif // EVALUATE_H


















