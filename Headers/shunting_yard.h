#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include <iostream>
#include "string"
#include "stdlib.h"
#include <cctype>
#include <sstream>

using namespace std;



//The ShuntingYard Algorithm
//Takes the tokenized input by user and rearranges it to Reverse Polish Notation
Queue<Token*> ShuntingYard(Queue<Token*> DoMe){
    Queue<Token*> OutputQueue;  //Main Output
    Stack<Token*> OperatorStack;//To hold operators


    while(DoMe.Emptyqueue()==false){//Input Queue is not empty

        Token* Temp = DoMe.Popqueue();//pop

            if(Temp->Type() == 1 || Temp->Type() == 3){//Number or 'x'
                OutputQueue.Pushqueue(Temp);
            }

            else if(Temp->Type() == 2){//Operator
                  if(OperatorStack.Empty()==false){//Stack isnt empty
                        Token* Oper = OperatorStack.Pop();
                        int OperVal = Oper->getVal();
                        OperatorStack.Push(Oper);

                        while(OperVal >= Temp->getVal()){//Stack has Higher prec
                            OutputQueue.Pushqueue(OperatorStack.Pop());//Pop stack Push output
                            if(OperatorStack.Empty() == false){ //If stack not empty
                                Oper = OperatorStack.Pop();     //Pop Another
                                OperVal = Oper->getVal();
                                OperatorStack.Push(Oper);
                            }
                            else{//If Stack Empty
                                break;
                            }
                        }
                            OperatorStack.Push(Temp);//Push operator in if stack is empty
                  }
                  else
                    OperatorStack.Push(Temp);

            }

            else if(Temp->Type() == 4){//Left Parentasis
                OperatorStack.Push(Temp);
            }

            else if(Temp->Type() == 5){//Right Parentasis
                Token* popoper = OperatorStack.Pop();
                int StVal = popoper->getVal();
                OperatorStack.Push(popoper);

                while(StVal != 4){//while no left bracket keep poping
                    OutputQueue.Pushqueue(OperatorStack.Pop());

                    if(OperatorStack.Empty() == false){
                        popoper = OperatorStack.Pop();//Pop more
                        StVal = popoper->getVal();
                        OperatorStack.Push(popoper);
                    }
                    else
                        break;
                }
                popoper = OperatorStack.Pop();
            }

            else if(Temp->Type() == 6){//Function
                  if(OperatorStack.Empty()==false){//Stack isnt empty
                        Token* Oper = OperatorStack.Pop();
                        int OperVal = Oper->getVal();
                        OperatorStack.Push(Oper);

                        while(OperVal >= Temp->getVal()){//Stack has Higher prec
                            OutputQueue.Pushqueue(OperatorStack.Pop());//Push Stack in output
                            if(OperatorStack.Empty() == false){ //If stack not empty
                                Oper = OperatorStack.Pop();     //Pop Another
                                OperVal = Oper->getVal();
                                OperatorStack.Push(Oper);
                            }
                            else{//If Stack Empty
                                break;
                            }
                        }
                            OperatorStack.Push(Temp);
                  }
                  else
                    OperatorStack.Push(Temp);
            }

            else
                cout<<endl<<"Wrong Input!!!"<<endl;

    }//Input Queue is empty

    while(OperatorStack.Empty() == false){//at the end keep poping all operators from stack into queue
         OutputQueue.Pushqueue(OperatorStack.Pop());
    }
    return OutputQueue;
}




#endif // SHUNTING_YARD_H
