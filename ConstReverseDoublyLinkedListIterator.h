//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"

template <typename T>
class DoublyLinkedList;

template<typename T>
class ConstReverseDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods
public:
  ConstReverseDoublyLinkedListIterator(int p, const DoublyLinkedList<T>& s);

  //copy constructor
  ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator& orig);

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstReverseDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(ConstReverseDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  ConstReverseDoublyLinkedListIterator<T>& operator++(); //pre
  const ConstReverseDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ConstReverseDoublyLinkedListIterator<T>& operator--(); //pre
  const ConstReverseDoublyLinkedListIterator<T> operator--(int);//post

  //get a const reference to the value
  const T& operator*() const;

  int getpos();

  virtual ~ConstReverseDoublyLinkedListIterator();
  
private:
    int pos;
    const DoublyLinkedList<T>& subject;
    DoubleLinkedNode<T>* cur;
};

template <typename  T>
ConstReverseDoublyLinkedListIterator<T>::ConstReverseDoublyLinkedListIterator(int p, const DoublyLinkedList<T>& s):pos(p), subject(s){
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
ConstReverseDoublyLinkedListIterator<T>::ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator &orig) :pos(orig.pos), subject(orig.subject), cur(orig.cur){
}

template <typename T>
ConstReverseDoublyLinkedListIterator<T>::~ConstReverseDoublyLinkedListIterator() {
}

template <typename T>
bool ConstReverseDoublyLinkedListIterator<T>::operator==(const ConstReverseDoublyLinkedListIterator<T>& rhs) const{
  if (!bool(*this) && !bool(rhs)){
    return true;
  }else if (&subject == &rhs.subject && pos == rhs.pos){
    return true;
  }else{
    return false;
  }
}


template <typename T>
bool ConstReverseDoublyLinkedListIterator<T>::operator!=( ConstReverseDoublyLinkedListIterator<T>& rhs) const{
  return !(*this == rhs) ;
}

template <typename T>
ConstReverseDoublyLinkedListIterator<T>::operator bool() const{
  return pos<subject.size() && pos>=0;
}

template <typename T>
ConstReverseDoublyLinkedListIterator<T>& ConstReverseDoublyLinkedListIterator<T>::operator++(){
  pos--;
  cur = cur->getpre();
  return *this;
}

template <typename T>
const ConstReverseDoublyLinkedListIterator<T> ConstReverseDoublyLinkedListIterator<T>::operator++ (int){
  ConstReverseDoublyLinkedListIterator<T> copy = ConstReverseDoublyLinkedListIterator(*this);
  ++(*this);
  return copy;
}

template <typename T>
ConstReverseDoublyLinkedListIterator<T>& ConstReverseDoublyLinkedListIterator<T>::operator--(){
  pos++;
  cur = cur->getnext();
  return *this;
}

template <typename T>
const ConstReverseDoublyLinkedListIterator<T> ConstReverseDoublyLinkedListIterator<T>::operator--(int){
  ConstReverseDoublyLinkedListIterator<T> copy = ConstReverseDoublyLinkedListIterator(*this);
  --(*this);
  return copy;
}

template <typename T>
const T& ConstReverseDoublyLinkedListIterator<T>::operator*() const{
  return cur->getval();
}

template  <typename T>
int ConstReverseDoublyLinkedListIterator<T>::getpos(){
  return pos;
}

#endif //TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
