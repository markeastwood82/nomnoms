#include "noms/fruit/apple.h"
#include <iostream>

int main()
{
    noms::Apple apple("red");
    std::cout << "The apple is " << apple.getColour() << std::endl;
    return 0;
}
