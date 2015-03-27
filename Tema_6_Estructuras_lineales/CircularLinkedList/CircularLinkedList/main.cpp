//
//  main.cpp
//  CircularLinkedList
//
//  Created by Vicente Cubells Nonell on 09/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "CircularLinkedList.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    /* Demostrar el uso de la clase genérica CircularLinkedList<T> */
    
    /* Declaración de una lista de enteros */
    CircularLinkedList<int> numeros;
    
    /* Determinar el tamaño */
    std::cout  << "Size = " << numeros.size() << std::endl;
    
    /* Determinar si la lista está vacía */
    std::cout  << "Empty = " << (numeros.empty() ? "true" : "false") << std::endl;

    
    /* Insertar elementos en la lista */
    numeros.insert(1, 0);
    numeros.insert(-1, -2);
    numeros.insert(-2, 0);
    numeros.insert(2, 10);
    numeros.insert(10, numeros.size());
    numeros.insert(5, 2);
    numeros.insertFront(-10);
    numeros.insertBack(20);

    /* Obtener el primer elemento */
    std::cout  << "First = " << numeros.first() << std::endl;
    
    /* Obtener el último elemento */
    std::cout  << "Last = " << numeros.last() << std::endl;
    
    /* Crear un nuevo nodo  e insertarlo en la lista */
    Node<int> * newnode = new Node<int>(30);
    
    numeros.insert(newnode, 6);
    
    /* Imprimir el contenido de la lista */
    std::cout << numeros << std::endl;
    
    /* Obtener el iésimo elemento  */
    int pos = numeros.size()-1;
    Node<int> * node = numeros.at(pos);
    
    std::cout  << "At(" << pos << ") = " << (node ? *node : Node<int>()) << std::endl;
    
    /* Obtener la posición de un elemento dado un apuntador al mismo */
    node = numeros.at(0);
    
    std::cout  << "Node está en posición " << numeros.at(node) << std::endl;
    
    /* Obtener la posición de un elemento que no está en la lista */
    node = new Node<int>(100);
    
    std::cout  << "Node está en posición " << numeros.at(node) << std::endl;
    
    delete node;
    
    /* Borrar un nodo de la lista */
    Node<int> * removenode = numeros.remove(6);
    
    if (removenode) {
        std::cout << "Nodo a borrar = " << *removenode << std::endl;
        delete removenode;
    }
    
    /* Imprimir el contenido de la lista */
    std::cout << numeros << std::endl;
    
    /* Borrar toda la lista y liberar la memoria de todos los nodos
     * Solo como demostración ya que aquí se invoca al destructor de la lista
     * de manera automática
     */
    
    numeros.clear();
    
    return 0;
}
