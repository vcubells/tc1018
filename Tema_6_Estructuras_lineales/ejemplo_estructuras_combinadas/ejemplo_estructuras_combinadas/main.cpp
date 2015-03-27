//
//  main.cpp
//  ejemplo_estructuras_combinadas
//
//  Created by Vicente Cubells Nonell on 19/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "../../Stack/Stack/Stack.h"

int main(int argc, const char * argv[]) {
    
    using namespace vcn;
    
    LinkedList< Stack<int> * > listaPilas;
    
    /* Insertar la primera pila */
    
    Stack<int> pila1;
    
    pila1.push(1);
    pila1.push(2);
    
    listaPilas.insertFront( &pila1 );
    
    Stack<int> pila2;
    
    pila1.push(3);
    pila1.push(4);
    
    listaPilas.insertBack( &pila2 );
    
    /* Mostrar toda la estructura */
    Node< Stack<int> * > * tmp = listaPilas.first();
    
    while ( tmp != nullptr) {
        std::cout << *(tmp->getInfo()) << std::endl;
        
        tmp = tmp->getNext();
    }
    
    return 0;
}
