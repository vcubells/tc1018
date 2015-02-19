//
//  main.cpp
//  ordenar_contratos
//
//  Created by Vicente Cubells Nonell on 18/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <ostream>
#include "../../ordenamientoGenerico/ordenamientoGenerico/OrdenamientoGenerico.h"
#include "Contrato.h"

int main(int argc, const char * argv[])
{
    const int numeroContratos = 3;
    
    Contrato contratos[numeroContratos];
    
    contratos[0] = Contrato(1, {2010, 9, 21});
    contratos[1] = Contrato(2, {2010, 9, 21});
    contratos[2] = Contrato(3, {2012, 10, 6});
    
    /* Mostrar contratos por pantalla */
    std::cout << "--- Listado de contratos ---" << std::endl;
    std::copy(contratos, contratos+numeroContratos, std::ostream_iterator<Contrato>(std::cout, ""));
    
    std::cout << std::endl;
    
    /* Ordenar el arreglo de contratos descendentemente por la fecha */
    Ordenamiento<Contrato>::insercion(contratos, numeroContratos, Ordenamiento<Contrato>::desc);
    
    /* Mostrar contratos ordenados descendentemente por la fecha */
    std::cout << "--- Listado de contratos ordenadas descendentemente por la fecha ---" << std::endl;
    std::copy(contratos, contratos+numeroContratos, std::ostream_iterator<Contrato>(std::cout, ""));

    std::cout << std::endl;
    
    return 0;
}

