//
//  main.cpp
//  CircularLinkedList
//
//  Created by Vicente Cubells Nonell on 09/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "CircularLinkedList.h"

int main(int argc, const char * argv[]) {
    
    using namespace vcn;
    
    /* Demostrar el uso de la clase genérica CircularLinkedList<T> */
    
    /* Declaración de una lista de enteros */
    CircularLinkedList<int> * numeros = new CircularLinkedList<int>();
    
    /* Determinar el tamaño */
    std::cout  << "Size = " << numeros->size() << std::endl;
    
    /* Determinar si la lista está vacía */
    std::cout  << "Empty = " << (numeros->empty() ? "true" : "false") << std::endl;

    
    /* Insertar elemento en la lista */
    
    numeros->LinkedList::insert(1, 0);
    numeros->LinkedList::insert(-1, -2);
    numeros->LinkedList::insert(-2, 0);
    numeros->LinkedList::insert(2, 10);
    numeros->LinkedList::insert(10, numeros->size());
    numeros->LinkedList::insert(5, 2);
    numeros->insertFront(-10);
    numeros->insertBack(20);

    /* Obtener el primer elemento */
    std::cout  << "First = " << *numeros->first() << std::endl;
    
    /* Obtener el último elemento */
    std::cout  << "Last = " << *numeros->last() << std::endl;
    
    /* Crear un nuevo nodo  e insertarlo en la lista */
    Node<int> * newnode = new Node<int>(30);
    
    numeros->insert(newnode, 6);
    
    /* Imprimir el contenido de la lista */
    std::cout << *numeros << std::endl;
    
    /* Obtener el iésimo elemento  */
    int pos = numeros->size()-1;
    std::cout  << "At(" << pos << ") = " << *(numeros->at(pos)) << std::endl;
    
    /* Obtener la posición de un elemento dado un apuntador al mismo */
    Node<int> * node = numeros->at(0);
    
    std::cout  << "Node está en posición " << numeros->LinkedList::at(node) << std::endl;
    
    /* Borrar un nodo de la lista */
    Node<int> * removenode = numeros->remove(6);
    
    if (removenode) {
        std::cout << " Nodo a borrar = " << *removenode << std::endl;
        delete removenode;
    }
    
    /* Imprimir el contenido de la lista */
    std::cout << *numeros << std::endl;
    
    /* Borrar toda la lista y liberar la memoria de todos los nodos */
    delete numeros;
    
    return 0;
}
