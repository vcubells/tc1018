//
//  main.cpp
//  stl
//
//  Created by Vicente Cubells Nonell on 16/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> numeros;
    
    numeros.push_back(1);
    numeros.push_back(2);
    
    for (auto i : numeros) {
        cout << i;
    }
    
    cout << endl;
    
    copy(numeros.rbegin(), numeros.rend() , ostream_iterator<int>(cout));
    
    cout << endl;
    
    copy(numeros.begin(), numeros.end() , ostream_iterator<int>(cout));
    
    return 0;
}
