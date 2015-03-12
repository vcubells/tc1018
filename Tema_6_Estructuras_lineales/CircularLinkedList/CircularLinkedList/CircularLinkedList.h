//
//  CircularLinkedList.h
//  CircularLinkedList
//
//  Created by Vicente Cubells Nonell on 09/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef CircularLinkedList_CircularLinkedList_h
#define CircularLinkedList_CircularLinkedList_h

#include "../../LinkedList/LinkedList/LinkedList.h"

using namespace vcn;
    
    template <class T>
    class CircularLinkedList :  public LinkedList<T> {
        
    protected:

        Node<T> * _last = nullptr;
        
    public:
        CircularLinkedList() {}
        virtual ~CircularLinkedList();
        
        /* Obtener un apuntador al último elemento */
        virtual Node<T> * last();

        /* Insertar un elemento nuevo */
        void insert(Node<T> *, int) override;
        
        /* Eliminar un elemento y regresar un apuntador al mismo.
         * Nota: No liberan la memmoria ocupada por el nodo eliminado
         */
        Node<T> * remove(int) override;
        
        /* Eliminar todos los elementos de la lista y liberar la memoria ocupada
         * por los mismos.
         */
        void clear() override;
        
        /* Obtener el elemento que se encuentra en una posición */
        Node<T> * at(int) override;
        
        /* Mostrar el contenido de la lista */
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, CircularLinkedList<Tn> &);

    };
    
    template <class T>
    CircularLinkedList<T>::~CircularLinkedList()
    {
        this->clear();
    }
    
    template <class T>
    Node<T> * CircularLinkedList<T>::last()
    {
        return this->_last;
    }
    
    template  <class T>
    void CircularLinkedList<T>::insert(Node<T> * newnode, int position)
    {
        /* Cuando la lista está vacía */
        if ( this->empty() ) {
            this->_first = this->_last = newnode;
            newnode->setNext(this->_first);
        }
        /* Cuando position < 0 */
        else if (position <= 0) {
            newnode->setNext(this->_first);
            this->_first = newnode;
            this->_last->setNext(this->_first);
        }
        
        /* Cuando se inserta en cualquier posición diferente del inicio */
        else {
            
            if (position > this->_size) { position = this->_size; }
            
            Node<T> * tmp = this->at(position-1);
            
            newnode->setNext(tmp->getNext());
            tmp->setNext(newnode);
            
            if (position == this->_size) {
                this->_last = newnode;
            }
        }
        
        /* Incrementar el tamaño de la lista */
        ++this->_size;
    }
    
    
    template  <class T>
    Node<T> * CircularLinkedList<T>::remove(int position)
    {
        /* Cuando la lista está vacía o position es inválida */
        if (this->empty() || (position < 0 || position >= this->_size )) {
            return nullptr;
        }
        
        Node<T> * removenode;
        
        /* Eliminar el primer nodo de la lista */
        if (position == 0) {
            removenode = this->_first;
            this->_first = this->_first->getNext();
            this->_last->setNext(this->_first);
            
            /* Caso particular en que existe un único elemento */
            if (this->_size == 1) {
                this->_first = this->_last = nullptr;
            }
            
        }
        /* Eliminar cualquier otro nodo */
        else {
            Node<T> * prev = this->at(position-1);
            removenode = prev->getNext();
            prev->setNext(removenode->getNext());
            
            /* Caso particular en que se elimina el último */
            if (position == this->_size -1) {
                this->_last = prev;
            }
        }
        
        /* Establecer el siguiente en nullptr */
        removenode->setNext(nullptr);
        
        /* Decrementar el tamaño de la lista */
        --this->_size;
        
        return removenode;
    }
    
    template  <class T>
    Node<T> *  CircularLinkedList<T>::at(int position)
    {
        /* Cuando la lista está vacía o position es inválida */
        if (this->empty() || (position < 0 || position >= this->_size )) {
            return nullptr;
        }
        
        /*  Buscar el nodo que se encuentra en position */
        int pos = 0;
        Node<T> * tmp = this->_first;
        
        while (pos++ < position)
        {
            tmp = tmp->getNext();
        }
        
        return tmp;
        
    }
    
    template  <class T>
    void CircularLinkedList<T>::clear()
    {
        /* Cuando la lista está vacía */
        if ( this->empty() ) { return; }
        
        Node<T> * tmp = this->_first;
        
        while (tmp != this->_last) {
            this->_first = this->_first->getNext();
            this->_last->setNext(this->_first);
            
            delete tmp;
            tmp = this->_first;
        }
        
        /* Para elimiinar el último elemento */
        delete tmp;
        tmp = this->_first;
        
        this->_size = 0;
        
        this->_first = this->_last = nullptr;
    }
    
    template <class T>
    std::ostream & operator <<(std::ostream & os, CircularLinkedList<T> & list)
    {
        for (auto node : list )
        {
            os << node << std::endl;
        }
        
        /*
         
         Node<T> * inicio = list.begin();
         Node<T> * fin = list.end();
         
         for (auto it = inicio; it != fin; ++it)
         {
            os << *it;
         }
        
         */
        
        return os;
    }

    

#endif
