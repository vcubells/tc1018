//
//  Camioneta.cpp
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Camioneta.h"

Camioneta::Camioneta(): Camioneta(0,"Sin definir", 0, 0.0, "---")
{
    
}

Camioneta::Camioneta(int co, std::string ma, int mo, float k, std::string tr) : Auto(co, ma, mo, k)
{
    traccion = tr;
}

std::string Camioneta::getTraccion()
{
    return traccion;
}

void Camioneta::setTraccion(std::string value)
{
    traccion = value;
}

std::ostream & operator <<(std::ostream & os, Camioneta & a)
{
    os << (Auto &)a;
    os << " : ";
    os << a.traccion;
    
    return os;
}