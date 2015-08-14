//
//  main.cpp
//  ordenar_numeros
//
//  Created by Vicente Cubells Nonell on 18/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <ostream>
#include <ctime>
#include "../../ordenamientoGenerico/ordenamientoGenerico/OrdenamientoGenerico.h"


typedef bool (*t_criterio) (int, int);
typedef void (*t_algoritmo)(int [], int, t_criterio);

int main(int argc, const char * argv[]) {
    
    const int n = 100;
    
    time_t inicio, final;

    /* Declarar el arreglo */
    int enteros[n];
    
    /* Establecer la semilla del generador de números aleatorios */
    srand((unsigned int) time(nullptr));
    
    /* Inicializar el arreglo con números aleatorios */
    std::generate(enteros, enteros+n, [](){return rand() % 100000;});
    
    /* Mostrar números por pantalla */
    std::copy(enteros, enteros+n, std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
    
    /* El usuario selecciona el algoritmo de ordenamiento */
    std::cout << "Algoritmos de ordenamiento: " << std::endl;
    std::cout << "1-Burbuja\n2-Selección\n3-Inserción" << std::endl;
    std::cout << "Seleccione el algoritmo: ";
    
    int algoritmo;
    
    std::cin >> algoritmo;
    
    /* El usuario selecciona el criterio de ordenamiento */
    std::cout << "Criterio: " << std::endl;
    std::cout << "1-Ascendente\n2-Descendente\n" << std::endl;
    std::cout << "Seleccione el criterio: ";
    
    int criterio;
    
    std::cin >> criterio;
    
    /* Definir arreglos de funciones para los criterios */
    t_criterio criterios[2];
    
    criterios[0] = Ordenamiento<int>::asc;
    criterios[1] = Ordenamiento<int>::desc;
    
    /* Definir arreglos de funciones para los algoritmos */
    t_algoritmo algoritmos[3];
    
    algoritmos[0] = Ordenamiento<int>::burbuja;
    algoritmos[1] = Ordenamiento<int>::seleccion;
    algoritmos[2] = Ordenamiento<int>::insercion;

    /* Ejecutar el algoritmo de ordenamiento seleccionado por el usuario */
    inicio = time(nullptr);
    algoritmos[algoritmo-1](enteros, n, criterios[criterio-1]);
    final = time(nullptr);
	
    /* Mostrar números ordenados por pantalla */
    std::copy(enteros, enteros+n, std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << std::endl;
 
    std::cout <<  "Número de segundos transcurridos: " <<  difftime(final, inicio) << std::endl;


   
    return 0;
}
