//
//  Comprador.cpp
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Comprador.h"

Comprador::Comprador()
{
    Comprador("Sin definir", "Sin definir", "Sin definir");
}

Comprador::Comprador(std::string n, std::string a, std::string i)
{
    nombre = n;
    apellidos = a;
    ife = i;
}

std::string Comprador::getNombre()
{
    return nombre;
}

void Comprador::setNombre(std::string value)
{
    nombre = value;
}

std::string  Comprador::getApellidos()
{
    return apellidos;
}

void Comprador::setApellidos(std::string value)
{
    apellidos = value;
}

std::string Comprador::getIfe()
{
    return ife;
}

void Comprador::setIfe(std::string value)
{
    ife = value;
}

bool Comprador::operator ==(Comprador & c)
{
    return ife == c.ife;
}


std::ostream & operator <<(std::ostream & os, Comprador & c)
{
    os << c.nombre << " : ";
    os << c.apellidos << " : ";
    os << c.ife;
    
    return os;
}
