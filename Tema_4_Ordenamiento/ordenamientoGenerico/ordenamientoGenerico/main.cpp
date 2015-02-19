
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
    std::generate(enteros, enteros+n, [](){return rand() % 100000;});
    
    /* Mostrar números por pantalla */
    std::copy(enteros, enteros+n, std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
    
    /* Ordenar los elementos del arreglo ascendentemente utilizando un método estático de la clase */
    Ordenamiento<int>::insercion(enteros, n, Ordenamiento<int>::desc);
    
    /* Mostrar números ordenados por pantalla */
    std::copy(enteros, enteros+n, std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl << std::endl;
    
    /* Ordenar personas */
    
    const int n_personas = 3;
    
    /* Declarar e incializar el arreglo de personas */
    Persona personas[n_personas];
    
    personas[0] = Persona("Maria", "Perez", 21);
    personas[1] = Persona("Juana", "Bacallao", 18);
    personas[2] = Persona("Luisa", "Perez", 28);
    
    /* Mostrar personas por pantalla utilizando la variante del for de C++11 */
    std::cout << "--- Listado de personas ---" << std::endl;
    for(auto p : personas)
    {
        std::cout << p;
    }
    
    std::cout << std::endl;

    /* Ordenar el arreglo de personas descendentemente utilizando una función lambda */
    Ordenamiento<Persona>::seleccion(personas, n_personas, [](Persona a, Persona b){ return a > b;});
    
    /* Mostrar personas ordenadas ascendentemente por la edad */
    std::cout << "--- Listado de personas ordenadas ascendetemente por la edad ---" << std::endl;
    std::copy(personas, personas+n_personas, std::ostream_iterator<Persona>(std::cout, ""));

    
    return 0;
}
