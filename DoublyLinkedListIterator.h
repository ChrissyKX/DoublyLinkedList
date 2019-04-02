//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"
template <typename T>
class DoublyLinkedList;

template<typename T>
class DoublyLinkedListIterator {
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

 public:
  DoublyLinkedListIterator(int p,const DoublyLinkedList<T>& s);

  DoublyLinkedListIterator(const DoublyLinkedListIterator& orig);
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const DoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  DoublyLinkedListIterator<T>& operator++(); //pre
  const DoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  DoublyLinkedListIterator<T>& operator--(); //pre
  const DoublyLinkedListIterator<T> operator--(int); //post

  //get a const reference to the value
  const T& operator*() const;

  //get a non const iterator
  T& operator*();

  int getpos();


private:
    int pos;
    const DoublyLinkedList<T>& subject;
    DoubleLinkedNode<T>* cur;

};







template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(int p, const DoublyLinkedList<T>& s): pos(p), subject(s) {
  if (p < 0) {
    cur = nullptr;
  } else {
    cur = s.gethead();
    if (p > 0) {
      for (int i = 1; i <= p; i++) {
        cur = cur->getnext();
      }
    }
  }
}

template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(const DoublyLinkedListIterator &orig):pos(orig.pos), subject(orig.subject), cur(orig.cur) {
}


template <typename T>
bool DoublyLinkedListIterator<T>::operator==(const DoublyLinkedListIterator<T>& rhs) const{
  if (!bool(*this) && !bool(rhs)){
    return true;
  }else if (&subject == &rhs.subject && pos == rhs.pos){
    return true;
  }else{
    return false;
  }
}

template <typename T>
bool DoublyLinkedListIterator<T>::operator!=(const DoublyLinkedListIterator<T>& rhs) const{
  return !(*this == rhs) ;
}

template <typename T>
DoublyLinkedListIterator<T>::operator bool() const{
  return pos<subject.size() && pos>=0;
}

template <typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator++(){
  pos++;
  cur = cur->getnext();
  return *this;
}

template <typename T>
const DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator++ (int){
  DoublyLinkedListIterator<T> copy = DoublyLinkedListIterator(*this);
  ++(*this);
  return copy;
}

template <typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator--(){
  pos--;
  cur = cur->getpre();
  return *this;
}

template <typename T>
const DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator--(int){
  DoublyLinkedListIterator<T> copy = DoublyLinkedListIterator(*this);
  --(*this);
  return copy;
}

template <typename T>
const T& DoublyLinkedListIterator<T>::operator*() const{
  return cur->getval();
}

template <typename T>
T& DoublyLinkedListIterator<T>::operator*(){
  return cur->getval();
}

template  <typename T>
int DoublyLinkedListIterator<T>::getpos(){
  return pos;
}
#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
