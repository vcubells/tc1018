//
//  main.cpp
//  EP1_E1
//
//  Created by Vicente Cubells Nonell on 23/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <string>

std::string hexadecimales = "0123456789ABCDEF";

std::string decimalToHex(int);

int main(int argc, const char * argv[]) {
    
    int numero;
    
    std::cout << "Entre un número en base 10: ";
    std::cin >> numero;
    
    std::cout << numero << " ---> " << decimalToHex(numero) << std::endl;
    return 0;
}


std::string decimalToHex(int decimal)
{
    if (decimal == 0) return "";
    else return decimalToHex(decimal / 16) + hexadecimales[decimal % 16];
}