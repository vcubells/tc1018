//
//  main.cpp
//  palindromo
//
//  Created by Vicente Cubells Nonell on 20/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <string>
#include <regex>

bool palindromo(std::string, int, int);

int main(int argc, const char * argv[]) {
    
    std::string cadena;
    
    std::cout << "Entre la cadena a verificar: ";
    std::getline(std::cin, cadena);
    
    /* Eliminar los espacios en blanco de la cadena */
    auto cadena_sin_espacios = std::regex_replace(cadena,std::regex("\\s+"), "");
    
    /* Invocar a la función recursiva */
    bool es_palindromo = palindromo(cadena_sin_espacios, 0, (int)cadena_sin_espacios.length()-1);
    
    /* Mostrar el resultado */
    if (es_palindromo) {
        std::cout << "La cadena es un palíndromo" << std::endl;
    }
    else {
        std::cout << "La cadena no es un palíndromo" << std::endl;
    }
    
    return 0;
}

bool palindromo(std::string cadena, int izquierda, int derecha)
{
    if (izquierda >= derecha) {
        return true;
    }
    else if (cadena[izquierda] != cadena[derecha]) {
        return false;
    }
    else {
        return palindromo(cadena, izquierda+1, derecha-1);
    }
}
