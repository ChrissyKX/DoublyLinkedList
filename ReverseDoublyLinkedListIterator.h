//
// Created by mfbut on 2/13/2019.
//

#ifndef LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"
template <typename T>
class DoublyLinkedList;

template<typename T>
class ReverseDoublyLinkedListIterator {
 public:
  ReverseDoublyLinkedListIterator(int p, const DoublyLinkedList<T>& s);
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

  //copy constructor
  ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator& orig);

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(ReverseDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  ReverseDoublyLinkedListIterator<T>& operator++(); //pre
  const ReverseDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ReverseDoublyLinkedListIterator<T>& operator--(); //pre
  const ReverseDoublyLinkedListIterator<T> operator--(int);//post

  //get a const reference to the value
  const T& operator*() const;

  //get a non-const reference to the value
  T& operator*();

  int getpos();

  virtual ~ReverseDoublyLinkedListIterator();

private:
    int pos;
    const DoublyLinkedList<T>& subject;
    DoubleLinkedNode<T>* cur;

};

template  <typename  T>
ReverseDoublyLinkedListIterator<T>::ReverseDoublyLinkedListIterator(int p, const DoublyLinkedList<T>& s):pos(p), subject(s) {
    if (p<0){
        cur = nullptr;
    }
    cur = s.gethead();
    if(p>0) {
        for (int i = 1; i <= p; i++) {
            cur = cur->getnext();
        }
    }
}

template <typename T>
ReverseDoublyLinkedListIterator<T>::ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator &orig) :pos(orig.pos), subject(orig.subject), cur(orig.cur){
}

template <typename T>
ReverseDoublyLinkedListIterator<T>::~ReverseDoublyLinkedListIterator(){
}

template <typename T>
bool ReverseDoublyLinkedListIterator<T>::operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const{
    if (!bool(*this) && !bool(rhs)){
        return true;
    }else if (&subject == &rhs.subject && pos == rhs.pos){
        return true;
    }else{
        return false;
    }
}

template <typename T>
bool ReverseDoublyLinkedListIterator<T>::operator!=( ReverseDoublyLinkedListIterator<T>& rhs) const{
    return !(*this == rhs) ;
}

template <typename T>
ReverseDoublyLinkedListIterator<T>::operator bool() const{
    return pos<subject.size() && pos>=0;
}

template <typename T>
ReverseDoublyLinkedListIterator<T>& ReverseDoublyLinkedListIterator<T>::operator++(){
    pos--;
    cur = cur->getpre();
    return *this;
}

template <typename T>
const ReverseDoublyLinkedListIterator<T> ReverseDoublyLinkedListIterator<T>::operator++ (int){
    ReverseDoublyLinkedListIterator<T> copy = ReverseDoublyLinkedListIterator(*this);
    ++(*this);
    return copy;
}

template <typename T>
ReverseDoublyLinkedListIterator<T>& ReverseDoublyLinkedListIterator<T>::operator--(){
    pos++;
    cur = cur->getnext();
    return *this;
}

template <typename T>
const ReverseDoublyLinkedListIterator<T> ReverseDoublyLinkedListIterator<T>::operator--(int){
    ReverseDoublyLinkedListIterator<T> copy = ReverseDoublyLinkedListIterator(*this);
    --(*this);
    return copy;
}

template <typename T>
const T& ReverseDoublyLinkedListIterator<T>::operator*() const{
    return cur->getval();
}

template <typename T>
T& ReverseDoublyLinkedListIterator<T>::operator*(){
    return cur->getval();
}

template  <typename T>
int ReverseDoublyLinkedListIterator<T>::getpos() {
    return pos;
}
#endif //LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
