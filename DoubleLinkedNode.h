//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

//the class that represents a node in the list

template<typename T>
class DoubleLinkedNode {
public:
    using NP = DoubleLinkedNode<T>*;
    //construct a node in the middle
    DoubleLinkedNode(NP pr,const T&v, NP ne);

    const T& getval() const;

    T& getval();

    NP getpre();

    void setpre(NP n);

    NP getnext();

    void setnext(NP n);




    virtual ~DoubleLinkedNode();



private:
    T value;
    NP pre = nullptr;
    NP next = nullptr;
};


template<typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(DoubleLinkedNode<T>* pr, const T& v, DoubleLinkedNode<T>* ne):value(v),pre(pr),next(ne) {}

template <typename T>
DoubleLinkedNode<T>::~DoubleLinkedNode(){
}

template <typename T>
const T& DoubleLinkedNode<T>::getval() const{
    return value;
}

template <typename T>
T& DoubleLinkedNode<T>::getval() {
    return value;
}

template <typename T>
DoubleLinkedNode<T>* DoubleLinkedNode<T>::getpre() {
    return pre;
}

template  <typename T>
void DoubleLinkedNode<T>::setpre(DoubleLinkedNode<T>* n) {
    pre = n;
}

template <typename T>
DoubleLinkedNode<T>* DoubleLinkedNode<T>::getnext() {
    return next;
}

template  <typename T>
void DoubleLinkedNode<T>::setnext(DoubleLinkedNode<T>* n) {
    next = n;
}



#endif //LINKEDLIST_DOUBLELINKEDNODE_H
