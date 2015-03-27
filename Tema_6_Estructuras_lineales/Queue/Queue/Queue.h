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
        virtual ~Queue();
        
        Node<T> * first() const override;
        Node<T> * last() const override;
        
        bool empty() const override;
        int size() const override;
        
        void enqueue(const T &);
        void enqueue(Node<T> *);
        
        Node<T> * dequeue();
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, const Queue<Tn> &);
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
    Node<T> * Queue<T>::first() const
    {
        return CircularLinkedList<T>::first();
    }
    
    template <class T>
    Node<T> * Queue<T>::last() const
    {
        return CircularLinkedList<T>::last();
    }
    
    template <class T>
    bool Queue<T>::empty() const
    {
        return CircularLinkedList<T>::empty();
    }
    
    template <class T>
    int Queue<T>::size() const
    {
        return CircularLinkedList<T>::size();
    }
    
    template <class T>
    void Queue<T>::enqueue(const T & value)
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
    std::ostream & operator <<(std::ostream & os, const Queue<T> & queue)
    {
        for (const Node<T> & node : queue) {
            os << node << " ";
        }
        
        return os;
    }

    
}

#endif
