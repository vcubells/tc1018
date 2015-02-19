//
//  Contrato.h
//  ordenar_contratos
//
//  Created by Vicente Cubells Nonell on 18/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __ordenar_contratos__Contrato__
#define __ordenar_contratos__Contrato__

#include <iostream>

struct Fecha {
    int año;
    int mes;
    int dia;
    
    bool operator >(Fecha & fecha)
    {
        return ( (año > fecha.año) || (año == fecha.año && mes > fecha.mes) || (año == fecha.año && mes == fecha.mes && dia > fecha.dia)  );
    }
    
    bool operator <(Fecha & fecha)
    {
        return !( operator>(fecha) );
    }
    
    bool operator ==(Fecha & fecha)
    {
        return ( año == fecha.año && mes == fecha.mes && dia == fecha.dia );
    }
    
    bool operator !=(Fecha & fecha)
    {
        return !( operator==(fecha) );
    }
    
    friend std::ostream & operator <<(std::ostream & os, const Fecha & fecha)
    {
        os << fecha.año << "-" << fecha.mes << "-" << fecha.dia;
        
        return os;
    }
    
    
};

class Contrato {
private:
    int numero;
    struct Fecha fecha;
    
public:
    Contrato()
    {
        Contrato(0, {0,0,0});
    }
    
    Contrato(int _numero, struct Fecha _fecha): numero(_numero), fecha(_fecha) {}
    
    bool operator >(Contrato &);
    bool operator <(Contrato &);
    
    friend std::ostream & operator <<(std::ostream &, const Contrato &);
};


#endif /* defined(__ordenar_contratos__Contrato__) */
