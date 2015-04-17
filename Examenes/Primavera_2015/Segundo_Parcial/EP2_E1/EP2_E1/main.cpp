//
//  main.cpp
//  EP2_E1
//
//  Created by Vicente Cubells Nonell on 13/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "../../../../../Tema_6_Estructuras_lineales/Stack/Stack/Stack.h"

using namespace vcn;

void decimalToBinary(int decimal);

int main(int argc, const char * argv[]) {
    
    int decimal = 0;
    
    std::cout << "Entre el número en base 10: ";
    std::cin >> decimal;
    
    decimalToBinary(decimal);
    
    return 0;
}

void decimalToBinary(int decimal)
{
    /* Inicialización de variables */
    Stack<int> binary;

    int residuo;
    
    /* Convertir a binario */
    while (decimal != 0) {
        residuo = decimal % 2;
        decimal /= 2;
        
        binary.push(residuo);
    }
    
    /* Mostrar el resultado */
    
    std::cout << binary << std::endl;
}
