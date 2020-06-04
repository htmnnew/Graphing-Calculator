#ifndef QUEUE_H
#define QUEUE_H


template <class T>
class Queue
{
public:
    Queue();


    //Big 3
    ~Queue();
    Queue(const Queue &rhd);
    Queue& operator =(const Queue &rhs);

    void Pushqueue(T addme);
    T Popqueue();
    bool Emptyqueue();

    LinkList<T> Listacc();
    node<T>* EndAcccess();

    void Print();

private:

    LinkList<T> List;

    node<T>* TheEnd = NULL;
};

//DISTRACTOR
template <class T>
Queue<T>::~Queue(){

}

//COPY CONSTRACTOR
template <class T>
Queue<T>::Queue(const Queue<T> &rhs){
    node<T>* temp;

    node<T>* front = List.hptracces();

    while(!List.IsEmpty()){

        temp = front;

        front = front->next;
        delete temp;
    }

    List = rhs.List;
    TheEnd = List.FindLastNodeC();

}

//ASSIGNMENT OPERATOR
template <class T>
Queue<T>& Queue<T>::operator =(const Queue<T> &rhs){
    node<T>* temp;

    node<T>* front = List.hptr;

    while(!List.hptr != NULL){
        temp = front;

        front = front->next;
        delete temp;
    }

    List = rhs.List;

    TheEnd = List.FindLastNodeC();

    return *this;
}

template <class T>
Queue<T>::Queue(){

}

template <class T>
void Queue<T>::Pushqueue(T addme){
    if(List.IsEmpty() == false){
        List.InsertAfterC(TheEnd,addme);
        TheEnd = TheEnd->next;
    }
    else{
        node<T>* head = List.hptracces();
        List.InsertHeadC(addme);
        head = List.hptracces();
        TheEnd = head;
    }
}

template <class T>
T Queue<T>::Popqueue(){
    node<T>* thiss = List.RemoveHeadC();
    return thiss->item;
}

template <class T>
LinkList<T> Queue<T>::Listacc(){
    return List;
}

template <class T>
node<T>* Queue<T>::EndAcccess(){
    return TheEnd;
}

template <class T>
void Queue<T>::Print(){
    List.PrintlistC(cout);
}

template <class T>
bool Queue<T>::Emptyqueue(){
    if(List.IsEmpty() == true)
        return true;
    else
        return false;
}

#endif // QUEUE_H




















