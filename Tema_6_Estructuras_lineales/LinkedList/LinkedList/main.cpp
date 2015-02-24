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
#include "../../../Tema_4_Ordenamiento/ordenamientoGenerico/ordenamientoGenerico/Persona.h"
int main(int argc, const char * argv[]) {
    
    Node<int> first;
    
    Node<float> second(3.45);
    
    Node<std::string> cad("Esto es una cadena");
    
    Persona juana("Juana", "Bacallao", 89);
    Node<Persona> persona(juana);
    
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << cad << std::endl;
    
    std::cout << persona << std::endl;
    
    
    return 0;
}
