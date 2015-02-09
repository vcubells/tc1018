//
//  main.cpp
//  ordenamientoGenerico
//
//  Created by Vicente Cubells Nonell on 05/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "OrdenamientoGenerico.h"
#include <algorithm>
#include <ostream>

int genera()
{
    return rand() % 100;
}

int main(int argc, const char * argv[]) {

    const int n = 10;

    int enteros[n];
    
    /* Establecer la semilla del generador de números aleatorios */
    srand((unsigned int) time(nullptr));
    
    /* Inicializar el arreglo con números aleatorios */
    std::generate(enteros, enteros+n, genera);
    
    /* Mostrar números por pantalla */
    std::copy(enteros, enteros+n, std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
    
    
    return 0;
}
