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
        
        int size() const override;
        bool empty() const override;
        
        Node<T> * top();
        Node<T> * pop();
        void push(const T &);
        void push(Node<T> *);
        
        bool operator ==(const Stack<T> &) const;
        bool operator !=(const Stack<T> &) const;
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, const Stack<Tn> &);
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
    int Stack<T>::size() const
    {
        return LinkedList<T>::size();
    }
    
    template <class T>
    bool Stack<T>::empty() const
    {
        return LinkedList<T>::empty();
    }
    
    template <class T>
    Node<T> * Stack<T>::top()
    {
        return LinkedList<T>::first();
    }
    
    template <class T>
    Node<T> * Stack<T>::pop()
    {
        return LinkedList<T>::removeFront();
    }
    
    template <class T>
    void Stack<T>::push(const T & value)
    {
        LinkedList<T>::insertFront(value);
    }
    
    template <class T>
    void Stack<T>::push(Node<T> * node)
    {
        LinkedList<T>::insertFront(node);
    }
    
    template <class T>
    bool Stack<T>::operator ==(const Stack<T> & stack) const
    {
        return size() == stack.size();
    }
    
    template <class T>
    bool Stack<T>::operator !=(const Stack<T> & stack) const
    {
        return ! (*this == stack);
    }
    
    template <class T>
    std::ostream & operator <<(std::ostream & os, const Stack<T> & stack)
    {
        for (const Node<T> & node : stack) {
            os << node << std::endl;
        }
        
        return os;
    }

}
#endif
