//
//  main.cpp
//  busquedaSecuencial
//
//  Created by Vicente Cubells Nonell on 25/08/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

#define N 100

template <typename T>
bool busquedaSecuencial(T a[], T buscar);

int buscarOcurrencias(int a[], int buscar);

template <typename T>
void imprimeVector(T a[]);

int main(int argc, const char * argv[])
{
    int numeros[N] = {0};
    float flotantes[N];
    
    srand((int)time(NULL));
    
    /* Inicializar con números aleatorios */
    for (int i= 0; i < N; ++i) {
        numeros[i] = rand() % 100;
        flotantes[i] = numeros[i] * 1.5;
    }
    
    imprimeVector(numeros);
    
    int elementoABuscar;
    
    std::cout << "Entre el número a buscar: ";
    std::cin >> elementoABuscar;
    
    bool existe = busquedaSecuencial(numeros, elementoABuscar);
    
    if (existe) {
        std::cout << "El número " << elementoABuscar << " si existe en el vector";
    }
    else {
        std::cout << "El número " << elementoABuscar << " no existe en el vector";
    }
    
    std::cout << std::endl;
    
    int ocurrencias = buscarOcurrencias(numeros, elementoABuscar);
    
    if (ocurrencias > 0) {
        std::cout << "El número " << elementoABuscar << " existe " << ocurrencias << " veces en el vector";
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
    
    existe = busquedaSecuencial(flotantes, flotanteABuscar);
    
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
bool busquedaSecuencial(T a[], T buscar)
{
    int i = 0;
    bool encontrado = false;
    
    while ( (i < N) && !encontrado)
    {
        if (a[i] == buscar) {
            encontrado = true;
        }
        
        ++i;
    }
    
    return encontrado;
}

template <typename T>
void imprimeVector(T a[])
{
    for (int i = 0; i < N; ++i) {
        std::cout << a[i] << ", ";
    }
    
    std::cout << std::endl;
}

int buscarOcurrencias(int a[], int buscar)
{
    int ocurrencias = 0;
    
    for (int i = 0; i < N; ++i) {
        if (a[i] == buscar) {
            ++ocurrencias;
        }
    }
    
    return ocurrencias;
}



