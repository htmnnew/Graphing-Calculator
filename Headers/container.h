#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>

using namespace std;

template <typename T>
class container
{
public:

    container();

    void Add(T something);

    T& operator[](int i);

    int Lenght();

private:

    T a[MAX_SIZE];

    int Numused = 0;
};

template <typename T>
container<T>::container(){

}

template <typename T>
void container<T>::Add(T something){
    a[Numused] = something;
    Numused++;
}

template <typename T>
T& container<T>::operator [](int i){
    return a[i];
}

template <typename T>
int container<T>::Lenght(){
    return Numused;
}

#endif // CONTAINER_H








