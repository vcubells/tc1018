//
//  main.cpp
//  busquedaEnLista
//
//  Created by Vicente Cubells Nonell on 05/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "../../LinkedList/LinkedList/LinkedList.h"

int main(int argc, const char * argv[]) {
    
    const int n = 10;
    const int m = 12;
    
    using namespace vcn;
    
    /* Declarar las listas */
    LinkedList<int> * N = new LinkedList<int>();
    LinkedList<int> * M = new LinkedList<int>();
    LinkedList<int> * P = new LinkedList<int>();
    
    
    for (int i = 0; i < n; ++i) {
        N->insertBack(i);
    }
    
    for (int i = 0; i < m; ++i) {
        M->insertBack(i);
    }

    
    /* Unir ambas listas */
    
    int numero;
    
    for (int i = 0; i < n; ++i) {
        numero = N->at(i)->getInfo();
        P->insertBack(numero);
    }
    
    for (int i = 0; i < m; ++i) {
        numero = M->at(i)->getInfo();
        
        if ( !P->search(numero) )
        {
            P->insertBack(numero);
        }
    }
    
    /* Visualizar las listas */
    std::cout << "N: " << *N << std::endl;
    std::cout << "M: " << *M << std::endl;
    std::cout << "P: " << *P << std::endl;
    
    
    /* N - M */
    
    P->clear();
    
    N->insertBack(15);
    
    int n1 = N->size();
    
    for (int i = 0; i < n1; ++i) {
        numero = N->at(i)->getInfo();
        
        if ( !M->search(numero) )
        {
            P->insertBack(numero);
        }
    }

    std::cout << "P: " << *P << std::endl;

    
    /* M - N */
    
    P->clear();
    
    for (int i = 0; i < m; ++i) {
        numero = M->at(i)->getInfo();
        
        if ( !N->search(numero) )
        {
            P->insertBack(numero);
        }
    }
    
    std::cout << "P: " << *P << std::endl;
    
    /* N intersect M */
    
    P->clear();
    
    for (int i = 0; i < n; ++i) {
        numero = N->at(i)->getInfo();
        
        if ( M->search(numero) )
        {
            P->insertBack(numero);
        }
    }
    
    std::cout << "P: " << *P << std::endl;
    
    /* Liberar la memoria ocupada por las listas */
    delete N;
    delete M;
    delete P;
    
    return 0;
}
