//
//  main.cpp
//  Queue
//
//  Created by Vicente Cubells Nonell on 19/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Queue.h"

int main(int argc, const char * argv[]) {
    
    /* Usar el namespace */
    using namespace vcn;
    
    /* Definir una cola */
    Queue<int> * cola = new Queue<int>();
    
    /* Insertar elementos en la cola */
    cola->enqueue(1);
    cola->enqueue(2);
    cola->enqueue(3);
    cola->enqueue(4);
    
    /* Mostrar el contenido de la cola */
    std::cout << *cola << std::endl;
    
    /* Obtener el elemento que está al inicio */
    Node<int> * node = cola->first();
    
    if (node != nullptr) {
        std::cout << "First = " << *node << std::endl;
    }
    
    /* Obtener el elemento que está al final */
    node = cola->last();
    
    if (node != nullptr) {
        std::cout << "Last = " << *node << std::endl;
    }
    
    /* Eliminar un elemento */
    node = cola->dequeue();
    
    if (node != nullptr) {
        std::cout << "Nodo a eliminar = " << *node << std::endl;
    }
    
    delete node;
    
    /* Obtener el elemento que está al inicio */
    node = cola->first();
    
    if (node != nullptr) {
        std::cout << "First = " << *node << std::endl;
    }
    
    /* Mostrar el contenido de la cola */
    std::cout << *cola << std::endl;
    
    /* Eliminar la cola */
    delete cola;
    
    return 0;
}
