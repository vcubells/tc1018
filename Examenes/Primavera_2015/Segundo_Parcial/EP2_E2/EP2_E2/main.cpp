//
//  main.cpp
//  EP2_E2
//
//  Created by Vicente Cubells Nonell on 13/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "../../../../../Tema_6_Estructuras_lineales/LinkedList/LinkedList/LinkedList.h"

using namespace vcn;

LinkedList<int> * findDuplicates(LinkedList<int> *);

int main(int argc, const char * argv[]) {
    
    LinkedList<int> original;
    
    const int n_elements = 10;
    
    /* Insertar valores aleatorios en la lista */
    for (int i = 0; i < n_elements; ++i) {
        original.insertBack( rand() % 10 );
    }
    
    /* Mostrar la lista original */
    std::cout << "--- Lista original ---" << std::endl;
    std::cout << original << std::endl;
    
    /* Encontrar los duplicados */
    LinkedList<int> * duplicates = findDuplicates(&original);
    
    /* Mostrar los duplicados */
    std::cout << "--- Lista con duplicados ---" << std::endl;
    std::cout << *duplicates << std::endl;
    
    /* Eliminar la memoria ocupada por la lista de duplicados */
    delete  duplicates;
    
    return 0;
}

LinkedList<int> * findDuplicates(LinkedList<int> * source)
{
    LinkedList<int> * duplicates = new LinkedList<int>();
    
    int value;
    
    for (auto e : *source)
    {
        value = e.getInfo();
        
        if (source->isDuplicate(value) && !duplicates->search(value)) {
            duplicates->insertBack(value);
        }
    }
    
    return duplicates;
}
