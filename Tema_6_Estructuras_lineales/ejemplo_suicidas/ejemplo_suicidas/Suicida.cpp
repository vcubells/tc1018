//
//  Suicida.cpp
//  ejemplo_suicidas
//
//  Created by Vicente Cubells Nonell on 27/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Suicida.h"

bool Suicida::operator ==(const Suicida & suicida)
{
    return _nombre == suicida._nombre;
}

bool Suicida::operator !=(const Suicida & suicida)
{
    return !(*this == suicida);
}

std::ostream & operator <<(std::ostream & os, const Suicida & suicida)
{
    os << suicida._nombre;
    
    return os;
}