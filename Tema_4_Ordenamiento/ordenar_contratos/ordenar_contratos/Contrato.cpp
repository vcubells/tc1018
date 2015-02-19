//
//  Contrato.cpp
//  ordenar_contratos
//
//  Created by Vicente Cubells Nonell on 18/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Contrato.h"

bool Contrato::operator >(Contrato & contrato)
{
    if (fecha > contrato.fecha)
    {
        return true;
    }
    else if (fecha == contrato.fecha && numero < contrato.numero)
    {
        return true;
    }
    
    return false;
}

bool Contrato::operator <(Contrato & contrato)
{
    return !(operator>(contrato));
}

std::ostream & operator <<(std::ostream & os, const Contrato & contrato)
{
    os << contrato.numero << " - " << contrato.fecha << std::endl;
    
    return os;
}