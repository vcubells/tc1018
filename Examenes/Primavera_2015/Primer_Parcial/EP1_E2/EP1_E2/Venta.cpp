//
//  Venta.cpp
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Venta.h"

Venta::Venta()
{
    Venta(0.0, nullptr, nullptr);
}

Venta::Venta(float m, Comprador * c, Auto * a)
{
    monto = m;
    cliente = c;
    vehiculo = a;
}

float Venta::getMonto()
{
    return monto;
}

void Venta::setMonto(float value)
{
    monto = value;
}

Comprador * Venta::getComprador()
{
    return cliente;
}

void Venta::setComprador(Comprador * value)
{
    delete cliente;
    cliente = value;
}

Auto * Venta::getAuto()
{
    return vehiculo;
}

void Venta::setAuto(Auto * value)
{
    delete vehiculo;
    vehiculo = value;
}


bool Venta::operator <(Venta & v)
{
    return monto < v.monto;
}

std::ostream & operator <<(std::ostream & os, Venta & v)
{
    os << "Datos de la venta: " << std::endl;
    os << "Auto - " << *v.vehiculo << std::endl;
    os << "Cliente - " << *v.cliente << std::endl;
    os << "Monto - $" << v.monto << std::endl;
    
    return os;
}

