//
//  Stack.h
//  Stack
//
//  Created by Vicente Cubells Nonell on 19/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Stack_Stack_h
#define Stack_Stack_h

#include "../../LinkedList/LinkedList/LinkedList.h"

namespace vcn {
template <class T>
class Stack : private LinkedList<T> {
public:
    Stack();
    virtual ~Stack();
    
    int size();
    bool empty();
    
    Node<T> * top();
    Node<T> * pop();
    void push(T);
    void push(Node<T> *);
    
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream &, Stack<Tn> &);
};

template <class T>
Stack<T>::Stack() : LinkedList<T>()
{
}

template <class T>
Stack<T>::~Stack()
{
    this->clear();
}

template <class T>
int Stack<T>::size()
{
    return LinkedList<T>::size();
}

template <class T>
bool Stack<T>::empty()
{
    return LinkedList<T>::empty();
}

template <class T>
Node<T> * Stack<T>::top()
{
    return this->first();
}

template <class T>
Node<T> * Stack<T>::pop()
{
    return this->removeFront();
}

template <class T>
void Stack<T>::push(T value)
{
    this->insertFront(value);
}

template <class T>
void Stack<T>::push(Node<T> * node)
{
    this->insertFront(node);
}

template <class T>
std::ostream & operator <<(std::ostream & os, Stack<T> & stack)
{
    for (auto i : stack) {
        os << i << std::endl;
    }
    
    return os;
}

}
#endif
