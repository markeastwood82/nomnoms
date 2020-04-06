#include "noms/fruit/apple.h"
#include "noms/veg/asparugus.h"

#include <iostream>

int main()
{
    noms::Apple apple("red");
    std::cout << "The apple is " << apple.getColour() << std::endl;

    noms::Aspargus aspargus{};
    //std::cout << "The asparagus is " << asparagus.() << std::endl;

    return 0;
}
