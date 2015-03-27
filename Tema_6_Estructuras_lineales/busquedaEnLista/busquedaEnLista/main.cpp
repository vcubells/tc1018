//
//  main.cpp
//  busquedaEnLista
//
//  Created by Vicente Cubells Nonell on 05/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "../../LinkedList/LinkedList/LinkedList.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    const int n = 10;
    const int m = 12;
    
    /* Declarar las listas */
    LinkedList<int> N;
    LinkedList<int> M;
    LinkedList<int> P;
    
    /* Llenar la lista N con valores */
    for (int i = 0; i < n; ++i) {
        N.insertBack(i);
    }
    
    /* Llenar la lista M con valores */
    for (int i = 0; i < m; ++i) {
        M.insertBack(i);
    }
    
    /* Unir ambas listas */
    int numero;
    
    /* Se insertan en P los registros de N */
    for (int i = 0; i < n; ++i) {
        numero = N.at(i)->getInfo();
        P.insertBack(numero);
    }
    
    /* Se insertan en P los registros de M que no aparezcan ya en P */
    for (int i = 0; i < m; ++i) {
        numero = M.at(i)->getInfo();
        
        if ( !P.search(numero) )
        {
            P.insertBack(numero);
        }
    }
    
    /* Visualizar las listas */
    std::cout << "N: " << N << std::endl;
    std::cout << "M: " << M << std::endl;
    std::cout << "P: " << P << std::endl;
    
    
    /* N - M */
    P.clear();
    
    N.insertBack(15);
    
    int n1 = N.size();
    
    /* Se insertan en P los registros de N que no están en M */
    for (int i = 0; i < n1; ++i) {
        numero = N.at(i)->getInfo();
        
        if ( !M.search(numero) )
        {
            P.insertBack(numero);
        }
    }

    std::cout << "P: " << P << std::endl;

    
    /* M - N */
    P.clear();
    
    /* Se insertan en P los registros de M que no están en N */
    for (int i = 0; i < m; ++i) {
        numero = M.at(i)->getInfo();
        
        if ( !N.search(numero) )
        {
            P.insertBack(numero);
        }
    }
    
    std::cout << "P: " << P << std::endl;
    
    
    /* N intersect M */
    P.clear();
    
    /* Se insertan en P los registros de N que si están en M */
    for (int i = 0; i < n; ++i) {
        numero = N.at(i)->getInfo();
        
        if ( M.search(numero) )
        {
            P.insertBack(numero);
        }
    }
    
    std::cout << "P: " << P << std::endl;
    
    return 0;
}
