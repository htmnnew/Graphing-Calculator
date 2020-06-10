#include <iostream>
#include <SFML/Graphics.hpp>
#include <sfml/Audio.hpp>
#include <cmath>
#include "node.h"
#include "LinkedListFuncs.h"
#include "LinkedListClass.h"
#include "mystack.h"
#include "queue.h"
#include "evaluatelower.h"
#include "token.h"
#include "childnumbers.h"
#include "childvariables.h"
#include "childfunctions.h"
#include "childoperators.h"
#include "childpLarentasis.h"
#include "childpRarentasis.h"
#include "childvariables.h"
#include "shunting_yard.h"
#include "coordinates.h"

// IF SFML CAUSES ISSUES WITH THE HEADERS MAKE SURE THE COMPILER AND SFML ARE CORRECT VERSION



using namespace std;
using namespace sf;


const int SCREEN_WIDTH=1000;
const int SCREEN_HEIGHT=1000;

const int Numofcells = 10;//Number of grids horizonally and vertically


//Evaluate, takes a queue of token pointers and 'x' for variable and returns a double
double Eval(Queue<Token*> evalme,double x){
    double answer;
    Stack<Token*> A;
    Token* tempQ;


    while(evalme.Emptyqueue() == false){ //While queue is not empty

        tempQ = evalme.Popqueue(); //pop from queue

        if(tempQ->Type() == 1){ //if number
            A.Push(tempQ); //push in stack
        }//end if number
        else if(tempQ->Type() == 3){ //if 'x'
            if(tempQ->getVal() == -1){ //handles negative sign
                x = -x;
                Token* variable = new numbers(x);
                A.Push(variable);
            }
            Token* variable = new numbers(x);
            A.Push(variable); //push in stack
        }//end if x
        else if(tempQ->Type() == 2){  //if operator
             double temp;
             double first;
             double second;

             Token* number1 = A.Pop();//pop stack
             first = number1->getVal();
             Token* number2 = A.Pop();//pop stack
             second = number2->getVal();

                       if(tempQ->GetFace() == '+'){
                           temp = second + first;
                           Token* tempNumber = new numbers(temp); //create new number object
                           A.Push(tempNumber);    //push back in stack
                       }
                       else if(tempQ->GetFace() == '-'){
                           temp = second - first;//do math
                           Token* tempNumber = new numbers(temp);  //create new number object
                           A.Push(tempNumber);    //push back in stack
                       }
                       else if(tempQ->GetFace() == '*'){
                           temp = second * first;//do math
                           Token* tempNumber = new numbers(temp);  //create new number object
                           A.Push(tempNumber);    //push back in stack
                       }
                       else if(tempQ->GetFace() == '/'){
                           if(first != 0){
                                temp = second / first;
                                Token* tempNumber = new numbers(temp); //create new number object
                                A.Push(tempNumber);    //push back in stack
                           }
                       }
        }//end if operator
        else if(tempQ->Type() == 6){ //function
            double temp;
            double first;
            double second;

                      if(tempQ->GetFace() == 'S'){ //Sine
                          Token* number1 = A.Pop();//pop stack
                          first = number1->getVal();
                          temp = sin(first);

                          Token* tempNumber = new numbers(temp); //create new number object
                          A.Push(tempNumber);    //push back in stack
                      }
                      else if(tempQ->GetFace() == 'C'){ //Cosine
                          Token* number1 = A.Pop();//pop stack
                          first = number1->getVal();
                          temp = cos(first);

                          Token* tempNumber = new numbers(temp); //create new number object
                          A.Push(tempNumber);    //push back in stack
                      }
                      else if(tempQ->GetFace() == 'T'){ //Tangent
                          Token* number1 = A.Pop();//pop stack
                          first = number1->getVal();
                          temp = tan(first);

                          Token* tempNumber = new numbers(temp); //create new number object
                          A.Push(tempNumber);    //push back in stack
                      }
                      else if(tempQ->GetFace() == 'H'){ //Max(x,y)
                          Token* number1 = A.Pop();//pop stack
                          first = number1->getVal();
                          Token* number2 = A.Pop();//pop stack
                          second = number2->getVal();

                          temp = max(first,second);
                          Token* tempNumber = new numbers(temp); //create new number object
                          A.Push(tempNumber);    //push back in stack
                      }
                      else if(tempQ->GetFace() == 'L'){ //Min(x,y)
                          Token* number1 = A.Pop();//pop stack
                          first = number1->getVal();
                          Token* number2 = A.Pop();//pop stack
                          second = number2->getVal();

                          temp = min(first,second);
                          Token* tempNumber = new numbers(temp); //create new number object
                          A.Push(tempNumber);    //push back in stack
                      }
        }//end if operator
    }//Queue is emptied
    answer = A.Pop()->getVal(); //last item in stack
    return answer;
}


//Takes a sting as input, converts it into objects, makes token pointers
//points the pointers to new objects, stores the pointers in queue, returns queue
Queue<Token*> Input(istream &in){
    Queue<Token*> QInputs; //Main input to be returned
    string strinput; //entered cin by user gets stored here temporarily

    while(strinput != '='){//while the expression isn't over
        Token* token;

        in >> strinput;//string is coming in

        if(isdigit(strinput[0])){//it's a number
            double value = stof(strinput);
            token = new numbers(value);
            QInputs.Pushqueue(token);
        }
        else if (strinput == '#'){//it's a '-' sign
            in >> strinput;//pop extra string and add nigative sign to it
            if(isdigit(strinput[0])){//it's a number
                double value = stof(strinput);
                token = new numbers(-value);//create negative of number
                QInputs.Pushqueue(token);
            }
            else if (strinput == 'x'){//it's a variable
                token = new variable(-1);//create negative of variable
                QInputs.Pushqueue(token);
            }
        }
        else if (strinput == '+'){//it's a '+' Operator
            token = new operators('+',2);
            QInputs.Pushqueue(token);
        }
        else if (strinput == '-'){//it's a '-' Operator
            token = new operators('-',2);
            QInputs.Pushqueue(token);
        }
        else if (strinput == '/'){//it's a '/' Operator
            token = new operators('/',3);
            QInputs.Pushqueue(token);
        }
        else if (strinput == '*'){//it's a '*' Operator
            token = new operators('*',3);
            QInputs.Pushqueue(token);
        }
        else if (strinput == 'x'){//it's a variable
            token = new variable();
            QInputs.Pushqueue(token);
        }
        else if (strinput == '('){//it's a '('
            token = new Lparent();
            QInputs.Pushqueue(token);
        }
        else if (strinput == ')'){//it's a ')'
            token = new Rparent();
            QInputs.Pushqueue(token);
        }
        else if (strinput == "Sin"){//it's a Sin
            token = new functions('S',4);
            QInputs.Pushqueue(token);
        }
        else if (strinput == "Cos"){//it's a Sin
            token = new functions('C',4);
            QInputs.Pushqueue(token);
        }
        else if (strinput == "Tan"){//it's a Sin
            token = new functions('T',4);
            QInputs.Pushqueue(token);
        }
        else if (strinput == "Min"){//it's a Min
            token = new functions('L',4);
            QInputs.Pushqueue(token);
        }
        else if (strinput == "Max"){//it's a Max
            token = new functions('H',4);
            QInputs.Pushqueue(token);
        }
        else {

        }
    }//Expression is finished
    return QInputs;
}


//Takes the input, low/high range, increments and zoom
//generates a queue of coordinates ready to be graphed
Queue<Coordinates*> PlotExpression (Queue<Token*> input,double low, double high, double increments,double Zoom){

    Queue<Token*> RPN = ShuntingYard(input);//returns the input in a "ready to evaluate" form
    Queue<Coordinates*> ToGraph;//Main queue of coordinate* that is returned
    Coordinates* A;
    double y;
    double x;

    for(x = low; x < high; x += (-low+high)/increments){//generates coordinates and pushes in queue
         y = Eval(RPN,x);
         A = new Coordinates(x*Zoom,y*Zoom);//zoom factor is multiplied here
         ToGraph.Pushqueue(A);
    }
    return ToGraph;
}



//Plotter, takes x and y and graphs the point on the window
void Plotting(RenderWindow& window,double x,double y){
/*Create Point*/RectangleShape Point;
/*Set Color*/   Point.setFillColor(Color::Red); //sets color
/*Set Size*/    Point.setSize(Vector2f(2,2)/*an xy coordinate using float*/); //sets size
/*Set Position*/Point.setPosition(Vector2f((SCREEN_WIDTH/2 - 1) + (x*20),(SCREEN_HEIGHT/2 - 1) - (y*20))); //changes origin to center from top left and adds x,y
        window.draw(Point);
}






//----------------------------------------------------------

int main(){

                             double Zoom = 1; //default zooming factor
/*Set the range on left*/    double lowrange  = -500;
/*Set the range on right*/   double highrange =  500;
/*Number of points graphed*/ double incr      = 100000;


/*Functions to test
 * Sin x * cos ( Max 201 65  * x )
 * x * x
 * x * x * x
 * 1 / x
 * Sin x
 * x * Cos x
 * 1 / Sin x
 * ( 1 / x ) * Tan x
 * Tan x / ( 1 / Tan x )=
 * ( 1 / x ) * Sin x
 * 34oi3hg4o3ibv
 */

//--------------------------------------

    //Takes the expression as an input
    Queue<Token*> input = Input(cin);

    //Takes the input,max-min range, and zoom factor
    //Returns a coordiante pointer queue to be graphed
    Queue<Coordinates*> GraphMe = PlotExpression(input,lowrange,highrange,incr,Zoom);

    //Creating the main window
    RenderWindow window; //creates the main window
    window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graph");

//--------------------------------------





        while (window.isOpen())//GAME LOOP
            {

                window.clear(); //clears the screen
                Event event;
                while (window.pollEvent(event)) //EVENT LOOP
                {
                    if (event.type==Event::Closed)
                    {
                        window.close();
                    }

                    else if (event.type==Event::KeyPressed)
                    {
                        switch (event.key.code)
                        {
                        case Keyboard::Escape:
                            window.close();
                            break;

                        case Keyboard::Add:{
                            Zoom += 0.7;
                           GraphMe = PlotExpression(input,lowrange,highrange,incr,Zoom);
                        }

                        case Keyboard::Subtract:
                            if(Zoom > 0 ){
                                Zoom -= 0.2;
                                GraphMe = PlotExpression(input,lowrange,highrange,incr,Zoom);
                            }
                            break;
                        default:
                            break;

                        }//end of switch (event.key.code)

                    }// end of else if (event.type==Event::KeyPressed)

                }//end of while (window.pollEvent(event))


//BACKGROUND-------------------------------------
                RectangleShape Background;
                Background.setFillColor(Color(200,200,100,255));
                Background.setSize(Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT));
                window.draw(Background);

//GRID------------------------------------

                for(int i= -1; i < Numofcells ; i++){
                    for(int j = -1; j < Numofcells + 1; j++){
                        RectangleShape mybox; //A rectangle shape
                        mybox.setFillColor(Color::White); //sets color
                        mybox.setSize(Vector2f(SCREEN_HEIGHT/Numofcells - 1,SCREEN_HEIGHT/Numofcells - 1)); //sets size
                        mybox.setPosition(i*(SCREEN_HEIGHT/Numofcells),j*(SCREEN_HEIGHT/Numofcells)); //sets position using the upper left corner of the box by default
                        window.draw(mybox);
                    }
                }


//Axis-------------------------------------

                //YAxis
                RectangleShape Yaxis;
                Yaxis.setFillColor(Color::Black); //sets color
                Yaxis.setSize(Vector2f(1,SCREEN_HEIGHT)/*an xy coordinate using float*/); //sets size
                Yaxis.setPosition(Vector2f(SCREEN_HEIGHT/2,0)); //sets position using the upper left corner of the box by default
                window.draw(Yaxis);

                //XAxis
                RectangleShape Xaxis;
                Xaxis.setFillColor(Color::Black); //sets color
                Xaxis.setSize(Vector2f(SCREEN_HEIGHT,1)/*an xy coordinate using float*/); //sets size
                Xaxis.setPosition(Vector2f(0,SCREEN_HEIGHT/2)); //sets position using the upper left corner of the box by default
                window.draw(Xaxis);

 //The Main Grapher-------------------------

                //This graphes the generated points over everything
                Queue<Coordinates*> PlsFix = GraphMe;

                while(!PlsFix.Emptyqueue()){
                    Coordinates* A = PlsFix.Popqueue();
                    Plotting(window,A->x,A->y);//Graphs the given Coordinate
                    //cout<<"HELLO";
                 }


                //--------------------------------------


                window.display(); //displays everything drawn


            }// end of while (window.isOpen())

    return 0;
}








