//
//  Moto.cpp
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Moto.h"

Moto::Moto():Moto(0,"Sin definir", 0, 0.0, 0)
{
    
}

Moto::Moto(int co, std::string ma, int mo, float k, int ci) : Auto(co, ma, mo, k)
{
    cilindraje = ci;
}

int Moto::getCilindraje()
{
    return cilindraje;
}

void Moto::setCilindraje(int value)
{
    cilindraje = value;
}

std::ostream & operator <<(std::ostream & os, Moto & a)
{
    os << (Auto &)a;
    os << " : ";
    os << a.cilindraje << "cc";
    
    return os;
}
