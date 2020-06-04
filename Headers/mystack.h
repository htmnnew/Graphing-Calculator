#ifndef STACK_H
#define STACK_H

template <class T>
class Stack{

public:
    Stack();

    void Push(T addme);

    T Pop();

    bool Empty();

    node<T>* headacc();

private:
    node<T>* hptr;
    T item;
};


template <class T>
Stack<T>::Stack(){
    hptr = NULL;
}

template <class T>
void Stack<T>::Push(T addme){
    InsertHead(hptr,addme);
}

template <class T>
T Stack<T>::Pop(){
    if(hptr != NULL){
        T temp = hptr->item;
        RemoveHead(hptr);
        return temp;
    }
    else
        return NULL;
}

template <class T>
bool Stack<T>::Empty(){
    if(hptr == NULL)
        return true;
    else
        return false;
}

template <class T>
node<T>* Stack<T>::headacc(){
    return hptr;
}

#endif // STACK_H
