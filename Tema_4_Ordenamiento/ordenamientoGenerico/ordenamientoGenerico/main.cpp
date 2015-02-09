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
#include "Persona.h"

int main(int argc, const char * argv[]) {

    const int n = 10;

    /* Declarar el arreglo */
    int enteros[n];
    
    /* Establecer la semilla del generador de números aleatorios */
    srand((unsigned int) time(nullptr));
    
    /* Inicializar el arreglo con números aleatorios */
    std::generate(enteros, enteros+n, [](){return rand() % 100;});
    
    /* Mostrar números por pantalla */
    std::copy(enteros, enteros+n, std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
    
    /* Ordenar los elementos del arreglo utilizanod un método de la clase */
   // Ordenamiento<int>::insercion(enteros, n, Ordenamiento<int>::desc);
    
    /* Ordenar los elementos del arreglo utilizando una función lambda */
    Ordenamiento<int>::insercion(enteros, n, [](int a, int b){ return a > b;});
    
    /* Mostrar números ordenados por pantalla */
    std::copy(enteros, enteros+n, std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
    
    /* Ordenar personas */
    
    const int n_personas = 3;
    
    /* Declarar e incializar el arreglo de personas */
    Persona personas[n_personas];
    
    personas[0] = Persona("Maria", "Perez", 21);
    personas[1] = Persona("Juana", "Bacallao", 18);
    personas[2] = Persona("Luisa", "Perez", 28);
    
    /* Mostrar personas por pantalla utilizando */
    for(auto p : personas)
    {
        std::cout << p;
    }
    
    /* Ordenar el arreglo de personas utilizando la clase genérica */
    Ordenamiento<Persona>::seleccion(personas, n_personas, Ordenamiento<Persona>::desc);
    
    /* Mostrar personas por pantalla utilizando */
    for(auto p : personas)
    {
        std::cout << p;
    }
    
    return 0;
}
