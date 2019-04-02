//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"

template <typename T>
class DoublyLinkedList;
template<typename T>
class ConstDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

 public:
  ConstDoublyLinkedListIterator(int p, const DoublyLinkedList<T>& s);

  ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator& orig);
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  ConstDoublyLinkedListIterator<T>& operator++(); //pre
  const ConstDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ConstDoublyLinkedListIterator<T>& operator--(); //pre
  const ConstDoublyLinkedListIterator<T> operator--(int); //post

  //get a const reference to the value
  const T& operator*() const;

  //get the position
  int getpos();

  virtual ~ConstDoublyLinkedListIterator();

private:
    int pos;
    const DoublyLinkedList<T>& subject;
    DoubleLinkedNode<T>* cur;

};

template  <typename T>
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator(int p, const DoublyLinkedList<T>& s):pos(p),subject(s){
  if(p<0){
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
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator &orig):pos(orig.pos), subject(orig.subject), cur(orig.cur){
}

template <typename T>
ConstDoublyLinkedListIterator<T>::~ConstDoublyLinkedListIterator() {
}

template <typename T>
bool ConstDoublyLinkedListIterator<T>::operator==(const ConstDoublyLinkedListIterator<T>& rhs) const{
  if (!bool(*this) && !bool(rhs)){
    return true;
  }else if (&subject == &rhs.subject && pos == rhs.pos){
    return true;
  }else{
    return false;
  }
}

template <typename T>
bool ConstDoublyLinkedListIterator<T>::operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const{
   return !(*this == rhs) ;
}

template <typename T>
ConstDoublyLinkedListIterator<T>::operator bool() const{
   return pos<subject.size() && pos>=0;
}

template <typename T>
ConstDoublyLinkedListIterator<T>& ConstDoublyLinkedListIterator<T>::operator++(){
  pos++;
  cur = cur->getnext();
  return *this;
}

template <typename T>
const ConstDoublyLinkedListIterator<T> ConstDoublyLinkedListIterator<T>::operator++ (int){
  ConstDoublyLinkedListIterator<T> copy = ConstDoublyLinkedListIterator(*this);
  ++(*this);
  return copy;
}

template <typename T>
ConstDoublyLinkedListIterator<T>& ConstDoublyLinkedListIterator<T>::operator--(){
  pos--;
  cur = cur->getpre();
  return *this;
}

template <typename T>
const ConstDoublyLinkedListIterator<T> ConstDoublyLinkedListIterator<T>::operator--(int){
  ConstDoublyLinkedListIterator<T> copy = ConstDoublyLinkedListIterator(*this);
  --(*this);
  return copy;
}

template <typename T>
const T& ConstDoublyLinkedListIterator<T>::operator*() const{
  return cur->getval();
}

template  <typename T>
int ConstDoublyLinkedListIterator<T>::getpos(){
  return pos;
}

#endif //TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
