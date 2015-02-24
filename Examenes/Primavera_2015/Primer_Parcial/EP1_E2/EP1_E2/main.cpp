//
//  main.cpp
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "Auto.h"
#include "Moto.h"
#include "Camioneta.h"
#include "Comprador.h"
#include "Venta.h"
#include "../../../../../Tema_4_Ordenamiento/ordenamientoGenerico/ordenamientoGenerico/OrdenamientoGenerico.h"

int main(int argc, const char * argv[])
{
    Auto * a2 = new Auto(1, "Toyota", 2012, 35000);
    Moto * m2 = new Moto(2, "Honda", 2013, 10000, 250);
    Camioneta * c2 = new Camioneta(3, "Toyota", 2009, 87000, "4WD");
    
    Comprador * cliente1 = new Comprador("Juan", "Perez", "1");
    Comprador * cliente2 = new Comprador("Maria", "Perez", "2");
    
    Venta venta1(125000, cliente1, m2);
    Venta venta2(225000, cliente2, a2);
    Venta venta3(400000, cliente1, c2);
    
    /* Crear arreglo de ventas */
    
    const int n_ventas = 3;
    
    Venta ventas[n_ventas];
    
    ventas[0] = venta1;
    ventas[1] = venta2;
    ventas[2] = venta3;

    
    /* Listado de ventas ordenadas por monto */
    
    std::cout << "---------------------------" << std::endl;
    std::cout << "Listado de ventas ordenadas : " << std::endl;
    std::cout << "---------------------------" << std::endl;

    Ordenamiento<Venta>::insercion(ventas, n_ventas, Ordenamiento<Venta>::desc);
    
    for (auto v : ventas){
        std::cout << v << std::endl;
    }
    
    /* Compras de un cliente */
    
    std::cout << "---------------------------" << std::endl;
    std::cout << "Compras del cliente : " << *cliente1 << std::endl;
    std::cout << "---------------------------" << std::endl;
    
    for (auto v : ventas) {
        if (v.getComprador() == cliente1) {
            std::cout << v << std::endl;
        }
    }
    
    
    delete a2;
    delete m2;
    delete c2;
    
    delete cliente1;
    delete cliente2;
    
    return 0;
}

