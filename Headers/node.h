#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

//implementation of a simple node
//containing an item and a pointer to the next item
template <class ITEM_TYPE>
struct node{


public:
    ITEM_TYPE item;
    node* next;
    node();
    node(ITEM_TYPE n);
};

template <class ITEM_TYPE>
node<ITEM_TYPE>::node(){
    item = 0;
    next = NULL;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>::node(ITEM_TYPE n){
    item = n;
    next = NULL;
}



#endif // NODE_H
