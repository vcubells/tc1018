//
//  main.cpp
//  frecuencias_con_map_stl
//
//  Created by Vicente Cubells Nonell on 16/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> numeros(1000);
    
    /* Generar números aleatorios */
    generate(numeros.begin(), numeros.end(), [](){ return rand() % 100; } );
    
    /* Mostrar todos los elementos */
    cout << "--- Números generados ---" << endl;
    copy(numeros.begin(), numeros.end(), ostream_iterator<int>(cout, ", "));
    
    /* Calcular frecuencias utilizando un map */
    map<int, int> frecuencias;
    
    for (auto n : numeros) {
        ++frecuencias[n];
    }
    
    /* Mostrar las frecuencias */
    cout << endl << "--- Frecuencias ---" << endl;
    for (auto n : frecuencias) {
        cout << n.first << "\t\t" << n.second << endl;
    }

    /* Ordenar por frecuencias
     * Nota: No se puede ordenar sobre el map porque por definición este se encuentra ordenado por las claves K. Se utilizará una estructura auxiliar
     */
    multimap<int, int, greater<int>> frecuencias_ordenadas;
    
    for (auto n : frecuencias) {
        frecuencias_ordenadas.insert(pair<int, int>(n.second, n.first));
    }

    /* Mostrar ordenado descendentemente por las frecuencias */
    cout << endl << "--- Frecuencias ordenadas ---" << endl;
    for (auto n : frecuencias_ordenadas) {
        cout << n.second << "\t\t" << n.first << endl;
    }
    
    return 0;
}
