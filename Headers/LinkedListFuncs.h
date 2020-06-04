#ifndef LINKLISTFUNCS_H
#define LINKLISTFUNCS_H
#include <iostream>
using namespace std;



#include "node.h"

/*Preconditions:
 * Takes a node headpointer
 *Postconditions
 *The items of the nodes are printed on the screen
 */
template <class ITEM_TYPE>
ostream& Printlist(ostream &out, const node<ITEM_TYPE>* headPtr);


/*Preconditions:
 * Takes a headpointer by referance and an item
 *Postconditions
 * A new node is created with the passed item in it and added
 *  at the start of the main nodes
 */
template <class ITEM_TYPE>
void InsertHead(node<ITEM_TYPE>* &hPtr,ITEM_TYPE addme);
//Takes a number (insertThis) and inserts it at the head of the list


/*Preconditions:
 * Takes a headpointer and an item to search for
 *Postconditions
 * Returns a pointer of the node the has the searched item in it
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* Search(node<ITEM_TYPE>* hPtr,ITEM_TYPE searchfor);
//Takes a value (key) and returns the pointer to the node containing that item. Null if not found


/*Preconditions:
 * Takes a node pointer after which the new node must be inserted and the item
 *Postconditions
 * A new node is created and wth the given item in it, after the passed node
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>* afterthis,const ITEM_TYPE &item);
//Takes a value (insertThis) and a pointer to a node in the list (afterThis) and inserts the value after the designated node


/*Preconditions:
 * Takes  a node pointer to a list
 *Postconditions
 * Copies the list and returns a pointer to the new clone list
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* Copy(const node<ITEM_TYPE>* CopyMe);
//Takes a list (head) and returns a pointer to a linked list that is a copy of this list.


/*Preconditions:
 * Takes a headpointer to a list
 *Postconditions
 * All the nodes in the list are deleted
 */
template <class ITEM_TYPE>
void DeleteAll(node<ITEM_TYPE>* &hptr);
//Takes a list (head) and deletes all the nodes in the list


/*Preconditions:
 * Takes a headpointer to a list
 *Postconditions
 * The first node of the list is Deleted
 */
template <class ITEM_TYPE>
void DeleteHead(node<ITEM_TYPE>* &hptr);


/*Preconditions:
 * Takes a node pointer before which the new node must be inserted and the item
 * Takes a headpointer to figure out where the previous node is
 *Postconditions
 * A new node is created with the passed item in it and inserted to the
 *  given location
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>* hptr,node<ITEM_TYPE>* beforethis,ITEM_TYPE item);
//Takes aa value (insertThis), and a pointer to a node in the list (beforeThis) and inserts the value before the designated node.


/*Preconditions:
 * Takes a node pointer to the node that needs to be deleted
 *Postconditions
 * The passed node is Deleted
 */
template <class ITEM_TYPE>
void Delete(node<ITEM_TYPE>* &hptr, ITEM_TYPE DeleteThis);
//Takes a pointer to a node in the list (deleteThis) and removes that node from the list.
//Deletes the node.

/*Preconditions:
 * Takes a pointer the the node that need to be removed from the list
 *Postconditions
 * The node is removed from the list and is returned
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* Remove(node<ITEM_TYPE>* &hptr, node<ITEM_TYPE>* &RemoveThis);


/*Preconditions:
 * Takes a pointer to the head of the list
 *Postconditions
 * The node is removed from the list and is returned
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* RemoveHead(node<ITEM_TYPE>* &hptr);


/*Preconditions:
 * Takes a head pointed to the node list,
 *  takes a pointer to the node find the previous one of it
 *Postconditions
 * A pointer to the previous node of PrevofThis is returned
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* Previous(node<ITEM_TYPE>* hptr,node<ITEM_TYPE>* PrevofThis);
//Takes a pointer to an item in the list (previousToThis) and returns a pointer
//to the node before the designated node. Returns NULL if the node is the first node in the list.




/*Preconditions:
 * Takes a headpointer to a list and an index
 *Postconditions
 * Returns a pointer to the node with corresponding index
 */
template <class ITEM_TYPE>
node<ITEM_TYPE>* Atindex(node<ITEM_TYPE>* hptr,int index); //gives you a pointer to that node
//Takes a position (n) and returns a pointer to the nth position in the list


/*Preconditions:
 * Takes a headpointer to a list and an item
 *Postconditions
 * returns the index of the given item
 */
template <class ITEM_TYPE>
int index(node<ITEM_TYPE>* hptr,ITEM_TYPE item); // gives the index of the given item


/*Preconditions:
 * Takes a headpointer to a list and an item
 *Postconditions
 * Returns a pointer to the previous node of where the item belongs to
 */
//given item tell where it belongs by returning item before
//return null for the beggining of the list
template <class ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* hptr,ITEM_TYPE item);
//Takes a value (item) and returns a pointer to the node after which the item belongs in the list.
//Assumes the list is sorted. Returns NULL if the item belongs at the head of the list.

/*Preconditions:
 * Takes a headpointer to a list and an item
 *Postconditions
 * Inserts the given item in the corresponding place
 */
//Copies are OKAY
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE>* &hptr,const ITEM_TYPE item);


/*Preconditions:
 * Takes a headpointer to a list and an item
 *Postconditions
 * If the item is unique it gets added to the list in the right place
 */
//COPIES ARE NOT OKAY
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertUniqueSorted(node<ITEM_TYPE>* hptr, const ITEM_TYPE item);

//
template <class ITEM_TYPE>
node<ITEM_TYPE>* ConcatLow(const node<ITEM_TYPE>* left, const node<ITEM_TYPE>* right);

//
template <class ITEM_TYPE>
node<ITEM_TYPE>* FindLastNode(node<ITEM_TYPE>* hptr);

//
template <class ITEM_TYPE>
int lenght(node<ITEM_TYPE>* hptr);







template <class ITEM_TYPE>
ostream& Printlist(ostream& out,const node<ITEM_TYPE>* headPtr){
    const node<ITEM_TYPE>* Walker = headPtr;

    while (Walker){
        out <<"| "<< Walker -> item << " |";
        Walker = Walker ->next;
    }
    return out;
}

template <class ITEM_TYPE>
void InsertHead(node<ITEM_TYPE>* &hPtr,ITEM_TYPE addme){
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(addme);

    temp ->next = hPtr;
    hPtr = temp;

}

template <class ITEM_TYPE>
node<ITEM_TYPE>* Search(node<ITEM_TYPE>* hPtr,ITEM_TYPE searchfor){
    node<ITEM_TYPE>* temp = hPtr;

    while(temp ->item != searchfor && temp != NULL){
        temp = temp ->next;
    }

    return temp;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>* afterthis,const ITEM_TYPE &item){
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(item);

    temp ->next = afterthis ->next;
    afterthis ->next = temp;

    return temp;

}

template <class ITEM_TYPE>
node<ITEM_TYPE>* Copy(const node<ITEM_TYPE>* CopyMe){
    node<ITEM_TYPE>* Clone = new node<ITEM_TYPE>(CopyMe->item);
    node<ITEM_TYPE>* NewWalker = Clone;

    const node<ITEM_TYPE>* Mainwalker = CopyMe;
    Mainwalker = Mainwalker->next;

    while(Mainwalker){
        node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(Mainwalker->item);
        NewWalker->next = temp;
        NewWalker = NewWalker->next;
        Mainwalker = Mainwalker->next;
    }
    return Clone;
}

template <class ITEM_TYPE>
void DeleteAll(node<ITEM_TYPE>* &hptr){
    while(hptr){
        DeleteHead(hptr);
    }
}

template <class ITEM_TYPE>
void DeleteHead(node<ITEM_TYPE>* &hptr){
    delete RemoveHead(hptr);
}


template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>* hptr,node<ITEM_TYPE>* beforethis,ITEM_TYPE item){
    node<ITEM_TYPE>* temp = Previous(hptr,beforethis);
    InsertAfter(temp,item);

    return temp;
}

template <class ITEM_TYPE>
void Delete(node<ITEM_TYPE>* &hptr,ITEM_TYPE DeleteThis){
    node<ITEM_TYPE>* walker = hptr;
        if(walker->item==DeleteThis){
            delete RemoveHead(hptr);
        }

        else{
            node<ITEM_TYPE>* DelThis = Search(hptr,DeleteThis);
            delete Remove(hptr,DelThis);
       }

}

template <class ITEM_TYPE>
node<ITEM_TYPE>* Remove(node<ITEM_TYPE>* &hptr,node<ITEM_TYPE>* &RemoveThis){
    if(Previous(hptr,RemoveThis) != NULL){
        node<ITEM_TYPE>* tempPrev = Previous(hptr,RemoveThis);
        node<ITEM_TYPE>* tempAfter = RemoveThis->next;
        node<ITEM_TYPE>* temp = RemoveThis;
        tempPrev->next = tempAfter;

        return temp;
    }
    else if(RemoveThis->next == NULL){
        node<ITEM_TYPE>* tempPrev = Previous(hptr,RemoveThis);
        node<ITEM_TYPE>* temp = RemoveThis;
        tempPrev->next = NULL;

        return temp;
    }
    else{
        return RemoveHead(hptr);
    }
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* RemoveHead(node<ITEM_TYPE>* &hptr){
    node<ITEM_TYPE>* temp = hptr;
    if(hptr != NULL){
        hptr = hptr->next;
    }

    return temp;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* Previous(node<ITEM_TYPE>* hptr,node<ITEM_TYPE>* PrevofThis){
    node<ITEM_TYPE>* walker = hptr;
    while(walker){
        if(walker->next == PrevofThis)
            return walker;
        else
            walker = walker->next;
    }
    return NULL;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* Atindex(node<ITEM_TYPE>* hptr, int index){
    node<ITEM_TYPE>* walker = hptr;
    for(int i = index;i>0;i--){
        walker = walker->next;
    }
    return walker;
}

template <class ITEM_TYPE>
int index(node<ITEM_TYPE>* hptr,ITEM_TYPE item){
    node<ITEM_TYPE>* walker = hptr;
    int counter = 0;

    while(walker){
        if(walker->item == item)//first node
            return counter+1;
        else{
            walker = walker->next;
            counter++;
        }
    }
    return 0;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* hptr, ITEM_TYPE item){
    node<ITEM_TYPE>* walkerPrev = hptr;
    node<ITEM_TYPE>* walker = hptr->next;

    while(walker && walker->item < item){
        walker = walker->next;
        walkerPrev = walkerPrev->next;
    }
    return walkerPrev;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE>* &hptr,const ITEM_TYPE item){
    node<ITEM_TYPE>* AfterThis = WhereThisGoes(hptr,item);
    return InsertAfter(AfterThis,item);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertUniqueSorted(node<ITEM_TYPE>* hptr,const  ITEM_TYPE item){
    node<ITEM_TYPE>* place = WhereThisGoes(hptr,item);
    node<ITEM_TYPE>* temp;

    if(place->item != item){
        temp = InsertAfter(place,item);
    }
    else{
        temp = NULL;
    }

    return temp;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* ConcatLow(const node<ITEM_TYPE>* left,const node<ITEM_TYPE>* right){
      node<ITEM_TYPE>* temp = new node<ITEM_TYPE>();
      temp = Copy(left);
      node<ITEM_TYPE>* tempSecPart = FindLastNode(temp);
      tempSecPart = Copy(right);

      return temp;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* FindLastNode(node<ITEM_TYPE>* hptr){
    node<ITEM_TYPE>* walker = hptr;

    while(walker->next != NULL){
      walker = walker->next;
    }
    return walker;
}

template <class ITEM_TYPE>
int Lenght(node<ITEM_TYPE>* hptr){
    node<ITEM_TYPE>* walker = hptr;
    int i = 0;

    while(walker){
      walker = walker->next;
      i++;
    }
    return i;
}









#endif // LINKLISTFUNCS_H











