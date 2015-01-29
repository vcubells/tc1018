//
//  main.cpp
//  busquedaBinaria
//
//  Created by Vicente Cubells Nonell on 25/08/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

#define N 100


template <typename T>
bool busquedaBinaria(T a[], T buscar, int inicio, int fin);

template <typename T>
void imprimeVector(T a[]);

int main(int argc, const char * argv[])
{
    int numeros[N] = {0};
    float flotantes[N];
    
    srand((int)time(NULL));
    
    /* Inicializar con números ordenados */
    for (int i= 0; i < N; ++i) {
        numeros[i] = i;
        flotantes[i] = i * 1.5;
    }
    
    imprimeVector(numeros);
    
    int elementoABuscar;
    
    std::cout << "Entre el número a buscar: ";
    std::cin >> elementoABuscar;
    
    bool existe = busquedaBinaria(numeros, elementoABuscar, 0, N);
    
    if (existe) {
        std::cout << "El número " << elementoABuscar << " si existe en el vector";
    }
    else {
        std::cout << "El número " << elementoABuscar << " no existe en el vector";
    }
    
    std::cout << std::endl;
    
    
    /* Buscar valores en punto flotante */
    
    imprimeVector(flotantes);
    
    float flotanteABuscar;
    
    std::cout << "Entre el número a buscar: ";
    std::cin >> flotanteABuscar;
    
    existe = busquedaBinaria(flotantes, flotanteABuscar, 0, N);
    
    if (existe) {
        std::cout << "El número " << flotanteABuscar << " si existe en el vector";
    }
    else {
        std::cout << "El número " << flotanteABuscar << " no existe en el vector";
    }
    
    std::cout << std::endl;
    
    return 0;
}

template <typename T>
bool busquedaBinaria(T a[], T buscar, int inicio, int fin)
{
    
    if (inicio > fin)
    {
        return false;
    }
    else {
        int mitad = (inicio + fin) / 2;
 
        if (a[mitad] == buscar)
        {
            return true;
        }
        else if (buscar < a[mitad] )
        {
            return busquedaBinaria(a, buscar, inicio, mitad-1);
        }
        else {
            return busquedaBinaria(a, buscar, mitad+1, fin);
        }
    }
    
    return false;
}

template <typename T>
void imprimeVector(T a[])
{
    for (int i = 0; i < N; ++i) {
        std::cout << a[i] << ", ";
    }
    
    std::cout << std::endl;
}
