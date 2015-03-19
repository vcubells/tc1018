//
//  Queue.h
//  Queue
//
//  Created by Vicente Cubells Nonell on 19/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Queue_Queue_h
#define Queue_Queue_h

#include "../../CircularLinkedList/CircularLinkedList/CircularLinkedList.h"

namespace vcn {
    template <class T>
    class Queue : private CircularLinkedList<T> {
    public:
        Queue();
        ~Queue();
        
        Node<T> * first();
        Node<T> * last();
        
        bool empty();
        int size();
        
        void enqueue(T);
        void enqueue(Node<T> *);
        
        Node<T> * dequeue();
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, Queue<Tn> &);
    };
    
    template <class T>
    Queue<T>::Queue() : CircularLinkedList<T>()
    {
        
    }
    
    template <class T>
    Queue<T>::~Queue()
    {
        this->clear();
    }
    
    template <class T>
    Node<T> * Queue<T>::first()
    {
        return CircularLinkedList<T>::first();
    }
    
    template <class T>
    Node<T> * Queue<T>::last()
    {
        return CircularLinkedList<T>::last();
    }
    
    template <class T>
    bool Queue<T>::empty()
    {
        return CircularLinkedList<T>::empty();
    }
    
    template <class T>
    int Queue<T>::size()
    {
        return CircularLinkedList<T>::size();
    }
    
    template <class T>
    void Queue<T>::enqueue(T value)
    {
        this->insertBack(value);
    }
    
    template <class T>
    void Queue<T>::enqueue(Node<T> * node)
    {
        this->insertBack(node);
    }
    
    template <class T>
    Node<T> * Queue<T>::dequeue()
    {
        return this->removeFront();
    }
    
    template <class T>
    std::ostream & operator <<(std::ostream & os, Queue<T> & queue)
    {
        for (auto i : queue) {
            os << i << " ";
        }
        
        return os;
    }

    
}

#endif
