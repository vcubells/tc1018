//
//  main.cpp
//  busquedaGenerica
//
//  Created by Vicente Cubells Nonell on 22/01/15.
//
//

#include <iostream>
#include "BusquedaGenerica.h"
#include "Libro.h"

template <typename T>
void imprimeArreglo(T [], int);

int main(int argc, const char * argv[]) {
    
    srand( (unsigned int) time(nullptr) );
    
    const int longitud = 10;
    
    int enteros[longitud];
    
    for (int i = 0; i < longitud; ++i) {
        enteros[i] = rand() % 100;
    }
    
    imprimeArreglo<int>(enteros, longitud);
    
    std::cout << "Entre el elemento a buscar: ";
    
    int valor;
    
    std::cin >> valor;
    
    bool existe = BusquedaGenerica<int>::busquedaSecuencial(enteros, valor, longitud);
    
    if (existe) {
        std::cout << "El valor si existe en el arreglo" << std::endl;
    }
    else {
        std::cout << "El valor no existe en el arreglo" << std::endl;
    }
    
    /* Buscar en un arreglo de números en punto flotante */
    
    float flotantes[longitud];
    
    for (int i = 0; i < longitud; ++i) {
        flotantes[i] = (rand() % 100) * 0.5;
    }
    
    imprimeArreglo<float>(flotantes, longitud);
    
    std::cout << "Entre el elemento a buscar: ";
    
    float valorf;
    
    std::cin >> valorf;
    
    existe = BusquedaGenerica<float>::busquedaSecuencial(flotantes, valorf, longitud);
    
    if (existe) {
        std::cout << "El valor si existe en el arreglo" << std::endl;
    }
    else {
        std::cout << "El valor no existe en el arreglo" << std::endl;
    }

    /* BUscar libros */
    
    const int nlibros = 3;
    Libro biblioteca[nlibros];
    
    biblioteca[0] = Libro();
    biblioteca[1] = Libro("Cien años de soledad", 1968, "1234");
    biblioteca[2] = Libro("El arte de la guerra", 1900, "6789");
    
    imprimeArreglo<Libro>(biblioteca, nlibros);
    
    return 0;
}

template <typename T>
void imprimeArreglo(T v[], int longitud)
{
    for (int i = 0; i < longitud; ++i) {
        std::cout << v[i] << " ";
    }
    
    std::cout << std::endl;
}
