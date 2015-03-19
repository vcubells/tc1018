//
//  main.cpp
//  Stack
//
//  Created by Vicente Cubells Nonell on 19/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    
    /* Usar el namespace */
    using namespace vcn;
    
    /* Definir una pila */
    Stack<int> * pila = new Stack<int>();
    
    /* Insertar elementos en la pila */
    pila->push(1);
    pila->push(2);
    pila->push(3);
    pila->push(4);
    
    /* Mostrar el contenido de la pila */
    std::cout << *pila << std::endl;
    
    /* Obtener el elemento que está en top */
    Node<int> * node = pila->top();
    
    if (node != nullptr) {
        std::cout << "Top = " << *node << std::endl;
    }
    
    /* Eliminar un elemento */
    node = pila->pop();
    
    if (node != nullptr) {
        std::cout << "Nodo a eliminar = " << *node << std::endl;
    }

    delete node;
    
    /* Obtener el elemento que está en top */
    node = pila->top();
    
    if (node != nullptr) {
        std::cout << "Top = " << *node << std::endl;
    }

    /* Mostrar el contenido de la pila */
    std::cout << *pila << std::endl;
    
    /* Eliminar la pila */
    delete pila;
    
    return 0;
}
