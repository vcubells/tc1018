//
//  LinkedList.h
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 23/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef LinkedList_LinkedList_h
#define LinkedList_LinkedList_h

#include "Node.h"

namespace vcn {

    template <class T>
    class LinkedList {
    protected:
        
        Node<T> * _first = nullptr;
        int _size = 0;
        
        /* Clase Iterator */
        class Iterator {
            const LinkedList<T> * _data;
            int _position;
            
        public:
            Iterator( const LinkedList<T> * _adata, int _aposition)
            : _data(_adata), _position(_aposition) {}
            
            Node<T> operator *() const { return *(_data->at(_position)); }
            const  Iterator & operator ++() { ++_position; return *this; }
            bool operator != (const Iterator & it) const { return _position != it._position; }
        };
    
    public:
        LinkedList() {}
        virtual ~LinkedList();
        
        /* Obtener un apuntador al primer elemento */
        virtual Node<T> * first() const;
        
        /* Obtener el tamaño de la lista */
        virtual int size() const;
        
        /* Determinar si la lista está vacía */
        virtual bool empty() const;
        
        /* Insertar un elemento nuevo */
        virtual void insert(const T &, int);
        virtual void insert(Node<T> *, int);
        void insertFront(const T &);
        void insertFront(Node<T> *);
        void insertBack(const T &);
        void insertBack(Node<T> *);
        
        /* Eliminar un elemento y regresar un apuntador al mismo.
         * Nota: No liberan la memmoria ocupada por el nodo eliminado
         */
        virtual Node<T> * remove(int);
        Node<T> * removeFront();
        Node<T> * removeBack();
        virtual Node<T> * remove(Node<T> *);
        
        /* Eliminar todos los elementos de la lista y liberar la memoria ocupada
         * por los mismos.
         */
        virtual void clear();
        
        /* Obtener el elemento que se encuentra en una posición */
        virtual Node<T> * at(int) const;
        
        /* Obtener la posición de un nodo */
        virtual int at(Node<T> *) const;

        /* Mostrar el contenido de la lista */
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, const LinkedList<Tn> &);
        
        /* Funciones que utiliza el foreach */
        Iterator begin() const { return { this, 0}; }
        Iterator end() const { return {this, _size }; }
        
        /* Sobrecarga del operador índice */
        Node<T> * operator [](const int);
        
        /* Buscar un elemento */
        bool search(const T &) const;
        virtual int searchAndReturnPosition(const T &) const;
        virtual Node<T> * searchAndReturnNode(const T &) const;
        
    };
    
    template  <class T>
    LinkedList<T>::~LinkedList()
    {
        this->clear();
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::first() const
    {
        return this->_first;
    }
    
    template  <class T>
    int LinkedList<T>::size() const
    {
        return this->_size;
    }
    
    template  <class T>
    bool LinkedList<T>::empty() const
    {
        return this->_size == 0;
    }
    
    /* Si position < 0 se inserta al inicio
     * Si position > _size se inserta al final
     * en cualquier otro caso, se inserta en la posición dada
     */
    template  <class T>
    void LinkedList<T>::insert(const T & element, int position)
    {
        /* Crear el nuevo nodo a insertar */
        Node<T> * newnode = new Node<T>(element);
        
        this->insert(newnode, position);
    }
    
    template  <class T>
    void LinkedList<T>::insert(Node<T> * newnode, int position)
    {
        /* Cuando la lista está vacía o position < 0 */
        if (this->empty() || position <= 0) {
            newnode->setNext(this->_first);
            this->_first = newnode;
        }
        /* Cuando se inserta en cualquier posición diferente del inicio */
        else {
            
            if (position > this->_size) { position = this->_size; }
            
            Node<T> * tmp = this->at(position-1);
            
            newnode->setNext(tmp->getNext());
            tmp->setNext(newnode);
        }
        
        /* Incrementar el tamaño de la lista */
        ++this->_size;
    }
    
    template  <class T>
    void LinkedList<T>::insertFront(const T & element)
    {
        this->insert(element, 0);
    }
    
    template  <class T>
    void LinkedList<T>::insertFront(Node<T> * node)
    {
        this->insert(node, 0);
    }
    
    template  <class T>
    void LinkedList<T>::insertBack(const T & element)
    {
        this->insert(element, this->_size);
    }
    
    template  <class T>
    void LinkedList<T>::insertBack(Node<T> * node)
    {
        this->insert(node, this->_size);
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::remove(int position)
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
            
        }
        /* Eliminar cualquier otro nodo */
        else {
            Node<T> * prev = this->at(position-1);
            removenode = prev->getNext();
            prev->setNext(removenode->getNext());
        }

        /* Establecer el siguiente en nullptr */
        removenode->setNext(nullptr);
        
        /* Decrementar el tamaño de la lista */
        --this->_size;
        
        return removenode;
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::removeFront()
    {
        return this->remove(0);
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::removeBack()
    {
        return this->remove(this->_size - 1);
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::remove(Node<T> * node)
    {
        return this->remove( this->at(node) );
    }
    
    template  <class T>
    void LinkedList<T>::clear()
    {
        /* Cuando la lista está vacía */
        if ( this->empty() ) { return; }
        
        Node<T> * tmp = this->_first;
        
        while (tmp != nullptr) {
            this->_first = this->_first->getNext();
            delete tmp;
            tmp = this->_first;
        }
        
        this->_size = 0;
        
        this->_first = nullptr;
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::at(int position) const
    {
        /* Cuando la lista está vacía o position es inválida */
        if (this->empty() || (position < 0 || position >= this->_size )) {
            return nullptr;
        }
        
        /*  Buscar el nodo que se encuentra en position */
        int pos = 0;
        Node<T> * tmp = this->_first;
        
        while (tmp != nullptr && pos++ < position)
        {
            tmp = tmp->getNext();
        }
        
        return tmp;
        
    }
    
    template  <class T>
    int LinkedList<T>::at(Node<T> * node) const
    {
        /* Cuando la lista está vacía o node es nullptr */
        if (this->empty() || node == nullptr) {
            return -1;
        }
        
        /* Buscar node y regresar su posición */
        return this->searchAndReturnPosition( node->getInfo() );
    }
    
    template <class T>
    std::ostream & operator <<(std::ostream & os, const LinkedList<T> & list)
    {
        for (const Node<T> & node : list )
        {
            os << node << std::endl;
        }
        
        return os;
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::operator [](const int position)
    {
        return this->at(position);
    }
    
    template  <class T>
    bool LinkedList<T>::search(const T & element) const
    {
        return ( this->searchAndReturnPosition(element) != -1 );
    }
    
    template  <class T>
    int LinkedList<T>::searchAndReturnPosition(const T & element) const
    {
        /* Cuando la lista está vacía */
        if ( this->empty() ) { return -1; }
        
        /* Buscar el element y regresar su posición */
        int pos = 0;
        Node<T> * tmp = this->_first;
        
        while (tmp != nullptr && tmp->getInfo() != element)
        {
            tmp = tmp->getNext();
            ++pos;
        }
        
        if (pos == this->_size){ return -1; }
        
        return pos;
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::searchAndReturnNode(const T & element) const
    {
        /* Cuando la lista está vacía */
        if ( this->empty() ) { return nullptr; }
        
        /* Buscar el element y regresar un apuntador al mismo */
        Node<T> * node = nullptr;
        
        Node<T> * tmp = this->_first;
        
        while (tmp != nullptr && node == nullptr)
        {
            if (tmp->getInfo() == element) { node = tmp; }
            tmp = tmp->getNext();
        }
        
        return node;
    }
    
}

#endif
