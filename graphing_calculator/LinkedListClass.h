#ifndef LINKLIST_H
#define LINKLIST_H
#include "LinkedListFuncs.h"
#include "node.h"

template <class ITEM_TYPE>
class LinkList
{
public:
    LinkList();


        //Big 3
        LinkList(const LinkList<ITEM_TYPE>& A);

        LinkList& operator =(const LinkList<ITEM_TYPE>& rhs);

        ~LinkList();


    ostream& PrintlistC(ostream &out);

    void InsertHeadC(ITEM_TYPE addme);

    node<ITEM_TYPE>* SearchC(ITEM_TYPE searchfor);

    node<ITEM_TYPE>* InsertAfterC(node<ITEM_TYPE>* afterthis,const ITEM_TYPE &item);

    node<ITEM_TYPE>* CopyC()const;

    void DeleteAllC();

    void DeleteHeadC();

    node<ITEM_TYPE>* InsertBeforeC(node<ITEM_TYPE>* beforethis, ITEM_TYPE item);

    void DeleteC(ITEM_TYPE DeleteThis);

    node<ITEM_TYPE>* RemoveC(node<ITEM_TYPE>* &RemoveThis);

    node<ITEM_TYPE>* RemoveHeadC();

    node<ITEM_TYPE>* PreviousC(node<ITEM_TYPE>* PrevofThis);

    node<ITEM_TYPE>* AtindexC(int index);

    int indexC(ITEM_TYPE item);

    node<ITEM_TYPE>* WhereThisGoesC(ITEM_TYPE item);

    node<ITEM_TYPE>* InsertSortedC(const ITEM_TYPE item);

    node<ITEM_TYPE>* InsertUniqueSortedC(const ITEM_TYPE item);

    node<ITEM_TYPE>* FindLastNodeC()const;

    template <typename T>
    friend LinkList operator +(const LinkList<T>& left,const LinkList<T>& right);

    node<ITEM_TYPE>* hptracces();

    bool IsEmpty();




    node<ITEM_TYPE>* hptr;
};


template <class ITEM_TYPE>
LinkList<ITEM_TYPE>::LinkList(){
    hptr = NULL;
}

//Big 3
    //Copy Const
template <class ITEM_TYPE>
LinkList<ITEM_TYPE>::LinkList(const LinkList& A){
       A.CopyC();
}

    //Assign opr
template <class ITEM_TYPE>
LinkList<ITEM_TYPE>& LinkList<ITEM_TYPE>::operator =(const LinkList<ITEM_TYPE>& A){
   if(A.hptr != NULL){
    DeleteAllC();
    hptr = Copy(A.hptr);
   }
    return *this;
}

    //Distractor
template <class ITEM_TYPE>
LinkList<ITEM_TYPE>::~LinkList(){
    node<ITEM_TYPE>* temp;

    node<ITEM_TYPE>* head = hptr;

    while(head != NULL){

        temp = head;
        head = head->next;


        delete temp;
    }
}



template <class ITEM_TYPE>
ostream& LinkList<ITEM_TYPE>::PrintlistC(ostream &out){
    return Printlist(out,hptr);
}

template <class ITEM_TYPE>
void LinkList<ITEM_TYPE>::InsertHeadC(ITEM_TYPE addme){
    InsertHead(hptr,addme);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::SearchC(ITEM_TYPE searchfor){

    return Search(hptr,searchfor);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::InsertAfterC(node<ITEM_TYPE>* afterthis,const ITEM_TYPE &item){
    return InsertAfter(afterthis,item);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::CopyC() const{
    return Copy(hptr);
}

template <class ITEM_TYPE>
void LinkList<ITEM_TYPE>::DeleteAllC(){
    DeleteAll(hptr);
}

template <class ITEM_TYPE>
void LinkList<ITEM_TYPE>::DeleteHeadC(){
    DeleteHead(hptr);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::InsertBeforeC(node<ITEM_TYPE>* beforethis,ITEM_TYPE item){
    return InsertBefore(hptr,beforethis,item);
}

template <class ITEM_TYPE>
void LinkList<ITEM_TYPE>::DeleteC(ITEM_TYPE DeleteThis){
    Delete(hptr,DeleteThis);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::RemoveC(node<ITEM_TYPE>* &RemoveThis){
   return Remove(hptr,RemoveThis);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::RemoveHeadC(){
    return RemoveHead(hptr);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::PreviousC(node<ITEM_TYPE>* PrevofThis){
    return Previous(hptr,PrevofThis);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::AtindexC(int index){
    return Atindex(hptr,index);
}

template <class ITEM_TYPE>
int LinkList<ITEM_TYPE>::indexC(ITEM_TYPE item){
    return index(hptr,item);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::WhereThisGoesC(ITEM_TYPE item){
    return WhereThisGoes(hptr,item);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::InsertSortedC(const ITEM_TYPE item){
    return InsertSorted(hptr,item);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::InsertUniqueSortedC(const ITEM_TYPE item){
    return InsertUniqueSorted(hptr,item);
}

template <typename T>
LinkList<T> operator+(const LinkList<T>& left,const LinkList<T>& right){
     LinkList<T> result;
     result.hptr = ConcatLow(left.hptr,right.hptr);
     return result;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::FindLastNodeC()const{
    return FindLastNode(hptr);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* LinkList<ITEM_TYPE>::hptracces(){
    return hptr;
}

template <class ITEM_TYPE>
bool LinkList<ITEM_TYPE>::IsEmpty(){
    if(hptr == NULL)
        return true;
    else
        return false;
}




#endif // LINKLIST_H











