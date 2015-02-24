//
//  Persona.cpp
//  ordenamientoGenerico
//
//  Created by Vicente Cubells Nonell on 09/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Persona.h"


bool Persona::operator >(Persona & persona)
{
    if (apellidos > persona.apellidos) {
        
        return true;
    }
    else if (apellidos == persona.apellidos) {
    
        if (nombre < persona.nombre) {
            return true;
        }
        else {
            return false;
        }
    }
    
    return false;
}

bool Persona::operator <(Persona & persona)
{
    return edad < persona.edad;
}

std::ostream & operator << (std::ostream & os,  const Persona & persona)
{
    os << persona.apellidos << ", " << persona.nombre << "(" << persona.edad << ")" << std::endl;
    
    return os;
}