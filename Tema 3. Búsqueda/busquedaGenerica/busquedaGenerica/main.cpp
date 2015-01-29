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
        enteros[i] = i;
    }
    
    imprimeArreglo<int>(enteros, longitud);
    
    std::cout << "Entre el elemento a buscar: ";
    
    int valor;
    
    std::cin >> valor;
    
   // bool existe = BusquedaGenerica<int>::busquedaSecuencial(enteros, valor, longitud);
    
    int pos = BusquedaGenerica<int>::busquedaSecuencialPosicion(enteros, valor, longitud);
    
    if (pos != -1) {
        std::cout << "El valor si existe en el arreglo en posición " << pos << std::endl;
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
    
    bool existe = BusquedaGenerica<float>::busquedaSecuencial(flotantes, valorf, longitud);
    
    if (existe) {
        std::cout << "El valor si existe en el arreglo" << std::endl;
    }
    else {
        std::cout << "El valor no existe en el arreglo" << std::endl;
    }

    /* Buscar libros */
    
    const int nlibros = 3;
    Libro biblioteca[nlibros];
    
    biblioteca[0] = Libro();
    biblioteca[1] = Libro("Cien años de soledad", 1968, "0ab2");
    biblioteca[2] = Libro("El arte de la guerra", 1900, "mar45");
    
    imprimeArreglo<Libro>(biblioteca, nlibros);
    
    std::cout << "Entre el ISBN del libro a buscar: ";
    
    std::string isbn;
    
    std::cin >> isbn;
    
    existe = BusquedaGenerica<Libro>::busquedaBinaria(biblioteca, Libro("No importa", 0, isbn), 0, nlibros);
    
    if (existe) {
        std::cout << "El libro si existe en la biblioteca" << std::endl;
    }
    else {
        std::cout << "El libro no existe en la biblioteca" << std::endl;
    }

    
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
