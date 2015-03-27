//
//  Suicida.h
//  ejemplo_suicidas
//
//  Created by Vicente Cubells Nonell on 27/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __ejemplo_suicidas__Suicida__
#define __ejemplo_suicidas__Suicida__

#include <iostream>

#include <string>

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


#endif /* defined(__ejemplo_suicidas__Suicida__) */
