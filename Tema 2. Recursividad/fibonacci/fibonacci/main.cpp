//
//  main.cpp
//  fibonacci
//
//  Created by Vicente Cubells Nonell on 19/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

int fibonacci(int i);

int main(int argc, const char * argv[])
{
    int posicion;
    
    std::cout << "Entre la posición en la serie del número a obtener: ";
    std::cin >> posicion;
    
    std::cout << "fibonacci(" << posicion << ") = " << fibonacci(posicion);
    std::cout << std::endl;
    
    return 0;
}

int fibonacci(int i)
{
    if (i == 0) {
        return 0;
    }
    else if (i == 1)
    {
        return 1;
    }
    else {
        return fibonacci(i - 2) + fibonacci(i - 1);
    }
}
