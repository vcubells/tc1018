//
//  main.cpp
//  invierte_digitos
//
//  Created by Vicente Cubells Nonell on 19/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

int invierteNumero(int, int);

int main(int argc, const char * argv[])
{
    int numero;
    
    std::cout << "Entre el número entero: ";
    std::cin >> numero;
    
    std::cout << "El número invertido es = " << invierteNumero(numero, 0);
    std::cout << std::endl;
    
    return 0;
}

int invierteNumero(int n, int nuevo)
{
    int resto = n % 10;
    n = n / 10;
    
    if (n == 0) {
        return resto + nuevo;
    }
    else {
        return invierteNumero(n, (nuevo + resto) * 10) ;
    }
    
}