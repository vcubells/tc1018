//
//  main.cpp
//  hanoi_recursivo
//
//  Created by Vicente Cubells Nonell on 15/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

void hanoi(int, int, int, int);

int main(int argc, const char * argv[]) {
    
    int numero_discos = 0;
    
    std::cout << "Entre el número de discos: ";
    std::cin >> numero_discos;
    
    if (numero_discos < 1)
    {
        std::cout << "El número de discos debe ser > 0" <<std::endl;
        return 1;
    }
    
    hanoi(numero_discos, 1, 3, 2);
    
    return 0;
}


void hanoi(int n, int x, int y, int z)
{
    if (n == 1 ) {
        // Mover los discos
        std::cout << n << ": " << x << " --> " << y << std::endl;
    }
    else {
        hanoi(n-1, x, z, y);
        
        // Mover los discos
        std::cout << n << ": " << x << " --> " << y << std::endl;
        
        hanoi(n-1, z, y, x);
    }
}