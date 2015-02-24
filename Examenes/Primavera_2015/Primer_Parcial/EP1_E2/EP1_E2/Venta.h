//
//  Venta.h
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef ___EP__Venta__
#define ___EP__Venta__

#include <iostream>
#include "Auto.h"
#include "Comprador.h"

class Venta {
private:
    float monto;
    Comprador * cliente;
    Auto * vehiculo;
    
public:
    Venta();
    Venta(float, Comprador *, Auto *);

    float getMonto();
    void setMonto(float value);
    
    Comprador * getComprador();
    void setComprador(Comprador * value);
    
    Auto * getAuto();
    void setAuto(Auto * value);
    
    bool operator <(Venta &);
    
    friend std::ostream & operator <<(std::ostream &, Venta &);
    
};

#endif /* defined(___EP__Venta__) */
