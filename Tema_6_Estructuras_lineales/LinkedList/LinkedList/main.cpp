//
//  main.cpp
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 23/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <string>
#include "Node.h"
#include "Computadora.h"
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    
using namespace vcn;
    
 //   using vcn::Computadora;
  //  using vcn::Node;
    
    Node<int> first(1);
    
    Node<float> second(3.45);
    
    Node<std::string> cad("Esto es una cadena");
    
    Computadora laptop;
    
    Node<Computadora> pc(laptop);
    
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << cad << std::endl;

    std::cout << pc << std::endl;
    
    LinkedList<int> * numeros  = new LinkedList<int>();
    
    /* Obtener el primer elemento */
    std::cout  << "First = " << numeros->first() << std::endl;
    
    /* Determinar el tamaño */
    std::cout  << "Size = " << numeros->size() << std::endl;
    
    /* Determinar si la lista está vacía */
    std::cout  << "Empty = " << (numeros->empty() ? "true" : "false") << std::endl;
    
    
    delete numeros;
    
    
    return 0;
}
