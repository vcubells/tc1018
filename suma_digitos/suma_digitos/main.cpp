//
//  main.cpp
//  suma_digitos
//
//  Created by Vicente Cubells Nonell on 19/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//


#include <iostream>

int sumaDigitos(int);

int main(int argc, const char * argv[])
{
    int numero;
    
    std::cout << "Entre el número entero: ";
    std::cin >> numero;
    
    std::cout << "La suma de los dígitos es = " << sumaDigitos(numero);
    std::cout << std::endl;
    
    return 0;
}

int sumaDigitos(int n)
{
    int resto = n % 10;
    n = n / 10;
    
    if (n == 0) {
        return resto;
    }
    else {
        return resto + sumaDigitos(n);
    }
}

