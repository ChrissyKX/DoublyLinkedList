//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
#include "ConstDoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedListIterator.h"


template<typename T>
class DoublyLinkedList {
 public:
  using Node_Ptr = DoubleLinkedNode<T>*;

  using iterator = DoublyLinkedListIterator<T> /*put the type of your iterator here*/;
  using const_iterator = ConstDoublyLinkedListIterator<T> /*put the type of your const iterator here*/;
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>/*put the type of your reverse iterator here*/;
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>/*put the type of your const reverse iterator here*/;

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList<T>(const std::vector<T>& values);



  //create an empty DoublyLinkedList
  DoublyLinkedList<T>();


  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear();
  //get a reference to the front element in the list
  const T& front() const;
  T& front();

  //get a reference to the last element in the list
  const T& back() const;
  T& back();
  //get my head
  DoubleLinkedNode<T>* gethead() const;
  DoubleLinkedNode<T>* gettail() const;

  //add a value to the front of the list
  void push_front(const T& value);

  //add a value to the back of the list
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;
  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value);


  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

 private:
  Node_Ptr head = nullptr;
  Node_Ptr tail = nullptr;
  int len = 0;
  int test = 1;
};











//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList){
  for (auto itr = doublyLinkedList.cbegin(); itr!= doublyLinkedList.cend(); ++itr){
    out<<*itr;
  }
  return out;
}

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList){
  T a;
  do{
    in>>a;
    doublyLinkedList.push_back(a);
  }while(a!='\n');
  return in;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values){
  for(unsigned int i = 0; i<values.size();i++){
    this->push_back(values[i]);
  }

}

//create an empty DoublyLinkedList
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() = default;

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  this->clear();

}


//remove all of the elements from your list
template <typename T>
void DoublyLinkedList<T>::clear(){
  if(len==1){
    delete head;
    head = nullptr;
    tail = nullptr;
  }else if(len>1) {
    auto temp = head;
      for (int i = 0; i < len-1; i++) {
        temp = head;
        head = head->getnext();
        head->setpre(nullptr);
        temp->setnext(nullptr);
        delete temp;
      }
      delete head;
      head = nullptr;
      tail = nullptr;
    }

    len = 0;
  }


//get a reference to the front element in the list
template <typename T>
const T& DoublyLinkedList<T>::front() const{
  return head->getval();
}

template <typename T>
T& DoublyLinkedList<T>::front(){
  return head->getval();
}

//get a reference to the last element in the list
template <typename T>
const T& DoublyLinkedList<T>::back() const{
  return tail->getval();
}

template <typename T>
T& DoublyLinkedList<T>::back(){
  return tail->getval();
}

template <typename T>
DoubleLinkedNode<T>* DoublyLinkedList<T>::gethead() const{
  return head;
}

template <typename T>
DoubleLinkedNode<T>* DoublyLinkedList<T>::gettail() const{
  return tail;
}



//add a value to the front of the list
template <typename T>
void DoublyLinkedList<T>::push_front(const T& value){
  if (len==0){
    head = new DoubleLinkedNode<T>(nullptr, value, nullptr);
    tail = head;
    len++;
  }else{
    head = new DoubleLinkedNode<T>(nullptr, value, head);
    head->getnext()->setpre(head);
    len++;
  }

}

//add a value to the back of the list
template <typename T>
void DoublyLinkedList<T>::push_back(const T& value){
  if (len>0) {
    tail = new DoubleLinkedNode<T>(tail, value, nullptr);
    tail->getpre()->setnext(tail);
  }else if (len == 0){
    tail = new DoubleLinkedNode<T>(nullptr, value, nullptr);
    head = tail;
  }
  len++;
}

//is the list empty?
template <typename T>
bool DoublyLinkedList<T>::empty() const{
  return len==0;
}

//return the number of elements in the list
template <typename T>
int DoublyLinkedList<T>::size() const{
  return len;
}

//return a constant bidirectional iterator to the front of the list
template <typename T>
ConstDoublyLinkedListIterator<T> DoublyLinkedList<T>::begin() const{
  return ConstDoublyLinkedListIterator<T>(0, *this);
}

template <typename T>
ConstDoublyLinkedListIterator<T>  DoublyLinkedList<T>::end() const{
  return ConstDoublyLinkedListIterator<T>(len, *this);
}

//return a nonconstant bidirectional iterator to the front of the list
template <typename T>
DoublyLinkedListIterator<T> DoublyLinkedList<T>::begin(){
  return DoublyLinkedListIterator<T>(0, *this);
}

template <typename T>
DoublyLinkedListIterator<T> DoublyLinkedList<T>::end(){
  return DoublyLinkedListIterator<T>(len, *this);
}

template <typename T>
ConstReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::crbegin() const{
  return ConstReverseDoublyLinkedListIterator<T>(len-1, *this);
}

template <typename T>
ConstReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::crend() const{
  return ConstReverseDoublyLinkedListIterator<T>(-1, *this);
}

template <typename T>
ReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::rbegin(){
  return ReverseDoublyLinkedListIterator<T>(len-1, *this);
}

template <typename T>
ReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::rend(){
  return ReverseDoublyLinkedListIterator<T>(0, *this);
}

//insert the value at the position in the list
//I promise not to use the iterator again after the insertion is done
//An example if we had the list 1 <-> 9 <-> 17
//And the iterator was pointing to the 9 and we wanted to
//insert -22 the result would be
//1 <-> 22 <-> 9 <-> 17
template <typename T>
void DoublyLinkedList<T>::insert(iterator& position, const T& value){
  int p = position.getpos();
  //if (bool(position)){
    if(len==0 || len== 1 || p == 0) {
      this->push_front(value);
    }else{
      auto temp = head;
      for(int i = 1; i <= p-1; i++){
        temp = temp->getnext();
      }
      temp->setnext(new DoubleLinkedNode<T>(temp, value, temp->getnext()));
      temp->getnext()->getnext()->setpre(temp->getnext());
      len++;
    }

  //}
}

//remove the element at the position pointed to
//by the iterator.
//I promise not to use the iterator again after the erase is done
//An example if we had the list 1 <-> 9 <-> 17
//And when the wanted to erase the iterator was at the 9
//1 <-> 17
template <typename T>
void DoublyLinkedList<T>::erase(iterator& position){
  int p = position.getpos();
  if(bool(position)){
    if(len==1){
      delete head;
      head = nullptr;
      tail = nullptr;
      len--;
    }else if(p==0){
      auto temp = head;
      head = head->getnext();
      temp->setnext(nullptr);
      head->setpre(nullptr);
      delete temp;
      len--;
    }else if(p==len-1){
      auto temp = tail;
      tail = tail->getpre();
      temp->setpre(nullptr);
      tail->setnext(nullptr);
      delete temp;
      len--;
    }else{
      auto temp = head;
      for (int i = 0; i<p; i++){
        temp = temp->getnext();
      }
      temp->getpre()->setnext(temp->getnext());
      temp->getnext()->setpre(temp->getpre());
      delete temp;
      len--;
    }
  }
}


#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
