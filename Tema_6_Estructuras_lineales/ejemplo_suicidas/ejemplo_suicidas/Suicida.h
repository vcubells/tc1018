//
//  Suicida.h
//  ejemplo_suicidas
//
//  Created by Vicente Cubells Nonell on 12/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef ejemplo_suicidas_Suicida_h
#define ejemplo_suicidas_Suicida_h

#include <string>
#include <ostream>
#include <iostream>

class Suicida {
private:
    std::string _nombre;
    
public:
    
    Suicida( std::string nombre ) : _nombre(nombre) { }
    Suicida() : Suicida("Anónimo") { }
    
    std::string getNombre() { return _nombre; }
    
    bool operator ==(const Suicida & suicida);
    bool operator !=(const Suicida & suicida);
    
    friend std::ostream & operator <<(std::ostream & os, const Suicida & suicida);
    
};


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

#endif
