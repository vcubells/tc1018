//
//  Auto.cpp
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Auto.h"

Auto::Auto(): Auto(0, "Sin definir", 0, 0.0)
{
}

Auto::Auto(int c, std::string ma, int mo, float k)
{
    modelo = mo;
    codigo = c;
    marca = ma;
    kilometraje = k;
}

int Auto::getCodigo()
{
    return codigo;
}

void Auto::setCodigo(int value)
{
    codigo = value;
}

std::string Auto::getMarca()
{
    return marca;
}

void Auto::setMarca(std::string value)
{
    marca = value;
}

int Auto::getModelo()
{
    return modelo;
}

void Auto::setModelo(int value)
{
    modelo = value;
}

float Auto::getKilometraje()
{
    return kilometraje;
}

void Auto::setKilometraje(float value)
{
    kilometraje = value;
}

std::ostream & operator <<(std::ostream & os, Auto & a)
{
    os << a.codigo << " : ";
    os << a.marca << " : ";
    os << a.modelo << " : ";
    os << a.kilometraje;

    return os;
}