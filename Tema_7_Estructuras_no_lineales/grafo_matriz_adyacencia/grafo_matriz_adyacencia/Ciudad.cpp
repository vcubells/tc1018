//
//  Ciudad.cpp
//  grafo_matriz_adyacencia
//
//  Created by Vicente Cubells Nonell on 20/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Ciudad.h"


std::ostream & operator <<(std::ostream & os, const Ciudad & ciudad)
{
    os << ciudad.nombre << " (" << ciudad.habitantes << " habitantes)" << std::endl;
    
    return os;
}