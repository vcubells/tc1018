//
//  main.cpp
//  maximo_comun_divisor
//
//  Created by Vicente Cubells Nonell on 19/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

int mcd(int, int);

int main(int argc, const char * argv[]) {
    
    int m, n;
    
    std::cout << "Entre el valor de m: ";
    std::cin >> m;
    
    std::cout << "Entre el valor de n: ";
    std::cin >> n;
    
    std::cout << " MCD(" << m << ", " << n << ") = ";
    std::cout << mcd(m, n) << std::endl;
    
    return 0;
}


int mcd(int m, int n)
{
    int r = m % n;
    
    if (r == 0)
    {
        return n;
    }
    else {
        return mcd(n, r);
    }
}