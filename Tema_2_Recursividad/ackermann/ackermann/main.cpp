//
//  main.cpp
//  ackermann
//
//  Created by Vicente Cubells Nonell on 19/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//


#include <iostream>

int ackermann(int m, int n);

int main(int argc, const char * argv[])
{
    int m, n;
    
    std::cout << "Entre el valor de m: ";
    std::cin >> m;
    
    std::cout << "Entre el valor de n: ";
    std::cin >> n;
    
    std::cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n);
    std::cout << std::endl;
    
    return 0;
}

int ackermann(int m, int n)
{
    if (m == 0) {
        return n + 1; // Paso base o condición de parada
    }
    else if (m > 0 && n == 0)
    {
        return ackermann(m - 1, 1); // Recursión simple
    }
    else if (m > 0 && n > 0)
    {
        return ackermann(m - 1, ackermann(m, n - 1)); // Recursión múltiple
    }
    else {
        return -1;
    }
}
