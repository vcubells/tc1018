//
//  main.cpp
//  robot
//
//  Created by Vicente Cubells Nonell on 18/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

using namespace std;

int robot(int , int );

int main(int argc, const char * argv[])
{
    
    int n, m;
    
    cout << "Entre el valor de n (filas): ";
    cin >> n;
    
    cout << "Entre el valor de m (columnas): ";
    cin >> m;
    
    cout << "Se encontraron " << robot(n, m) << " caminos" << endl;
    
    return 0;
}

int robot(int n, int m)
{
    int derecha = 0, abajo = 0;
    
    if ( (n == 3 && m == 1) || (m == 4 && n == 1) )
    {
        return 1;
    }
    else
    {
        if ( n > 2 )
        {
            abajo = robot(n - 2, m);
        }
        
        if ( m > 3 )
        {
            derecha = robot(n, m - 3);
        }
        
        return derecha + abajo;
    }
}
