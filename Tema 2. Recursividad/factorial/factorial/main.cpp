//
//  main.cpp
//  factorial
//
//  Created by Vicente Cubells Nonell on 19/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//
#include <iostream>

unsigned long int factorial(int n);

int main(int argc, const char * argv[])
{
    int numero;
    
    std::cout << "Entre el número a calcularle el factorial: ";
    std::cin >> numero;
    
    std::cout << "El factorial de " << numero << " es = ";
    std::cout << factorial(numero) << std::endl;
    
    return 0;
}

unsigned long int factorial(int n)
{
    if (n == 0 || n == 1) { // Condición base o condición de parada
        return 1;
    }
    else {
        return n * factorial(n -1); // Procesamiento
    }
    
}
