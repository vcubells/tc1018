//
//  main.cpp
//  BinaryTree
//
//  Created by Vicente Cubells Nonell on 26/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

#include "BNode.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    BNode<int> entero(1);
    std::cout << entero << std::endl;
    
    BNode<float> flotante(3.14);
    std::cout << flotante << std::endl;
    
    BNode<char> letra('A');
    std::cout << letra << std::endl;
    
    return 0;
}
