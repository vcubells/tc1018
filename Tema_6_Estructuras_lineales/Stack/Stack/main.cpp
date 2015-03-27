//
//  main.cpp
//  Stack
//
//  Created by Vicente Cubells Nonell on 19/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Stack.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    /* Definir una pila */
    Stack<int> pila;
    
    /* Insertar elementos en la pila */
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    
    /* Mostrar el contenido de la pila */
    std::cout << pila << std::endl;
    
    /* Determinar el tamaño */
    std::cout  << "Size = " << pila.size() << std::endl;
    
    /* Determinar si la pila está vacía */
    std::cout  << "Empty = " << (pila.empty() ? "true" : "false") << std::endl;
    
    /* Obtener el elemento que está en top */
    Node<int> * node = pila.top();
    
    if (node != nullptr) {
        std::cout << "Top = " << *node << std::endl;
    }
    
    /* Eliminar un elemento */
    node = pila.pop();
    
    if (node != nullptr) {
        std::cout << "Nodo a eliminar = " << *node << std::endl;
        delete node;
    }
    
    /* Obtener el elemento que está en top */
    node = pila.top();
    
    if (node != nullptr) {
        std::cout << "Top = " << *node << std::endl;
    }

    /* Mostrar el contenido de la pila */
    std::cout << pila << std::endl;
    
    /* Eliminar la pila.
     * Automáticamente se invoca al destructor.
    */
    
    return 0;
}
