//
//  Node.h
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 23/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef LinkedList_Node_h
#define LinkedList_Node_h

#include <iostream>

namespace vcn {
    
template <class T>
    class Node {
        T info;
        Node<T> * next = nullptr;
        
    public:
        
        /* Constructores */
        Node() { }
        Node(const T & _info) : info (_info) { }
        Node(const Node<T> & );
        
        /* Destructor */
        virtual ~Node();
        
        T getInfo() const { return info; }
        void setInfo(const T & value) { info = value; }
        
        Node<T> * getNext() const { return next; }
        void setNext(Node<T> * value) { next = value; }
        
        template <typename Tn>
        friend std::ostream & operator << (std::ostream & os, const Node<Tn>  & node);
    };
    
    template <class T>
    Node<T>::Node(const Node<T> & other)
    {
        info = other.info;
        next = other.next;
    }
    
    template <class T>
    Node<T>::~Node()
    {
        info.~T();
        next = nullptr;
    }

    
    template <class T>
    std::ostream & operator << (std::ostream & os, const Node<T>  & node)
    {
        os << node.info;
        
        return os;
    }
    
}



#endif
